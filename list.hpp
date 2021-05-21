#pragma once

#include <cstdint>
#include <iterator>
#include <initializer_list>

template<typename T>
class List {
    using size_t = std::size_t;

    struct Node {
        Node* next = nullptr;
        Node* prev = nullptr;
        T* value = nullptr;

        ~Node() { delete value; }
    };


    Node head;
    size_t size_;

public:
    struct iterator : std::iterator<std::bidirectional_iterator_tag, T>
    {
        Node* node;

        iterator() = delete;
        iterator(const iterator&) = default;
        iterator(Node* node_) : node(node_) {}

        iterator& operator++() { node = node->next; return *this; }
        iterator operator++(int) { iterator copy(*this); ++(*this); return copy; }
        iterator& operator--() { node = node->prev; return *this; }
        iterator operator--(int) { iterator copy(*this); --(*this); return copy; }

        bool operator==(iterator other) { return node == other.node; }
        bool operator!=(iterator other) { return !(*this == other); }
        T& operator*() { return *(node->value); }
    };

    // Здесь ужасное дублирование кода, но без него было бы ещё хуже
    struct const_iterator : std::iterator<std::bidirectional_iterator_tag, T>
    {
        const Node* node;

        const_iterator() = delete;
        const_iterator(const const_iterator&) = default;
        const_iterator(const Node* node_) : node(node_) {}

        const_iterator& operator++() { node = node->next; return *this; }
        const_iterator operator++(int) { const_iterator copy(*this); ++(*this); return copy; }
        const_iterator& operator--() { node = node->prev; return *this; }
        const_iterator operator--(int) { const_iterator copy(*this); --(*this); return copy; }

        bool operator==(const_iterator other) { return node == other.node; }
        bool operator!=(const_iterator other) { return !(*this == other); }
        const T& operator*() { return *(node->value); }
    };

    List() : size_(0) {
        head.next = &head;
        head.prev = &head;
    }

    template<typename Iter>
    List(Iter first, const Iter last) : List() {
        // Вставляем после этого элемента
        Node *current_node = &head;

        while (first != last) {
            Node* new_node = new Node;
            new_node->prev = current_node;
            new_node->value = new T(*first);
            current_node->next = new_node;

            ++first;
            current_node = new_node;

            ++size_;
        }

        current_node->next = &head;
        head.prev = current_node;
    }

    // Использование: 
    // List<int> first_five = {1, 2, 3, 4, 5};
    List(std::initializer_list<T> init_list) : List(init_list.begin(), init_list.end()) { }

    List(const List& other) : List(other.cbegin(), other.cend()) { }
    
    ~List() { clear(); }

    iterator begin() { return iterator(head.next); }
    iterator end() { return iterator(&head); }
    const_iterator cbegin() const { return const_iterator(head.next); }
    const_iterator cend() const { return const_iterator(&head); }
            
    void push_back(const T& val) {
        Node *new_node = new Node;
        new_node->value = new T(val);
        new_node->next = &head;
        new_node->prev = head.prev;

        new_node->prev->next = new_node;
        head.prev = new_node;
        ++size_;
    }

    void push_front(const T& val) {
        Node *new_node = new Node;
        new_node->value = new T(val);
        new_node->next = head.next;
        new_node->prev = &head;

        new_node->next->prev = new_node;
        head.next = new_node;
        ++size_;
    }

    iterator insert(iterator pos, const T& val) {
        Node *new_node = new Node;
        new_node->value = new T(val);
        new_node->next = pos.node;
        new_node->prev = pos.node->prev;

        pos.node->prev->next = new_node;
        pos.node->prev = new_node;
        ++size_;
        // Итератор на элемент до pos
        return --pos;
    }

    iterator erase(iterator pos) {
        pos.node->next->prev = pos.node->prev;
        pos.node->prev->next = pos.node->next;
        auto ret = pos.node->next;

        delete pos.node;
        --size_;
        return ret;
    }

    T& at(size_t index) {
        // Инкрементирует итератор, возвращенный begin() index раз
        // Затем разыменовывает его
        return *std::next(begin(), index);
    }

    const T& at(size_t index) const {
        return *std::next(cbegin(), index);
    }

    void clear() {
        Node* last, *curr = head.next;
        while (curr != &head) {
            last = curr;
            curr = curr->next;
            delete last;
        }

        head.next = &head;
        head.prev = &head;
        size_ = 0;
    }

    size_t size() const { return size_; }
    bool empty() const { return !size(); }
};

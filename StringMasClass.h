#pragma once
#pragma once
#include <string>
#include <iostream>
using namespace std;

class StringMasClass
{
private:
	struct node
	{
		string data;
		node* next;
	};
	node* head;
	node* getNextNode;
	int count;
public:
	StringMasClass() {
		head = NULL;
		getNextNode = NULL;
		count = 0;
	}

	bool Erase() {
		head = NULL;
		return true;
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}

	bool Add(string st) {
		//std::cout << st << std::endl;
		//string valueString(st.length(), ' ');
		//valueString = st;
		if (!head)
		{
			head = new node;
			head->data = st;
			head->next = NULL;
			count++;
			return true;
		}
		else
		{
			node* tmp = new node;
			tmp->data = st;
			tmp->next = head;
			head = tmp;
			count++;
			return true;
		}
		return false;
	}

	bool getInit() {
		return getNextNode = head;
	}
	string getNext() {
		string tmpString = "";
		if (getNextNode) {
			tmpString = getNextNode->data;
			getNextNode = getNextNode->next;
		}
		return tmpString;
	}
	void dislay() {
		node* curNode = head;
		while (curNode) {
			std::cout << curNode->data << std::endl;
			curNode = curNode->next;
		}
	}

};



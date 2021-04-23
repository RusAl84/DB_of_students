#pragma once
#include <string>
using namespace std;

class StringMasClass
{
private:
	struct node
	{
		string data;
		node* next;
		node* prev;
	};
	static node* head;
	static node* getNextNode;
	static int count;
public:
	bool Erase() {
		return true;
	}

	bool Add(string st) {

		if (!head)
		{
			head = new node;
			head->data = st;
			head->next = NULL;
			head->prev = NULL;
			count++;
		}
		else
		{
			node* tmp = new node;
			tmp->data = st;
			tmp->next = head;
			tmp->prev = NULL;
			head = tmp;
			head->next->next->prev = head->next;
			count++;
		}
	}

	void getInit() {
		getNextNode = head;
	}
	string getNext() {
		string tmpString = "";
		if (not getNextNode){
			tmpString = getNextNode->data;
			getNextNode = getNextNode->next;
		}
		return tmpString;
	}
};


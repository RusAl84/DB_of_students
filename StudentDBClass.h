#pragma once
#include "StudentClass.h"
#include <iostream>
using namespace std;
class StudentDBClass
{
	struct node
	{
		StudentClass data;
		node* next;
		node* prev;
	};

	static node* head;
	static int count;
public:
	bool Add(StudentClass st) {

		if (!head)
		{
			head = new node;
			head->data = st;
			head->next = NULL;
			head->prev = NULL;

		}
		else
		{
			node* tmp = new node;
			tmp->data = st;
			tmp->next = head;
			tmp->prev = NULL;
			head = tmp;
			head->next->next->prev = head->next;
		}
	}

	void print_SurName() {
		node* curr = head;
		while (curr) {
			cout << curr->data.surName << endl;
			curr = curr->next;
		}
	}
	
};


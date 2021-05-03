#pragma once
#include "StudentClass.h"
#include <iostream>
#include "FileManagerClass.h"
using namespace std;
struct Node
{
	string surName;
	string name;
	string middleName;
	string faculty;
	string department;
	string group;
	string recordÑardNumber;
	bool sex; // true - ìàëü÷èê
			  // false - äåâî÷êà
	int startYear;
	string birthDateString;
	ExamsRecords data[9][10];
	Node* next;
};

class StudentDBClass : public FileManagerClass
{
private:
	static Node* head;
	static Node* getNextNode;
	static int count;
public:
	bool Erase() {
		head = NULL;
		return true;
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}

	void LoadDataFromFile() {

	}

	void setData(Node* tNode, StudentClass* st) {
		tNode->surName = "st->surName";
		tNode->name = "st->name";
		tNode->middleName = "st->middleName";
		//string st.faculty; //ïî àíàëîãèè
		//string st.department;
		//string st.group;
		//string st.recordÑardNumber;
		//bool st.sex; 
		//int st.startYear;
		//string birthDateString;
		//ExamsRecords data[9][10];

	}
	bool Add(StudentClass* st) {
		if (!head)
		{
			
			head = new Node();
			//head->surName = st->surName;
			setData(head, st);
			//head->data = st;
			head->next = NULL;
			count++;
			return true;
		}
		else
		{
			Node* tmp = new Node();
			setData(tmp, st);
			//tmp->data = st;
			tmp->next = head;
			head = tmp;
			count++;
			return true;
		}
		return false;
	}
	//bool getInit() {
	//	return getNextNode = head;
	//}
	//Node getNext() {
	//	Node tmpSt;
	//	if (getNextNode) {
	//		tmpSt = getNextNode->data;
	//		getNextNode = getNextNode->next;
	//	}
	//	return tmpSt;
	//}

	void print_AllSurName() {
		Node* curr = head;
		while (curr) {
			cout << curr->surName << endl;
			curr = curr->next;
		}
	}
	
};



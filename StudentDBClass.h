#pragma once
#include "StudentClass.h"
#include <iostream>
#include "FileManagerClass.h"
using namespace std;
struct StudentNode
{
	string surName;
	string name;
	string middleName;
	string faculty;
	string department;
	string group;
	string recordСardNumber;
	string birthDateString;
	bool sex; // true - мальчик
			  // false - девочка
	int startYear;
	//ExamsRecords data[9][10];
	StudentNode* next;
};

class StudentDBClass : public FileManagerClass
{
private:
	StudentNode* head;
	StudentNode* getNextNode;
	int count;
public:
	StudentDBClass() {
		head = NULL;
		getNextNode = NULL;
		count = 0;
	}
	bool Erase() {
		head = NULL;
		return true;
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	void loadDataFromFile() {
		string line;
		int count = 0;
		std::ifstream inFile(FileName); // окрываем файл для чтения
		if (inFile.is_open())
		{
			bool isRecord = false;
			StudentNode* st = new StudentNode();
			while (getline(inFile, line))
			{
				if (strcmp(startRecordString.c_str(), line.c_str()) == 0) {
					isRecord = true;
					continue;
				}
				if (strcmp(endRecordString.c_str(), line.c_str()) == 0) {
					isRecord = false;
					Add(st);
					/// add

					continue;
				}
				if (isRecord) {
					string valueName = getName(line);
					if (strcmp(getType(line).c_str(), "str") == 0)
					{
						string value = getValueStr(line);
						//cout << value << endl;
						//string faculty;
						//string department;
						//string group;
						//string recordСardNumber;
						//string birthDateString;

						if (strcmp("surName", valueName.c_str()) == 0)
							st->surName = value;
						//if (strcmp("name", valueName.c_str()) == 0)
						//	st.name = value;
						//if (strcmp("middleName", valueName.c_str()) == 0)
						//	st.middleName = value;
						//!!!!!!!!!!!!!!!!!!!!!!!!!!!!! надо бы продолжить 
					}
					else // Тогда явно int но надо проверить
					{
						int value = getValueInt(line);
						//if (strcmp("sex", valueName.c_str()) == 0)
						//	if (value == 0)
						//		st.sex = false;
						//	else
						//		st.sex = true;
						//if (strcmp("startYear", valueName.c_str()) == 0)
						//	st.startYear = value;
					}
				}
			}
			inFile.close();     // закрываем файл
		}
	}

	void setData(StudentNode* tNode, StudentNode* st) {
		tNode->surName = st->surName;
		tNode->name = st->name;
		tNode->middleName = st->middleName;
		//string st.faculty; //по аналогии  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!111
		//string st.department;
		//string st.group;
		//string st.recordСardNumber;
		//bool st.sex; 
		//int st.startYear;
		//string birthDateString;
		//ExamsRecords data[9][10];

	}
	bool Add(StudentNode *st) {
		if (!head)
		{
			head = new StudentNode();
			//head->surName = st->surName;
			setData(head, st);
			//head->data = st;
			head->next = NULL;
			count++;
			return true;
		}
		else
		{
			StudentNode* tmp = new StudentNode();
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

	void printAllSurName() {
		StudentNode* curr = NULL;
		curr = head;
		while (curr) {
			cout << curr->surName << endl;
			curr = curr->next;
		}
	}
	
};



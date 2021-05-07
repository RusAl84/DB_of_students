#pragma once
#include "StudentClass.h"
#include <iostream>
#include "FileManagerClass.h"
using namespace std;
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
	~StudentDBClass() {
		Erase();
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
			int studentId = 0;
			while (getline(inFile, line))
			{
				if (strcmp(startRecordString.c_str(), line.c_str()) == 0) {
					isRecord = true;
					continue;
				}
				if (strcmp(endRecordString.c_str(), line.c_str()) == 0) {
					isRecord = false;
					studentId++;
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
						if (strcmp("surName", valueName.c_str()) == 0)
							st->surName = value;
						if (strcmp("name", valueName.c_str()) == 0)
							st->name = value;
						if (strcmp("middleName", valueName.c_str()) == 0)
						    st->middleName = value;
						if (strcmp("faculty", valueName.c_str()) == 0)
							st->faculty = value;
						if (strcmp("department", valueName.c_str()) == 0)
							st->department = value;						
						if (strcmp("group", valueName.c_str()) == 0)
							st->group = value;						
						if (strcmp("recordСardNumber", valueName.c_str()) == 0)
							st->recordСardNumber = value;
						if (strcmp("birthDateString", valueName.c_str()) == 0)
							st->birthDateString = value;
						//!!!! ExamsRecords
						//!!!!!!!!!!!!!!!!!!!!!!!!!!!!! надо бы продолжить 
					}
					else // Тогда явно int но надо проверить
					{
						int value = getValueInt(line);
						if (strcmp("id", valueName.c_str()) == 0)
							st->id = studentId;  // сейчас здесь порядковый номер записи в файле
						//должно быть value хорошо бы, но ладно;) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
						if (strcmp("startYear", valueName.c_str()) == 0)
							st->id = value;
						if (strcmp("sex", valueName.c_str()) == 0)
							if (value == 0)
								st->sex = false;
							else
								st->sex = true;
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
		tNode->faculty = st->faculty;
		tNode->department = st->department;
		tNode->group = st->group;
		tNode->recordСardNumber = st->recordСardNumber;
		tNode->sex = st->sex;
		tNode->startYear = st->startYear;
		tNode->birthDateString = st->birthDateString;
		// //по аналогии  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!111
		//ExamsRecords data[9][10];


		tNode->isNULL = false;

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
	bool getInit() {
		return getNextNode = head;
	}

	StudentNode getNext() {
		StudentNode tmpSt;
		tmpSt.isNULL = true;
		if (getNextNode) {
			//tmpSt = getNextNode->data;
			setData(&tmpSt, getNextNode);
			getNextNode = getNextNode->next;
		}
		return tmpSt;
	}

	void printAllSurName() {
		StudentNode* curr = NULL;
		curr = head;
		while (curr) {
			cout << curr->surName << endl;
			curr = curr->next;
		}
	}
	
};



#pragma once
#include <string>
#include "BirthDateClass.h"
#include "ExamsResultsClass.h"
#include "StringBuilderClass.h"
//#include "StringMasClass.h"
#include "ClassMenu.h"
#include "ClassEdit.h"
#include "list.hpp"
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

	ExamsRecords examsRecordsData[9][10];  
	StudentNode* next;
	int id;
	double avrMarks;
	double Marks45;
	double countMarks5;
	double countMarks4;
	double countMarks3;

};

class StudentClass
{
private:
	StudentNode *sn;
	//StringMasClass stringMas;
	
public:
	List <string> stringList;
	 StudentClass() {
		 sn = new StudentNode();
		 addRusakov();
	}
	 StudentNode* getStudentNode() {
		 return sn;
	 }

	void addRusakov() {
		sn->id = 0;
		sn->surName = "Русаков";
		sn->name = "Алексей";
		sn->middleName = "Михайлович";
		sn->faculty = "10.05.04 Информационно-аналитические системы безопасности";
		sn->department = "Институт комплексной безопасности и специального приборостроения";
		sn->group = "БИСО-01-21";
		sn->recordСardNumber = "20Б0857";
		sn->sex = true;
		sn->startYear = 2021;
		sn->birthDateString = "27.12.1984";
		ExamsResultsClass* er = new ExamsResultsClass();
		er->add(0, "Яыки программирования 1", 5);
		er->add(0, "Математика 1", 5);
		er->add(0, "Физкультура 1", true);
		er->add(1, "Яыки программирования 2", 5);
		er->add(1, "Математика 2", 5);
		er->add(1, "Физкультура 2", true);
		setExamsResultsData(er,sn);
	}
	void setExamsResultsData(ExamsResultsClass* er, StudentNode* sn) {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++) {
				sn->examsRecordsData[i][j].isEmpty = er->data[i][j].isEmpty;
				sn->examsRecordsData[i][j].mark = er->data[i][j].mark;
				sn->examsRecordsData[i][j].name = er->data[i][j].name;
			}
	}
	void UpdateMasString(StudentNode* sn) {
		stringList.clear();
		//stringMas.Erase();
		StringBuilderClass sb = StringBuilderClass();
		stringList.insert(stringList.begin(), sb.setParam("surName", sn->surName));
		stringList.insert(stringList.begin(), sb.setParam("name", sn->name));
		stringList.insert(stringList.begin(), sb.setParam("middleName", sn->middleName));
		stringList.insert(stringList.begin(), sb.setParam("faculty", sn->faculty));
		stringList.insert(stringList.begin(), sb.setParam("department", sn->department));
		stringList.insert(stringList.begin(), sb.setParam("group", sn->group));
		stringList.insert(stringList.begin(), sb.setParam("recordСardNumber", sn->recordСardNumber));
		int intSex = 1;
		if (sn->sex)
			intSex = 1;
		else
			intSex = 0;
		stringList.insert(stringList.begin(), sb.setParam("sex", intSex));
		stringList.insert(stringList.begin(), sb.setParam("startYear", sn->startYear));
		stringList.insert(stringList.begin(), sb.setParam("birthDateString", sn->birthDateString)); //27.12.1984

		int sem = 0;
		int num = 0;
		for (int sem=0;sem<9;sem++)
			for (int num=0;num<10;num++)
				if (not sn->examsRecordsData[sem][num].isEmpty ){
					//examsResults_sem_num_n - название экзамена или зачета
					stringList.insert(stringList.begin(), sb.setParam("examsResults_" + std::to_string(sem) + "_" + std::to_string(num) + "_n", sn->examsRecordsData[sem][num].name));
					//examsResults_sem_num_m - оценка
					stringList.insert(stringList.begin(), sb.setParam("examsResults_" + std::to_string(sem) + "_" + std::to_string(num) + "_m", std::to_string(sn->examsRecordsData[sem][num].mark)));
				}
		//stringMas.dislay();
	}
	//string getStringRecord() {
	//	return stringMas.getNext();
	//}
	//bool getInitStringRecord() {
	//	return stringMas.getInit();
	//}
	bool editSex() {
		ClassMenu* sexMenu = new ClassMenu();
		int resultSelectedItem = 1;
		const int exitItem = 3;
		sexMenu->addTitleItem("Выберите пол: ");
		sexMenu->addItem("Мальчик:(");
		sexMenu->addItem("Девочка:(");
		while (resultSelectedItem != exitItem) {
			sexMenu->run();
			resultSelectedItem = sexMenu->getSelectedItem();
			switch (resultSelectedItem) {
			case 0:
				return true;
				resultSelectedItem = exitItem;
				break;
			case 1:
				return false;
				resultSelectedItem = exitItem;
				break;
			default:
				break;
			}
		}
	}
	void editStudent(StudentNode *sn)
	{
		ClassMenu* studDataMenu = new ClassMenu();
		int resultStudDataMenu = 1;
		const int exitStudDataMenu = 0;
		ClassEdit* ce = new  ClassEdit();
		studDataMenu->addItem("Выход");   //0
		studDataMenu->addItem("Добавить/изменить фамилию"); //1
		studDataMenu->addItem("Добавить/изменить имя");   //2
		studDataMenu->addItem("Добавить/изменить отчество");   //3
		studDataMenu->addItem("Добавить/изменить институт");   //4
		studDataMenu->addItem("Добавить/изменить кафедру");   //5
		studDataMenu->addItem("Добавить/изменить группу");   //6
		studDataMenu->addItem("Добавить/изменить номер зачетной книжки");   //7
		studDataMenu->addItem("Добавить/изменить пол");   //
		studDataMenu->addItem("Добавить/изменить год поступления в ВУЗ");   //8
		studDataMenu->addItem("Добавить/изменить дату рождения");   //9
		studDataMenu->addItem("Добавить/изменить оценки");   //10
		int day, month, year;
		while (resultStudDataMenu != exitStudDataMenu) {
			studDataMenu->eraseTitle();
			studDataMenu->addTitleItem("Изменение/добавление данных о студенте:");
			studDataMenu->addTitleItem("Фамилия: " + sn->surName + " Имя: " + sn->name + " Отчество: " + sn->middleName);
			string sexString = "";
			if (sn->sex) { sexString = "мальчик:("; }
			else { sexString = "девочка;)"; }
			studDataMenu->addTitleItem("пол: " + sexString + " дата рождения: " + sn->birthDateString + " год поступления:" + std::to_string(sn->startYear));
			studDataMenu->addTitleItem("Номер зачетной книжки: " + sn->recordСardNumber + " Группа: " + sn->group);
			studDataMenu->addTitleItem("Институт: " + sn->faculty);
			studDataMenu->addTitleItem("Кафедра: " + sn->department);
			studDataMenu->run();
			resultStudDataMenu = studDataMenu->getSelectedItem();
			string tmpString = "";
			int year = 0;
			int startYear = 0;
			StringBuilderClass* sb = new StringBuilderClass();
			ExamsRecords oldExamsRecordsData[9][10];
			switch (resultStudDataMenu) {
			case 0:
				resultStudDataMenu = exitStudDataMenu;
				break;
			case 1:
				ce->setLabel("Введите фамилию. ");
				sn->surName = ce->setDataString(sn->surName);
				break;
			case 2:
				ce->setLabel("Введите имя. ");
				sn->name = ce->setDataString(sn->name);
				break;
			case 3:
				ce->setLabel("Введите отчество. ");
				sn->middleName = ce->setDataString(sn->middleName);
				break;
			case 4:
				ce->setLabel("Введите название института. ");
				sn->faculty = ce->setDataString(sn->faculty);
				break;
			case 5:
				ce->setLabel("Введите название кафедры. ");
				sn->department = ce->setDataString(sn->department);
				break;
			case 6:
				ce->setLabel("Введите группу. ");
				sn->group = ce->setDataString(sn->group);
				break;
			case 7:
				ce->setLabel("Введите номер зачетной книжки. ");
				sn->recordСardNumber = ce->setDataString(sn->recordСardNumber);
				break;
			case 8:
				ce->setLabel("Введите пол. ");
				sn->sex = editSex();        ////
				break;
			case 9:
				ce->setLabel("Введите год поступления в ВУЗ. ");
				startYear = ce->setDataInt(1900, 2021);
				tmpString = sb->split(sn->birthDateString.c_str(), '.', 3);
				year = atoi(tmpString.c_str());
				if  (year==0)
					sn->startYear = startYear;
				else
				{
					if (startYear - year >= 15) {
						sn->startYear = startYear;
					}
					else
					{
						cout << "Ошибка год поступления в институт должен быть на 15 лет больше чем год рождения";
						_getch();
					}
				} 

				break;
			case 10:
				ce->setLabel("Введите день рождения. ");
				day = ce->setDataInt(1, 31);
				ce->setLabel("Введите месяц рождения. ");
				month = ce->setDataInt(1, 12);
				ce->setLabel("Введите год рождения. ");
				year = ce->setDataInt(1900, 2005);
				if (sn->startYear == 0)
					sn->birthDateString = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
				else
				{
					if (sn->startYear - year >= 15) {
						sn->birthDateString = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
					}
					else
					{
						cout << "Ошибка год поступления в институт должен быть на 15 лет больше чем год рождения";
						_getch();
					}
				}
				break;
			case 11:
				ce->setLabel("Просмотреть/ изменить оценки.");
				//sn = getStudentNode();
				for (int i = 0; i < 9; i++)
					for (int j = 0; j < 10; j++) {
						oldExamsRecordsData[i][j].name = sn->examsRecordsData[i][j].name;
						oldExamsRecordsData[i][j].isEmpty = sn->examsRecordsData[i][j].isEmpty;
						oldExamsRecordsData[i][j].mark = sn->examsRecordsData[i][j].mark;
					}
						
				editExamsResults(sn); // "Ошибка есть одинаковые названия предметов"
				if (isSameNameExamsResults(sn)){ 
					cout << "Ошибка есть одинаковые названия предметов";
					for (int i = 0; i < 9; i++)
						for (int j = 0; j < 10; j++) {
							sn->examsRecordsData[i][j].name = oldExamsRecordsData[i][j].name;
							sn->examsRecordsData[i][j].isEmpty = oldExamsRecordsData[i][j].isEmpty;
							sn->examsRecordsData[i][j].mark = oldExamsRecordsData[i][j].mark;
						}
					_getch();
				}
				break;
			default:
				break;
			}
			delete sb;
		}
	}
	void editExamsResults(StudentNode* sn) {
		ClassMenu* sesMenu = new ClassMenu();
		int result = 1;
		const int exit = 0;
		ClassMenu* msMenu = new ClassMenu();
		int resultS = 1;
		const int exitS = 0;
		ClassEdit* ce = new  ClassEdit();
		ExamsResultsClass* erc = new ExamsResultsClass();
		sesMenu->addItem("Выход");   //0
		for(int i=1;i<10;i++){
		sesMenu->addItem("Сессия "+std::to_string(i));
		}
		while (result != exit) {
			sesMenu->eraseTitle();
			sesMenu->addTitleItem("Просмотр/изменение/добавление данных о оценках за все сессии");
			sesMenu->addTitleItem("Выберите сессию для просмотра и редактирования информации об оценках");
			sesMenu->run();
			result = sesMenu->getSelectedItem();
			if (result == exit) {
				result = exit;
				break;
			}
			int curSess = result;
			if ((curSess >= 1) and (curSess <= 10))
			{
				//рисуем меню и правим оценки про сессию
				msMenu->eraseAll();
				msMenu->addTitleItem("Просмотр/изменение/добавление данных о оценках");
				msMenu->addTitleItem("Данные сессии №" + std::to_string(curSess));
				resultS = 1;
				while (resultS != exitS) {
					msMenu->eraseItem();
					msMenu->addItem("Выход");
					msMenu->addItem("Добавить запись");
					msMenu->addItem("Удалить запись");
					for (int i = 0; i < 10; i++)
						if (not sn->examsRecordsData[curSess - 1][i].isEmpty)
						{
							string markString = "";
							int markInt = sn->examsRecordsData[curSess - 1][i].mark;
							if (markInt == 0) markString = "не зачтено";
							if (markInt == 1) markString = "зачтено";
							if ((markInt >= 2) and (markInt <= 5)) {
								markString = std::to_string(markInt);
							}
							msMenu->addItem("Предмет: " + sn->examsRecordsData[curSess - 1][i].name + " Оценка: " + markString);
						}
					msMenu->run();
					resultS = msMenu->getSelectedItem();
					if (resultS == 0)
						resultS == exitS;
					if (resultS == 1) {
						int itemNum = msMenu->getItemsCount() - 3;
						if (itemNum > 9) {
							system("cls");
							cout << "Ошибка в сессию бывает только 10 дисциплин для зачетов или экзаменов";
							_getch();  //!!!!!!!!!!!!!!!????????
							_getch();
						}
						else {
							addExamsResults(sn, curSess, itemNum);
						}	
					}
					if (resultS == 2) {
						//Удалить запись
						delExamsResults(sn, curSess);
					}
					if (resultS > 2) {
						addExamsResults(sn, curSess, resultS - 3);
					}
				}
			}
			result = curSess;
		}
	}
	void addExamsResults(StudentNode* sn, int curSess, int curItem) {
		ClassEdit* ce = new  ClassEdit();
		ce->setLabel("Введите название предмета. ");
		sn->examsRecordsData[curSess - 1][curItem].name=ce->setDataString(sn->examsRecordsData[curSess - 1][curItem].name);
		int resultS = 1;
		const int exitS = 0;
		ClassMenu* msMenu = new ClassMenu();
		msMenu->addTitleItem("Выберите оценку");
		msMenu->addItem( "не зачтено"); //0
		msMenu->addItem("зачтено"); //1
		msMenu->addItem("2"); //2	
		msMenu->addItem("3"); //3		
		msMenu->addItem("4"); //4		
		msMenu->addItem("5"); //5
		resultS = 1;
		while (resultS != exitS) {
			msMenu->run();
			resultS = msMenu->getSelectedItem();
			// 0 - не зачет  
			// 1 - зачет  
			// 2,3,4,5 - оценки
			sn->examsRecordsData[curSess - 1][curItem].mark = resultS;
			resultS = exitS;
		}
		sn->examsRecordsData[curSess - 1][curItem].isEmpty = false;
	}	
	void delExamsResults(StudentNode* sn, int curSess) {
		ClassEdit* ce = new  ClassEdit();
		int resultS = 1;
		const int exitS = 0;
		ClassMenu* msMenu = new ClassMenu();
		msMenu->addTitleItem("Выберите запись для удаления");
		resultS = 1;
		while (resultS != exitS) {
			msMenu->eraseItem();
			msMenu->addItem("Выход");
			for (int i = 0; i < 10; i++)
				if (not sn->examsRecordsData[curSess - 1][i].isEmpty)
				{
					string markString = "";
					int markInt = sn->examsRecordsData[curSess - 1][i].mark;
					if (markInt == 0) markString = "не зачтено";
					if (markInt == 1) markString = "зачтено";
					if ((markInt >= 2) and (markInt <= 5)) {
						markString = std::to_string(markInt);
					}
					msMenu->addItem("Предмет: " + sn->examsRecordsData[curSess - 1][i].name + " Оценка: " + markString);
				}
			msMenu->run();
			resultS = msMenu->getSelectedItem();
			if (resultS == exitS)
				resultS == exitS;
			else
			{
				sn->examsRecordsData[curSess - 1][resultS-1].isEmpty = true;
				//Дефрагментация массива
				ExamsResultsClass* er = new ExamsResultsClass();
				for (int i = 0; i < 10; i++)
					if (not sn->examsRecordsData[curSess - 1][i].isEmpty)
						er->add(0, sn->examsRecordsData[curSess - 1][i].name, sn->examsRecordsData[curSess - 1][i].mark);
						//er->add(0, "Яыки программирования 1", 5);
				for (int i = 0; i < 10; i++)
					sn->examsRecordsData[curSess - 1][i].isEmpty = true;
				for (int i = 0; i < 10; i++)
					if (not er->data[0][i].isEmpty){
						sn->examsRecordsData[curSess - 1][i].isEmpty = false;
						sn->examsRecordsData[curSess - 1][i].name = er->data[0][i].name;
						sn->examsRecordsData[curSess - 1][i].mark = er->data[0][i].mark;
					}
			}
		}
	}
	bool isSameNameExamsResults(StudentNode* sn){
		for(int curSess = 0; curSess < 9; curSess++) {
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					if (sn->examsRecordsData[curSess][i].isEmpty == false and sn->examsRecordsData[curSess][j].isEmpty == false and i != j)
						if (strcmp(sn->examsRecordsData[curSess][i].name.c_str(), sn->examsRecordsData[curSess][j].name.c_str()) == 0)
							return true;
		}
		return false;
	}
	double getAvrMarks(StudentNode* sn) {
		double sum = 0;
		double count = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++)
				if (sn->examsRecordsData[i][j].isEmpty == false and sn->examsRecordsData[i][j].mark>1) {
					sum = sum + sn->examsRecordsData[i][j].mark;
					count++;
				}
		int avr = 0;
		if (count > 0)
			avr=sum / count;
		return avr;
	}

	double getAvrMarks(StudentNode* sn,  List <int> rangeSem) {
		double sum = 0;
		double count = 0;
		for (auto i:rangeSem)
			for (int j = 0; j < 10; j++)
				if (sn->examsRecordsData[i -1][j].isEmpty == false and sn->examsRecordsData[i-1][j].mark > 1) {
					sum = sum + sn->examsRecordsData[i-1][j].mark;
					count++;
				}
		int avr = 0;
		if (count > 0)
			avr = sum / count;
		return avr;
	}

	double getMarks45(StudentNode* sn) {
		double sum = 0;
		double count = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++)
				if (sn->examsRecordsData[i][j].isEmpty == false and sn->examsRecordsData[i][j].mark > 1) {
					count++;
					if (sn->examsRecordsData[i][j].mark > 3)
						sum ++;
				}
		double proc = 0;
		if (count > 0)
			proc = sum / count;
		return proc;
	}

	int getCountMarks5(StudentNode* sn, List <int> rangeSem) {
		int count = 0;
		for (auto i: rangeSem)
			for (int j = 0; j < 10; j++)
				if (sn->examsRecordsData[i][j].isEmpty == false and sn->examsRecordsData[i][j].mark > 4) {
					count++;
				}
		return count;
	}
	StudentNode* getCountMarks543(StudentNode* sn) {
		int count = 0;
		for (int i=0;i<9;i++)
			for (int j = 0; j < 10; j++)
				if (sn->examsRecordsData[i][j].isEmpty == false and sn->examsRecordsData[i][j].mark > 1) {
					if (sn->examsRecordsData[i][j].mark == 5)
						sn->countMarks5++;					
					if (sn->examsRecordsData[i][j].mark == 4)
						sn->countMarks4++;
					if (sn->examsRecordsData[i][j].mark == 3)
						sn->countMarks3++;
					count++;
				}
		if (count > 0) {
			sn->countMarks5 = sn->countMarks5 / count;
			sn->countMarks4 = sn->countMarks4 / count;
			sn->countMarks3 = sn->countMarks3 / count;
		}
		else {
			sn->countMarks5 = 0;
			sn->countMarks4 = 0;
			sn->countMarks3 = 0;
		}
		return sn;
	}

	List <string> getStringMas() {
		return stringList;
	}
};

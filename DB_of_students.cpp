﻿#include <iostream>
#include "StringBuilderClass.h"
#include "FileManagerClass.h"
#include "ClassMenu.h"
#include "StudentDBClass.h"
#include "StudentClass.h"
#include "ClassEdit.h"
#include "list.hpp"
//#include <algorithm>
using namespace std;

void var57(StudentDBClass* sdb) {
    ClassMenu* varMenu = new ClassMenu();
    int resultSelectedItem = 1;
    const int exitItem = 0;
    varMenu->addTitleItem("Выберите выборку: ");
    for (auto item : sdb->DataBase) {
        string tmpString = "";
        tmpString = item.surName + " " + item.name + " " + item.middleName +  " " + std::to_string(item.countMarks5) + " " + std::to_string(item.countMarks4) + " " + std::to_string(item.countMarks3) + " " + item.birthDateString;
        varMenu->addTitleItem(tmpString);
    }
    varMenu->addItem("Выход"); //0
    varMenu->addItem("а) 3;"); //1
    varMenu->addItem("б) 3 и 4;"); //2
    varMenu->addItem("в) 5;"); //3
    varMenu->addItem("г) 3 и 5;"); //4
    varMenu->addItem("д) 4 и 5."); //5
    StudentDBClass* sdb1 = new StudentDBClass();
    while (resultSelectedItem != exitItem) {
        varMenu->run();
        resultSelectedItem = varMenu->getSelectedItem();
        if (resultSelectedItem == 1) {
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase) {
                if (item.countMarks3 > 0.25) {
                    sdb1->DataBase.push_front(item);
                }
            }
            sdb1->printAllSurName_Name_MName_bYaear_Marks543();
            _getch();
        }
        if (resultSelectedItem == 2) {
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase) {
                if ((item.countMarks3 > 0.25) and (item.countMarks4 > 0.25)){
                    sdb1->DataBase.push_front(item);
                }
            }
            sdb1->printAllSurName_Name_MName_bYaear_Marks543();
            _getch();
        }
        if (resultSelectedItem == 3) {
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase) {
                if (item.countMarks5 > 0.25) {
                    sdb1->DataBase.push_front(item);
                }
            }
            sdb1->printAllSurName_Name_MName_bYaear_Marks543();
            _getch();
        }
        if (resultSelectedItem == 4) {
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase) {
                if ((item.countMarks3 > 0.25) and (item.countMarks5 > 0.25)) {
                    sdb1->DataBase.push_front(item);
                }
            }
            sdb1->printAllSurName_Name_MName_bYaear_Marks543();
            _getch();
        }
        if (resultSelectedItem == 5) {
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase) {
                if ((item.countMarks4 > 0.25) and (item.countMarks5 > 0.25)) {
                    sdb1->DataBase.push_front(item);
                }
            }
            sdb1->printAllSurName_Name_MName_bYaear_Marks543();
            _getch();
        }
    }
}


List<string>::iterator mMin(List <string> *_lst) {
    List<string>::iterator pos = _lst->begin();
    List<string>::iterator mMinPos = _lst->begin();
    string tmpString = *pos;
    while (pos != _lst->end()){
        if (*pos> tmpString)
            mMinPos = pos;
        ++pos;
    }
    return mMinPos;
   // return std::max_element(_lst->begin(), _lst->end());// #include <algorithm>
   
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    std::cout << "Курсовая работа запущена...\n";
    StudentDBClass* sdb = new StudentDBClass();    
    StudentDBClass* sdb1 = new StudentDBClass();
    StudentDBClass* sdb2 = new StudentDBClass();
    StudentDBClass* sdb3 = new StudentDBClass();
    sdb->FileName = "DB.txt";
    sdb->loadDataFromFile();

    bool debug = false;
    if (debug) {
        //Сортировка строк
        List <string> lst = { "Яна" , "Алина Рогова", "Ксюша","Данила", "Алексей" ,"Армен" };
        //Просмотреть список
        for (auto item : lst) {
            cout << item << endl;
        }
        List <string> sortedLst;
        sortedLst.clear();
        //cout << *mMin(&lst);
        while (!lst.empty()) {
            sortedLst.push_front(*mMin(&lst));
            lst.erase(mMin(&lst));
        }
        //Просмотреть отсортированный список
        cout << endl << "------------" << endl;
        for (auto item : sortedLst) {
            cout << item<<endl;
        }
    }
    else {

    
    //cout << sdb->GetRecordCount() << endl;
    ClassMenu* mainMenu = new ClassMenu();
    mainMenu->addTitleItem("Главное меню");
    mainMenu->addItem("Просмотреть список студетов (удалить или изменить данные)"); //0
    mainMenu->addItem("Добавить данные о студенте в БД"); //1
    mainMenu->addItem("Сохранить БД студентов в файл"); //2
    mainMenu->addItem("Выполнить вариант 77"); //3
    mainMenu->addItem("Выполнить вариант 71"); //4
    mainMenu->addItem("Выполнить вариант 31"); //5
    mainMenu->addItem("Выполнить вариант 27"); //6
    mainMenu->addItem("Выполнить вариант 57"); //7
    mainMenu->addItem("Выполнить вариант 43"); //8
    mainMenu->addItem("Выход"); //9
    int resultSelectedItem = 0;
    int exitInt = 9;
    ClassMenu* studentsMenu = new ClassMenu();
    studentsMenu->addTitleItem("Список студентов");
    int resultStudentSelectedItem = 1;
    const int exitIntStudentMenu = 0;
    StudentNode* sn;
    StudentClass* st = new StudentClass();
    ClassMenu* delStudentsMenu = new ClassMenu();
    int curCount;
    ClassEdit* ce = new  ClassEdit();
    int startYear = 0;
    int endYear = 0;
    int year = 0;
    StringBuilderClass* sb = new StringBuilderClass();
    List<StudentNode>::iterator pos();
    List <StudentNode> printLst;
    string firstPartString;
    while (resultSelectedItem != exitInt) {
        mainMenu->run();
        resultSelectedItem = mainMenu->getSelectedItem();
        switch (resultSelectedItem) {
        case 0:
            resultStudentSelectedItem = 1;
            while (resultStudentSelectedItem != exitIntStudentMenu) {
                studentsMenu->eraseItem();
                studentsMenu->addItem("Выход");
                studentsMenu->addItem("Удалить данные о студенте");
                /*sn = sdb->getInit();*/
                for(int i=0;i<sdb->DataBase.size();i++)
                { // добавить пункты меню ФИО студентов
                    sn = &sdb->DataBase.at(i);
                    string tmpString = sn->surName + " " + sn->name + " " + sn->middleName + " " + sn->group;
                    studentsMenu->addItem(tmpString); //добавить в меню студентов
                    //sn = sn->next;
                }
                studentsMenu->run();
                resultStudentSelectedItem = studentsMenu->getSelectedItem();
                if (resultStudentSelectedItem == exitIntStudentMenu) {
                    break;
                }
                if (resultStudentSelectedItem == 1) //удаление данных о студенте
                {
                    delStudentsMenu->eraseAll();
                    delStudentsMenu->addTitleItem("Выберите студента для удаления данных");
                    delStudentsMenu->addItem("Выход");
                    int resultDel = 1;
                    const int exitDel = 0;
                    for(int i=0; i<sdb->DataBase.size();i++)
                    { // добавить пункты меню ФИО студентов
                        sn = &sdb->DataBase.at(i);
                        string tmpString = sn->surName + " " + sn->name + " " + sn->middleName + " " + sn->group;
                        delStudentsMenu->addItem(tmpString); //добавить в меню студентов
                        //sn = sn->next;
                    }
                    while (resultDel != exitDel) {
                        delStudentsMenu->run();
                        resultDel = delStudentsMenu->getSelectedItem();
                        if (resultDel == exitDel) {
                            break;
                        }
                        else {
                            int num = resultDel - 1;
                            sdb->DataBase.erase(std::next(sdb->DataBase.begin(), num));
                            break;
                        }
                    }
                }
                if (resultStudentSelectedItem>1)
                {
                    int num = resultStudentSelectedItem - 2; //!
                    sn = &sdb->DataBase.at(num);   
                    string oldRecordСardNumber = "";
                    oldRecordСardNumber = sn->recordСardNumber;
                    st->editStudent(sn);

                    if (sdb->getSameRecordСardNumber(sn->recordСardNumber)>1)
                    {
                        sn->recordСardNumber = oldRecordСardNumber;
                        cout << "Ошибка введен номер зачетной книжки который уже есть в БД";
                        _getch();
                    }
                }
            }
            //resultSelectedItem = exitInt;
            break;
        case 1:
            sn = new StudentNode();
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 10; j++)
                    sn->examsRecordsData[i][j].isEmpty = true;
            st->editStudent(sn);
            if (sdb->getSameRecordСardNumber(sn->recordСardNumber)>=1)
            {
                cout << "Ошибка введен номер зачетной книжки который уже есть в БД";
                _getch();
            }
            else
            {
                sdb->DataBase.push_front(*sn);
            }
            break;        
        case 2: //Сохранить в файл
            sdb->saveDataToFile(sdb->FileName);
            //sdb->saveDataToFile("d:\\db1.txt");
            break;
        case 3: //Вариант 77
            //ce->setLabel("Введите начальный год рождения для интервала выборки. ");
            //startYear = ce->setDataInt(1900, 2021);
            //ce->setLabel("Введите rjytxysq год рождения для интервала выборки. ");
            //endYear = ce->setDataInt(1900, 2021);
            startYear = 1900;
            endYear = 2000;

            system("cls");
            cout << "Полный список студентов" << endl;
            sdb->updateAvrMarks();  //Перерасчитать поле средний балл 
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            sdb->sortByAvrMarks();
            cout << "Отсортированный список студентов" << endl;
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            sdb1->DataBase.clear();
            sdb2->DataBase.clear();
            for(auto item: sdb->DataBase)
            { 
                sn = &item;
                year = atoi(sb->split(sn->birthDateString, '.', 2).c_str());
                if (year >= startYear and year <= endYear)
                    sdb1->DataBase.push_front(*sn);
                else
                    sdb2->DataBase.push_front(*sn);
            }
            cout << "Список студентов часть 1 (год рождения от " + std::to_string(startYear) + " до " + std::to_string(endYear) + " ): " << endl;
            sdb1->printAllSurName_Name_MName_bYaear_avrMarks();
            cout << "Список студентов часть 2 (год рождения НЕ от " + std::to_string(startYear) + " до " + std::to_string(endYear) + " ): " << endl;
            sdb2->printAllSurName_Name_MName_bYaear_avrMarks();
            _getch();
            resultSelectedItem = -1;
            break;
        case 4: //Вариант 71

            startYear = 1900;
            endYear = 2005;
            system("cls");
            cout << "Полный список студентов" << endl;
            sdb->updateMarks45(); //50% хороших и отличных оценокк
            sdb->printAllSurName_Name_MName_bYaear_Marks45();
            sdb->sortByMarks45();
            cout << "\nОтсортированный список студентов" << endl;
            sdb->printAllSurName_Name_MName_bYaear_Marks45();
            sdb1->DataBase.clear();
            sdb2->DataBase.clear();
            for (auto item : sdb->DataBase)
            {
                sn = &item;
                year = atoi(sb->split(sn->birthDateString, '.', 2).c_str());
                if (year >= startYear and year <= endYear){
                    if (sn->Marks45>=0.5)
                        sdb1->DataBase.push_front(*sn);
                    else
                        sdb2->DataBase.push_front(*sn);
                }
            }
            cout << "\nСписок студентов 4 и 5 > 50%: " << endl;
            sdb1->printAllSurName_Name_MName_bYaear_Marks45();
            cout << "\nСписок студентов 4 и 5 < 50%: " << endl;
            sdb2->printAllSurName_Name_MName_bYaear_Marks45();            
            cout << "\nСписок студентов 4 и 5 > 50%: два лучших " << endl;
            sdb3->DataBase.push_front(*sdb1->getMinMarks45());
            sdb1->DataBase.erase(sdb1->getMinMarks45());
            sdb3->DataBase.push_front(*sdb1->getMinMarks45());
            sdb3->printAllSurName_Name_MName_bYaear_Marks45();
            cout << "\nСписок студентов 4 и 5 < 50%: два худших" << endl;
            sdb3->DataBase.clear();
            sdb3->DataBase.push_front(*sdb2->getMaxMarks45());
            sdb1->DataBase.erase(sdb2->getMaxMarks45());
            sdb3->DataBase.push_front(*sdb2->getMaxMarks45());
            sdb3->printAllSurName_Name_MName_bYaear_Marks45();
            _getch();
            resultSelectedItem = -1;
            break;
        case 5: 
            //Вариант 31. Распечатать всех студентов в порядке убывания 5 в одном, 
            //    нескольких или всех семестрах, которые выбираются по желанию пользователя.
            //    Предусмотреть распечатывать лиц определенного пола.
            system("cls");
            sdb->getRangeSem();
            cout << "Полный список студентов" << endl;
            sdb->updateCountMarks5();
            sdb->printAllSurName_Name_MName_bYaear_countMarks5();
            sdb->sortByCountMarks5();
            cout << "\nОтсортированный список студентов" << endl;
            sdb->printAllSurName_Name_MName_bYaear_countMarks5();
            _getch();
            break;
        case 6:
            //Вариант 27. Отсортировать группу по успеваемости в каждой сессии 
            // или вводимой по требованию пользователя
            system("cls");
            sdb->getRangeSem();
            cout << "Полный список студентов" << endl;
            sdb->updateAvrMarksRangeSem();  //Перерасчитать поле средний балл 
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            sdb->sortByAvrMarks();
            cout << "\nОтсортированный список студентов" << endl;
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            _getch();
            break;
        case 7:
            //Вариант 57. Распечатать всех студентов, у которых за все время обучения не более 25 % оценок 
            //а) 3 б) 3 и 4 в) 5 г) 3 и 5 д) 4 и 5. 
            //Варианты а - д выбираются по желанию пользователя.
            //Их можно выбрать как 1, так и несколько или все варианты, 
            //с указанием интервала года рождения...
            ce->setLabel("Введите начальный год рождения для интервала выборки. ");
            startYear = ce->setDataInt(1900, 2021);
            ce->setLabel("Введите конечный год рождения для интервала выборки. ");
            endYear = ce->setDataInt(1900, 2021);
            //startYear = 1900;
            //endYear = 2005;
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase)           {
                sn = &item;
                year = atoi(sb->split(sn->birthDateString, '.', 2).c_str());
                if (year >= startYear and year <= endYear)
                    sdb1->DataBase.push_front(*sn);
            }
            sdb1->updateCountMarks543();  //Перерасчитать поля 
            var57(sdb1);
            _getch();
            break;
        case 8:
            //Вариант 43. Разбить группу на 2 части, с поиском среди лиц определенного пола:
            //1) по алфавиту от А до П;
            //2) по алфавиту от Р до Я.
            //Каждую часть отсортировать в порядке увеличения среднего бала за все время
            system("cls");
            cout << "Полный список студентов" << endl;
            sdb->updateAvrMarks();  //Перерасчитать поле средний балл 
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            sdb->sortByAvrMarks();
            cout << "\nОтсортированный список студентов" << endl;
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            firstPartString = "АБВГДЕЖЗИКЛМНОПабвгдежзиклмноп";
            sdb1->DataBase.clear();
            sdb2->DataBase.clear();
            for (auto item : sdb->DataBase) {
                for (int i = 0; i<firstPartString.length(); i++)
                    if (item.surName[0] == firstPartString[i]){
                        sdb1->DataBase.push_front(item);
                    }
            }
            cout << "\nCписок студентов по алфавиту от А до П" << endl;
            sdb1->printAllSurName_Name_MName_bYaear_avrMarks();     
            for (auto item : sdb->DataBase){
                bool isExist = false;
                for (auto item1 : sdb1->DataBase)
                    if (strcmp(item.surName.c_str(), item1.surName.c_str()) == 0)
                        isExist = true;
                if (isExist == false)
                    sdb2->DataBase.push_front(item);
            }

            cout << "\nCписок студентов по алфавиту от Р до Я" << endl;
            sdb2->printAllSurName_Name_MName_bYaear_avrMarks();
            _getch();
            break;
        case 9:
            resultSelectedItem = exitInt;
            break;
        default:
            break;
        }
    }
    //_getch();
    }
}


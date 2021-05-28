#include <iostream>
#include "StringBuilderClass.h"
#include "FileManagerClass.h"
#include "ClassMenu.h"
#include "StudentDBClass.h"
#include "StudentClass.h"
#include "ClassEdit.h"
#include "list.hpp"
//#include <algorithm>
using namespace std;

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
    mainMenu->addItem("Выход"); //5
    int resultSelectedItem = 0;
    int exitInt = 6;
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
            resultSelectedItem = exitInt;
            break;
        default:
            break;
        }
    }
    //_getch();
    }
}


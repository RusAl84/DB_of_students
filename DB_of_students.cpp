#include <iostream>
#include "StringBuilderClass.h"
#include "FileManagerClass.h"
#include "ClassMenu.h"
#include "StudentDBClass.h"
#include "StudentClass.h"
#include "ClassEdit.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    std::cout << "Курсовая работа запущена...\n";
    bool isDebug = false;
    if (isDebug) {
        StudentNode* sn = new StudentNode();
        StudentClass* st = new StudentClass();
        st->addRusakov();
        sn = st->getStudentNode();
        //st->editStudent(sn);
        st->editExamsResults(sn);
        //StringBuilderClass sb = StringBuilderClass();
        //cout << endl;
        //string s1 = sb.setParam("surName", "Ярошенко");
        //string s2 = sb.setParam("startYear", 2020);
        //cout << endl << s1 << "  " << sb.getType(s1) << endl;
        //cout << endl << s2 << "  " << sb.getType(s2) << endl;
        //sb.getName(s2);
        //sb.getValueInt(s2);
        //FileManagerClass fb = FileManagerClass("d:\\DB.txt");
        //fb.AddRusakovRecord();
        //StringBuilderClass sb = StringBuilderClass();
        //string tmpString = "27_12_1984";
        //cout << sb.split(tmpString,'_',2)<< endl;
    }
    else
    {
    StudentDBClass* sdb = new StudentDBClass();
    sdb->FileName = "DB.txt";
    sdb->loadDataFromFile();
    //cout << sdb->GetRecordCount() << endl;
    ClassMenu* mainMenu = new ClassMenu();
    mainMenu->addTitleItem("Главное меню");
    mainMenu->addItem("Просмотреть список студетов (удалить или изменить данные)"); //0
    mainMenu->addItem("Добавить данные о студенте в БД"); //1
    mainMenu->addItem("Сохранить БД студентов в файл"); //2
    //mainMenu->addItem("Выбрать файл для загрузки БД студентов"); //3
    mainMenu->addItem("Выход"); //4
    int resultSelectedItem = 0;
    int exitInt = 3;
    ClassMenu* studentsMenu = new ClassMenu();
    studentsMenu->addTitleItem("Список студентов");
    int resultStudentSelectedItem = 1;
    const int exitIntStudentMenu = 0;
    StudentNode* sn;
    StudentClass* st = new StudentClass();
    int curCount;
    while (resultSelectedItem != exitInt) {
        mainMenu->run();
        resultSelectedItem = mainMenu->getSelectedItem();
        switch (resultSelectedItem) {
        case 0:
            resultStudentSelectedItem = 1;
            while (resultStudentSelectedItem != exitIntStudentMenu) {
                studentsMenu->eraseItem();
                studentsMenu->addItem("Выход");
                sn = sdb->getInit();
                while (sn) {
                    string tmpString = sn->surName + " " + sn->name + " " + sn->middleName + " " + sn->group;
                    studentsMenu->addItem(tmpString); //добавить в меню студентов
                    sn = sn->next;
                }
                studentsMenu->run();
                resultStudentSelectedItem = studentsMenu->getSelectedItem();
                if (resultStudentSelectedItem == exitIntStudentMenu) {
                    break;
                }else{
                int num = resultStudentSelectedItem - 1;
                sn = sdb->getStudentNode(num);    
                st->editStudent(sn);
                }
            }
            //resultSelectedItem = exitInt;
            break;
        case 1:
            sn = new StudentNode();
            st->editStudent(sn);
            sdb->Add(sn);
            break;        
        case 2: //Сохранить в файл
            sdb->saveDataToFile();
            break;
        case 3: //Выход
            resultSelectedItem = exitInt;
            break;
        default:
            break;
        }
    }
    //_getch();
    }


}


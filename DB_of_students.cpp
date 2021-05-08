
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
    bool isDebug = true;
    if (isDebug) {
        StudentNode* sn = new StudentNode();
        StudentClass* st = new StudentClass();
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
    sdb->FileName = "d:\\DB.txt";
    sdb->loadDataFromFile();

    //cout << sdb->GetRecordCount() << endl;
    ClassMenu* mainMenu = new ClassMenu();
    mainMenu->addTitleItem("Главное меню");
    mainMenu->addItem("Вывести на экран список студентов");
    mainMenu->addItem("Добавить данные о студенте в БД");
    mainMenu->addItem("Выбрать файл для загрузки БД студентов");
    mainMenu->addItem("Сохранить БД студентов в файл");
    mainMenu->addItem("Выход");

    int resultSelectedItem = 0;
    int exitInt = 4;
    //StudentClass Rusakov = StudentClass();
    //Rusakov.addRusakov();
    //Rusakov.faculty = "Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...";
    ClassMenu* studentsMenu = new ClassMenu();
    studentsMenu->addTitleItem("Список студентов");
    int resultStudentSelectedItem = 1;
    studentsMenu->addItem("Выход");
    const int exitIntStudentMenu = 0;
    StudentNode* sn = new StudentNode;
    StudentClass* st = new StudentClass();
    int curCount;
    while (resultSelectedItem != exitInt) {
        mainMenu->run();
        resultSelectedItem = mainMenu->getSelectedItem();
        switch (resultSelectedItem) {
        case 0:
            //system("cls"); 
            //cout << "*** Список студентов ***" << endl;
            //sdb.printAllSurName();
            sdb->getInit();
            sn = sdb->getNext();
            while (sn->isNULL==false){
                string tmpString = sn->surName + " " + sn->name + " " + sn->middleName + " " + sn->group;
                studentsMenu->addItem(tmpString); //добавить в меню студентов
                sn = sdb->getNext();
            }
            while (resultStudentSelectedItem != exitIntStudentMenu) {
                studentsMenu->run();
                resultStudentSelectedItem = studentsMenu->getSelectedItem();
                int curCount = 0;
                int count = sdb->getCount();
                if ((resultStudentSelectedItem > 0) and (resultStudentSelectedItem < count)) {
                    sdb->getInit();
                    sn = sdb->getNext();
                    while (sn->isNULL == false) {
                        if (curCount == resultStudentSelectedItem)
                        {
                            st->editStudent(sn);
                                //
                            break;
                         }
                        else 
                        { sn = sdb->getNext(); } 
                        curCount++;
                    }
                }
                /// загружать данные из списка и отображать
            }
            //resultSelectedItem = exitInt;
            break;
        case 1:
            //system("cls");
            
            st->editStudent(sn);
            resultSelectedItem = exitInt;
            break;        
        case 2:
            system("cls");

            //cout << sizeof(Rusakov)*10000 << endl;
            //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            //SetConsoleTextAttribute(hConsole, 15);
            //sdb.printAllSurName();
            resultSelectedItem = exitInt;
            break;
        default:
            break;
        }

    }

    _getch();

    }


}


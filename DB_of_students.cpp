
#include <iostream>
#include "StringBuilderClass.h"
#include "FileManagerClass.h"
#include "ClassMenu.h"
#include "StudentDBClass.h"
#include "StudentClass.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Курсовая работа запущена...\n";
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

    StudentDBClass sdb = StudentDBClass();
    sdb.FileName = "d:\\DB.txt";
    sdb.loadDataFromFile();

    cout << sdb.GetRecordCount() << endl;
    ClassMenu mainMenu = ClassMenu();
    mainMenu.count = 5;
    mainMenu.items[0]->assign("Вывести на экран список студентов");
    mainMenu.items[1]->assign("Добавить данные о студенте в БД");
    mainMenu.items[2]->assign("Выбрать файл для загрузки БД студентов");
    mainMenu.items[3]->assign("Сохранить БД студентов в файл");
    mainMenu.items[4]->assign("Выход");
    int resultSelectedItem = 0;
    int exitInt = 4;
    //StudentClass Rusakov = StudentClass();
    //Rusakov.addRusakov();
    //Rusakov.faculty = "Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...Угу, в продакшене я просто беру питон, ставлю либу для парсинга PE и теку. Ещё не хватало на няшной или крестах эти структуры ковырять в сотый раз...";
    ClassMenu* studentsMenu = new ClassMenu();
    StudentNode sn;
    int resultStudentSelectedItem = 1;
    int studentCount = 0;
    studentsMenu->items[0]->assign("Выход");
    const int exitIntStudentMenu = 0;
    while (resultSelectedItem != exitInt) {
        mainMenu.run();
        resultSelectedItem = mainMenu.getSelectedItem();
        switch (resultSelectedItem) {
        case 0:
            //system("cls"); 
            //cout << "*** Список студентов ***" << endl;
            //sdb.printAllSurName();
            
            sdb.getInit();
            sn = sdb.getNext();
            while (sn.isNULL==false){
                string tmpString = sn.surName + " " + sn.name + " " + sn.middleName + " " + sn.group;
                studentsMenu->items[studentCount+1]->assign(tmpString);
                sn = sdb.getNext();
                studentCount++;
            }
            studentsMenu->count = studentCount+1;
            while (resultStudentSelectedItem != exitIntStudentMenu) {
                studentsMenu->run();
                resultStudentSelectedItem = studentsMenu->getSelectedItem();
            }
            //resultSelectedItem = exitInt;
            break;
        case 1:
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


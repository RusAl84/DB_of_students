
#include <iostream>
#include "StringBuilderClass.h"
#include "FileManagerClass.h"
#include "ClassMenu.h"
#include "StudentDBClass.h"
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
    cout << sdb.GetRecordCount() << endl;
    ClassMenu mainMenu = ClassMenu();
    mainMenu.count = 5;
    mainMenu.items[0]->assign("Вывести на экран список студентов");
    mainMenu.items[1]->assign("Добавить данные о студенте в БД");
    mainMenu.items[2]->assign("Выбрать файл для загрузки БД студентов");
    mainMenu.items[3]->assign("Сохранить БД студентов в файл");
    mainMenu.items[4]->assign("Выход");
    mainMenu.run();
    cout << endl << mainMenu.selectedItem << endl;
    _getch();




}


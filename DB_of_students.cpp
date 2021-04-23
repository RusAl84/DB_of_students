
#include <iostream>
#include "StringBuilderClass.h"
#include "FileManagerClass.h"

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

    FileManagerClass fb = FileManagerClass("d:\\DB.txt");
    fb.AddRusakovRecord();

}


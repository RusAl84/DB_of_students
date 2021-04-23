#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include "StringBuilderClass.h"
#include "StudentClass.h"
using namespace std;

class FileManagerClass : public StringBuilderClass
{
public:
    string FileName = "";

    FileManagerClass() {
        FileName = "";
    }

    FileManagerClass(string _FileName) {
        FileName = _FileName;
    }

    void AddRusakovRecord() {
        std::ofstream outFile;          // поток дл€ записи
        outFile.open(FileName, std::ios::app); // окрываем файл дл€ записи
        if (outFile.is_open())
        {
            outFile << "### Start Record" << std::endl;
            setlocale(LC_ALL, "Russian");
            StringBuilderClass sb = StringBuilderClass();
            string s1 = sb.setParam("surName", "ярошенко");
            StudentClass stud = StudentClass();
            stud.addRusakov();


            outFile << "### End Record" << std::endl;
        }
        outFile.close();
    }
    void GetRecordCount() {

    }

    static void display(string FileName) {
        string line;
        ifstream inFile(FileName); // окрываем файл дл€ чтени€
        if (inFile.is_open())
            while (getline(inFile, line))
                std::cout << line << std::endl;
        inFile.close();     // закрываем файл
    }
};


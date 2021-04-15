#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileManagerClass
{
public:
	string FileName;
    static void AddRecord() {
        std::ofstream outFile;          // поток для записи
        outFile.open(FileName); // окрываем файл для записи
        if (outFile.is_open())
        {
            outFile << "### Start Record" << std::endl;
            outFile << "### End Record" << std::endl;
        }
        outFile.close();
	}
    static void display(string FileName) {
        string line;
        ifstream inFile(FileName); // окрываем файл для чтения
        if (inFile.is_open())
            while (getline(inFile, line))
                std::cout << line << std::endl;
        inFile.close();     // закрываем файл
    }
};


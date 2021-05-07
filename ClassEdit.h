#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include "ClassMenu.h"

using namespace std;
class ClassEdit
{
private:
	string data;
	string label;
public:

	ClassEdit() {};
	void setLabel(string inString) {
		label = inString;
	}
	void draw(){
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int maxLength = label.length();
			drawLineUP(maxLength + 6);
			SetConsoleTextAttribute(hConsole, 15);
			string tmpString = "";
			tmpString = "|   ";
			tmpString = tmpString + label.c_str();
			while (tmpString.length() < maxLength + 7)
				tmpString += " ";
			tmpString += "|";
			cout << tmpString << endl;
			drawLineDown(maxLength + 7);
	}

	string setDataString() {
		draw();
		string inString = "";
		while (inString.length()==0){
			cin >> inString;
		}
		data = inString;
		return data;
	}
	int setDataInt() {
		draw();
		string inString = "";
		while (inString.length() == 0) {
			cin >> inString;
			if (not isDigit(inString)){
				inString = "";
				cout << "ќшибка: ќжидалось число.";
			}
		}
		data = inString;
		return atoi(data.c_str());
	}

	bool isDigit(string inString) {
		bool flag = true;
		for (int i = 0; i < inString.length(); i++)
		{
			if (not isdigit(inString[i]))
				flag = false;
		}
		return flag;
	}

	friend void drawLineUP(int size);
};


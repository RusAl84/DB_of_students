#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
class ClassMenu
{
public:
    string items[30][40];
    int selectedItem;
    int count;

    ClassMenu() {
        selectedItem = 0;
    }
    void setDown() {
        selectedItem++;
        if (selectedItem > count - 1)
            selectedItem = 0;
    }
    void setUp() {
        selectedItem--;
        if (selectedItem < 0)
            selectedItem = count - 1;
    }

    //где <A> и <B> Ч шестнадцатеричные цифры Ч перва€ задает цвет фона, а втора€ Ч цвет переднего плана(цвет шрифта).
    //    «начени€ цифр
    //    0 Ч черный
    //    1 Ч синий
    //    2 Ч зеленый
    //    3 Ч голубой
    //    4 Ч красный
    //    5 Ч лиловый
    //    6 Ч желтый
    //    7 Ч белый
    //    8 Ч серый
    //    9 Ч свело - синий
    //    A Ч светло - зеленый
    //    B Ч светло - голубой
    //    — Ч светло - красный
    //    E Ч светло - желтый
    //    F Ч €рко - белый
    //system("Color 15");
    void draw() {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        for (int i = 0; i < 5; i++) {

            if (i == selectedItem) {
                SetConsoleTextAttribute(hConsole, 13);
                cout << " * " << items[i]->c_str() << endl;
            }
            else {
                SetConsoleTextAttribute(hConsole, 15);
                cout << "   " << items[i]->c_str() << endl;
            }

        }
    }

    void run() {
        char ch = ' ';
        while (ch != 13) {
            draw();
            Sleep(100);
            ch = _getch();
            //cout << endl << ch <<endl;
            if (ch == 80)  // вниз
                setDown();
            if (ch == 72)
                setUp();
        }

    }

};
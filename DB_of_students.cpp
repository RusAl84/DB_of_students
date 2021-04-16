
#include <iostream>
#include "StringBuilderClass.h"

int main()
{
    std::cout << "Hello World!\n";

    setlocale(LC_ALL, "Russian");
    StringBuilderClass sb = StringBuilderClass();
    cout << endl;
    string s1 = sb.setParam("MersovMersovMersov:-:-", "МужикМужикМужикМужикМужик;)");
    string s2 = sb.setParam("MersovMersovMersov:-:-", 1001);
    cout << endl << s1 << "  " << sb.getType(s1) << endl;
    cout << endl << s2 << "  " << sb.getType(s2) << endl;



}


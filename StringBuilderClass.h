#pragma once
#include <string>
using namespace std;
class StringBuilderClass
{
public:
	string setParam(string name, string value) {
		string outString = "name:000; value:str:000 -: ";
						//  0123456789012345678901234567
		int offset = outString.length(); //28
		//cout << offset;
		string lengthName = std::to_string(name.length());
		if (lengthName.length()==1) {
			outString[7] = lengthName[0];
		}
		if (lengthName.length() == 2) {
			outString[6] = lengthName[0];
			outString[7] = lengthName[1];
		}
		string lengthValue = std::to_string(value.length());
		if (lengthValue.length() == 1) {
			outString[22] = lengthValue[0];
		}
		if (lengthValue.length() == 2) {
			outString[21] = lengthValue[0];
			outString[22] = lengthValue[1];
		}
		outString = outString + name + "=" + value;
		//cout << outString;
		return outString;
	}

	string setParam(string name, int intvalue) {
		string outString = "name:000; value:int:000 -: ";
						//  0123456789012345678901234567
		string value = std::to_string(intvalue);
		int offset = outString.length(); //28
		//cout << offset;
		string lengthName = std::to_string(name.length());
		if (lengthName.length() == 1) {
			outString[7] = lengthName[0];
		}
		if (lengthName.length() == 2) {
			outString[6] = lengthName[0];
			outString[7] = lengthName[1];
		}
		string lengthValue = std::to_string(value.length());
		if (lengthValue.length() == 1) {
			outString[22] = lengthValue[0];
		}
		if (lengthValue.length() == 2) {
			outString[21] = lengthValue[0];
			outString[22] = lengthValue[1];
		}

		outString = outString + name + "=" + value;
		//cout << outString;
		return outString;
	}

	string getName(string inString) {
		return "";
	}

	string getType(string inString) {
		string ch = " ";
		ch[0] = inString[16];
		if (ch.compare("i") == 0) {
			return "int";
		}
		if (ch.compare("s")==0) {
			return "str";
		}
		return "";
	}


	int getValueInt(string inString){
		string tmpString = "";
		int lengthName = 0;
		tmpString = inString[5] + inString[6] + inString[7];
		lengthName = std::stoi(tmpString);
		string	lengthValue = "";
		tmpString = inString[20] + inString[21] + inString[22];
		int lengthValue = std::stoi(tmpString);;
		int offset = 28;
		return 0;
	}

	string getValueStr(string inString) {
		return "";
	}

};


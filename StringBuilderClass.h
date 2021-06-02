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
		string tmpString = "000";
		int lengthName = 0;
		tmpString[0] = inString[5];
		tmpString[1] = inString[6];
		tmpString[2] = inString[7];
		//cout << endl << tmpString << endl;
		lengthName = atoi(tmpString.c_str());
		tmpString = "000";
		tmpString[0] = inString[20];
		tmpString[1] = inString[21];
		tmpString[2] = inString[22];
		int lengthValue = 0;
		lengthValue = atoi(tmpString.c_str());
		int offset = 28;
		string valueString(lengthName, ' ');
		for (int i = 0; i < lengthName; i++) {
			valueString[i] = inString[i + offset - 1];
		}
		//cout << endl << valueString << endl;
		return valueString;
	}

	string getType(string inString) {
		string ch = " ";
		ch[0] = inString[16];
		if (ch.compare("i") == 0) {
			return "int";
		}
		if (ch.compare("s") == 0) {
			return "str";
		}
		return "";
	}

	int getValueInt(string inString) {
		string tmpString = "000";
		int lengthName = 0;
		tmpString[0] = inString[5];
		tmpString[1] = inString[6];
		tmpString[2] = inString[7];
		//cout << endl << tmpString << endl;
		lengthName = atoi(tmpString.c_str());
		tmpString = "000";
		tmpString[0] = inString[20];
		tmpString[1] = inString[21];
		tmpString[2] = inString[22];
		int lengthValue = 0;
		lengthValue = atoi(tmpString.c_str());
		int offset = 28;
		string valueString(lengthValue, '0');
		for (int i = 0; i < lengthValue; i++) {
			valueString[i] = inString[i + offset + lengthName];
		}
		//cout << endl << valueString << endl;
		return atoi(valueString.c_str());
	}

	string getValueStr(string inString) {
		string tmpString = "000";
		int lengthName = 0;
		tmpString[0] = inString[5];
		tmpString[1] = inString[6];
		tmpString[2] = inString[7];
		//cout << endl << tmpString << endl;
		lengthName = atoi(tmpString.c_str());
		tmpString = "000";
		tmpString[0] = inString[20];
		tmpString[1] = inString[21];
		tmpString[2] = inString[22];
		int lengthValue = 0;
		lengthValue = atoi(tmpString.c_str());
		int offset = 28;
		string valueString(lengthValue, '0');
		for (int i = 0; i < lengthValue; i++) {
			valueString[i] = inString[i + offset + lengthName];
		}
		//cout << endl << valueString << endl;
		return valueString;
	}
	string split(const string inString, char delimiter, int num) {
		string outString = "";
		int numDelimeter = 0;
		for (int i = 0; i <= inString.length(); i++) {
			if (inString[i] == delimiter) { 
				numDelimeter++; }
			if ((numDelimeter == num) && (delimiter != inString[i])) {
				  outString = outString + inString[i];
			}

		}
		
		return outString;
	}

};


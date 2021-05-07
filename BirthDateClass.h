#pragma once
class BirthDateClass: public StringBuilderClass
{
private:
	int Day;
	int Month;
	int Year;
public:
	void setDate(int _Day, int _Month, int _Year) {
		Day = _Day;
		Month = _Month;
		Year = _Year;
	}
	int getDay() {
		return Day;
	}	
	int getMonth() {
		return Month;
	}	
	int getYear() {
		return Year;
	}
	string getString() {
		return std::to_string(Day)+"."+std::to_string(Month)+"."+std::to_string(Year);
	}
	void setOfString(string inString) {
		Day = atoi(split(inString, '.', 0).c_str());
		Month = atoi(split(inString, '.', 1).c_str());
		Year = atoi(split(inString, '.', 2).c_str());
	}
};


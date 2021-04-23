#pragma once
class BirthDateClass
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
		return std::to_string(Day)+"_"+std::to_string(Month)+"_"+std::to_string(Year);
	}


};


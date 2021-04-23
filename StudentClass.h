#include <string>
#include "BirthDateClass.h"
#include "ExamsResultsClass.h"
#include "StringBuilderClass.h"
#include "StringMasClass.h"
using namespace std;
class StudentClass
{
private:
	string surName;
	string name;
	string middleName;
	string faculty;
	string department;
	string group;
	string recordСardNumber;
	bool sex; // true - мальчик
			  // false - девочка
	int startYear;
	BirthDateClass birthDate;
	ExamsResultsClass examsResults;
	StringMasClass stringMas;

public:


	void addRusakov() {
		surName = "Русаков";
		name = "Алексей";
		middleName = "Михайлович";
		faculty = "10.05.04 Информационно-аналитические системы безопасности";
		department = "Институт комплексной безопасности и специального приборостроения";
		group = "БИСО-01-21";
		recordСardNumber = "20Б0857";
		sex = true;
		startYear = 2021;
		birthDate.setDate(27, 12, 1984);
		examsResults.addData(0, 1, "Яыки программирования 1", 5);
		examsResults.addData(0, 2, "Математика 1", 5);
		examsResults.addData(0, 3, "Физкультура 1", true);
		examsResults.addData(1, 1, "Яыки программирования 2", 5);
		examsResults.addData(1, 2, "Математика 2", 5);
		examsResults.addData(1, 3, "Физкультура 2", true);
	}

	void UpdateMasString() {

		stringMas.Erase();
		StringBuilderClass sb = StringBuilderClass();
		string tmpString = sb.setParam("surName", surName);
		stringMas.Add(tmpString);
		string tmpString = sb.setParam("name", name);
		stringMas.Add(tmpString);		
		string tmpString = sb.setParam("middleName", middleName);
		stringMas.Add(tmpString);		
		string tmpString = sb.setParam("faculty", faculty);
		stringMas.Add(tmpString);
		string tmpString = sb.setParam("department", department);
		stringMas.Add(tmpString);
		string tmpString = sb.setParam("group", group);
		stringMas.Add(tmpString);		
		int intSex = 1;
		if (sex)
			intSex = 1;
		else
			intSex = 0;
		string tmpString = sb.setParam("sex", intSex);
		stringMas.Add(tmpString);		
		string tmpString = sb.setParam("startYear", startYear);
		stringMas.Add(tmpString);




	}
};

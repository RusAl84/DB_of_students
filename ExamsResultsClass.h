#pragma once
class ExamsResultsClass
{
private:
	ExamsRecords data[9][10];
public:
	ExamsResultsClass() {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++)
				data[i][j].isEmpty = true;
	}
	bool addData(int sem, int num, string Item, int Mark) {
		data[sem][num].isEmpty = false;
		data[sem][num].Item = Item;
		data[sem][num].Mark = Mark;
	}
	bool addData(int sem, int num, string Item, bool zach) {
		data[sem][num].isEmpty = false;
		data[sem][num].Item = Item;
		if (zach)
			data[sem][num].Mark = 1;
		else
			data[sem][num].Mark = 0;
	}


};

struct ExamsRecords {
	string Item;
	int Mark; // 0 - зачет
			  // не зачет    2,3,4,5
	bool isEmpty; // заполнено ли поле
};
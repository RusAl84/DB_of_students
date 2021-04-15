#pragma once
class ExamsResultsClass
{ 
public:
	ExamsRecords data[9][10];
};

struct ExamsRecords {
	string Item;
	int Mark; // 0 - зачет
			  // не зачет
};
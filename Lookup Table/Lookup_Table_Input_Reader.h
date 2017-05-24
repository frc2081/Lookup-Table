#pragma once
#include <iostream>
#include <fstream>
#include "Lookup_Table.h"
class Lookup_Table_Input_Reader
{
public:
	// Array of Points that will be filled upon class' instantiation
	Lookup_Table::Point *Points;
	// Will always need to start at row 1
	int Rows = 1;

	// Constructor and deconstructor
	Lookup_Table_Input_Reader(char*);
	~Lookup_Table_Input_Reader();

private:
	void CountRows();
	void MakePoints();
	char *_file;
};


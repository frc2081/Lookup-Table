#pragma once
#include <iostream>
#include <fstream>
#include "LookupTable.h"

class __declspec(dllexport) LookupTableInputReader
{
public:
	// Array of Points that will be filled upon class' instantiation
	LookupTable::Point *Points;
	// Will always need to start at row 1
	int Rows = 1;

	// Constructor and deconstructor
	LookupTableInputReader(char*);
	~LookupTableInputReader();

private:
	void CountRows();
	void MakePoints();
	char *_file;
};

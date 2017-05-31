#define _CRT_SECURE_NO_WARNINGS
//Because fopen throws stuff

#include "LookupTableInputReader.h"
using namespace std;

namespace LibIcarus
{
	LookupTableInputReader::LookupTableInputReader(char *file)
	{
		// Set instance properties so they don't have to be passed between methods
		_file = file;

		// Determine number of Points based on number of newlines in the input file
		this->CountRows();
		// Make a new array of Points with the size of the number of Points from the file
		Points = new LookupTable::Point[Rows];
		// Actually read the Points from the file into the array of Points
		this->MakePoints();
	}

	void LookupTableInputReader::CountRows()
	{
		int ch;
		FILE *File;
		// Open the file with mode "r" (reading only)
		File = fopen(_file, "r");

		// Iterate over all the characters in the file, as long as we aren't at the end
		while (!feof(File))
		{
			// Get the integer value of the character being iterated over
			ch = fgetc(File);
			// If the character value is equivalent to the character value of a newline
			if (ch == '\n')
				// Add 1 to Rows
				++Rows;
		}
		// Close the input file to prevent any unintentional misreading when reopened
		fclose(File);
	}

	void LookupTableInputReader::MakePoints()
	{
		// Open a new input stream from the input file
		ifstream File(_file, ios::in);
		// Variables for holding values
		int in, out;
		int iter = 0;
		// Some magic code that I honestly don't understand
		while (File >> in >> out)
		{
			// Make a new Point in the array of Points based on the values from the line
			Points[iter] = LookupTable::Point(in, out);
			++iter;
		}
	}


	LookupTableInputReader::~LookupTableInputReader()
	{
		// Not entirely sure what to free here

		//delete this;
	}
}
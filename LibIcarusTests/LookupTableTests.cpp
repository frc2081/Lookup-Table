#include "LookupTableTests.h"
#include <stdio.h>

static inline char* BuildAssertTableErrorMessage(double input, double expected, double output);

#define ILTP(input, value) LookupTable::Point(input, value)
void LookupTableTests::LookupTableCaseOne()
{
	const int rows = 10;
	LookupTable::Point tableInputs[rows] = 
	{
		ILTP(1, 1),
		ILTP(2, 2),
		ILTP(3, 3),
		ILTP(4, 4),
		ILTP(5, 5),
		ILTP(6, 6),
		ILTP(7, 6),
		ILTP(8, 6),
		ILTP(9, 8),
		ILTP(10, 10)
	};

	LookupTable table(rows, tableInputs);

	AssertLookupValue(&table, 1, 1);
	AssertLookupValue(&table, 10, 10);
	AssertLookupValue(&table, 5, 5);
	AssertLookupValue(&table, 5.5, 5.5);
	AssertLookupValue(&table, 11, 10);
	AssertLookupValue(&table, 20, 10);
	AssertLookupValue(&table, 0, 1);
	AssertLookupValue(&table, -5, 1);
	AssertLookupValue(&table, 6, 6);
	AssertLookupValue(&table, 7, 6);
	AssertLookupValue(&table, 8, 6);
	AssertLookupValue(&table, 8.5, 7);
	AssertLookupValue(&table, 9.25, 8.5);
}

void LookupTableTests::LookupTableCaseTwo()
{
	const int rows = 7;

	LookupTable::Point tableInputs[rows] =
	{
		ILTP(-52.6, -12.4),
		ILTP(-2.3, 13.5),
		ILTP(1, 13.5),
		ILTP(2, 26.4),
		ILTP(3, 10.45),
		ILTP(1045, 6),
		ILTP(1050, 17.8)
	};

	LookupTable table(rows, tableInputs);

	AssertLookupValue(&table, -20, 4.39);
	AssertLookupValue(&table, 0.3, 13.50);
	AssertLookupValue(&table, 1.2, 16.08);
	AssertLookupValue(&table, 2.35, 20.82);
	AssertLookupValue(&table, 999, 6.20);
	AssertLookupValue(&table, 1048, 13.08);
	AssertLookupValue(&table, 1051, 18);
}

void LookupTableTests::AssertLookupValue(LookupTable* table, double input, double expected)
{
	double output;
	const double threshold = 0.0001;
	output = table->GetOutput(input);

	if (output < expected - threshold || output > expected + threshold)
		throw BuildAssertTableErrorMessage(input, expected, output);
}

char* BuildAssertTableErrorMessage(double input, double expected, double output)
{
#define ASSERT_MESSAGE_SIZE 200
	char* message = new char[ASSERT_MESSAGE_SIZE];
	sprintf_s(message, ASSERT_MESSAGE_SIZE - 1, "Lookup Table assertion failed.  Input was '%.2f', expected '%.2f', but received '%.2f'.", input, expected, output);

	return message;
}

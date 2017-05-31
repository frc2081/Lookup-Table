#include "LookupTableInputReader.h"
#include "LookupTable.h"

int main(int argc, char **argv)
{
	// If there are less than 2 arguments besides the program, return exit code 1
	if (argc < 3) return 1;

	// Make a new Input_Reader using the first CLI argument (should be filename/filepath)
	LookupTableInputReader data(argv[1]);

	// Make a new Lookup_Table using the data made by the Input_Reader
	LookupTable *table = new LookupTable(data.Rows, data.Points);

	// Get the output values from the table based on the second CLI argument (the number you want to get)
	double x = table->GetOutput(atof(argv[2]));

	// Print the aforementioned value
	printf("%f", x);

	return 0;
}
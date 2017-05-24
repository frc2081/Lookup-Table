#include "Lookup_Table_Input_Reader.h"
#include "Lookup_Table.h"

int main(int argc, char **argv)
{
	// If there are less than 2 arguments besides the program, return exit code 1
	if (argc < 3) return 1;

	// Make a new Input_Reader using the first CLI argument (should be filename/filepath)
	Lookup_Table_Input_Reader data(argv[1]);

	// Make a new Lookup_Table using the data made by the Input_Reader
	Lookup_Table *table = new Lookup_Table(data.Rows, data.Points);

	// Get the output values from the table based on the second CLI argument (the number you want to get)
	double x = table->GetOutput(atof(argv[2]));

	// Print the aforementioned value
	printf("%f", x);

	return 0;
}

#include "Lookup_Table.h"

int main()
{
	int rows = 3;
	Lookup_Table::Point points[3] = 
	{
		Lookup_Table::Point(1, 2),
		Lookup_Table::Point(2, 4),
		Lookup_Table::Point(3, 6)
	};

	Lookup_Table *table = new Lookup_Table(rows, points);
	table->GetOutput(10);

	table->GetOutput(2.5);

	table->GetOutput(0);

	table->GetOutput(3);

	return 0;
}
#include "Lookup_Table.h"


Lookup_Table::Lookup_Table(int rows, Point *points)
{
	_rows = rows;

	_point = new Point[_rows];

	for (int i = 0; i < _rows; i++) {
		_point[i].input = points[i].input;

		_point[i].output = points[i].output;
	}
}


double Lookup_Table::GetOutput(double input)
{
	double lower;
	double greater;

	for (int i = 0; i < _rows; i++) {
		// Won't this throw an error if i == 0 because 0 isn't less than 0 so it will try to access the -1st element in the array (which I think would actually be the last)?
		lower = (i < 0) ? _point[0].output : _point[i - 1].output;
		// Shouldn't it be this?
		// lower = (i <= 0) ? _point[0].output : _point[i - 1].output;

		greater = ((i + 1) >= _rows) ? _point[_rows - 1].output :  _point[i + 1].output;

		if (input >= _point[i].input) {
			break;
		}
	}
}

Lookup_Table::~Lookup_Table()
{
	delete _point;

	_rows = 0;
}

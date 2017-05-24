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
	Point lower, greater;

	GetLimits(input, &lower, &greater);

	return 0;
}

void Lookup_Table::GetLimits(double val, Point *lower, Point *greater) {

	double currInput;

	*lower = *greater =  _point[0];

	for (int i = 0; i < _rows; i++) {
		currInput = _point[i].input;

		*lower = (i <= 0) ? _point[0] : _point[i - 1];

		if (currInput == val) {
			*lower = *greater = _point[i];
			return;
		}

		if (val <= currInput) {
			return;
		}

		*greater = ((i + 1) >= _rows) ? _point[_rows - 1] : _point[i + 1];
	}

	*lower = *greater = _point[_rows - 1];
}

double Lookup_Table::GetLine(double greater, double lower, Point *point) {
	//y = mx + b
	//b = 0
	//lower -> x=0
	//greater -> x=1
	//values are y

	//double y;
	//double slope;

	//y = 


	return 0;
}

Lookup_Table::~Lookup_Table()
{
	delete _point;

	_rows = 0;
}

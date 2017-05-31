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

	return Interpolate(input, &lower, &greater);

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

double Lookup_Table::Interpolate(double val, Point *lower, Point *greater) {
	//y = mx + b
	//input == x
	//output == y

	double b = 0;
	if (greater->input == lower->input || greater->output == lower->output) {
		return greater->output;
	}

	double m = (greater->output - lower->output) / (greater->input - lower->input);

	double out = m * val + b;

	return out;
}

Lookup_Table::~Lookup_Table()
{
	delete _point;

	_rows = 0;
}

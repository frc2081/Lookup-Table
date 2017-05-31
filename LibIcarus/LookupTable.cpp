#include "LookupTable.h"

LookupTable::LookupTable(int rows, Point *points)
{
	_rows = rows;

	_point = new Point[_rows];

	for (int i = 0; i < _rows; i++) {
		_point[i].input = points[i].input;

		_point[i].output = points[i].output;
	}
}


double LookupTable::GetOutput(double input)
{
	Point lower, greater;

	GetLimits(input, &lower, &greater);

	return Interpolate(input, &lower, &greater);

}

void LookupTable::GetLimits(double val, Point *lower, Point *greater) {

	double currInput;

	*lower = *greater = _point[0];

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

double LookupTable::Interpolate(double val, Point *lower, Point *greater) {
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

LookupTable::~LookupTable()
{
	delete _point;

	_rows = 0;
}
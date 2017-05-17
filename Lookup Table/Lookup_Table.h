#pragma once
class Lookup_Table
{
public:
	struct Point {

		Point() {

		}

		Point(int in, int out) {
			input = in;
			output = out;
		}

		double  input;

		double  output;

	};

	Lookup_Table(int rows, Point *points );
	~Lookup_Table();

	double GetOutput(double input);


private:
	int _rows;

	Point *_point;

};


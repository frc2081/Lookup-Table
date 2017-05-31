#pragma once
namespace LibIcarus
{
	class __declspec(dllexport) LookupTable
	{
	public:
		struct Point {

			//Give numbers in ascedning order
			Point()
			{ }

			Point(int in, int out)
			{
				input = in;
				output = out;
			}

			double  input;
			double  output;

		};

		LookupTable(int rows, Point *points);
		~LookupTable();

		double GetOutput(double input);


	private:
		int _rows;

		Point *_point;

		void GetLimits(double val, Point *lower, Point *greater);

		double Interpolate(double val, Point *lower, Point *greater);
	};
}
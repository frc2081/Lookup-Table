#pragma once
class Lookup_Table
{
public:
	Lookup_Table(int rows);
	~Lookup_Table();

	double GetOutput(double input);

	double SetInputs(double inputs[]);

	double SetOutputs(double inputs[]);

private:
	int _rows;

	int *_outputs;

	int *_inputs;
};


#pragma once

class TestValidators {
public:
	TestValidators(double *values, int arrayLength);

	double readSignalFromHardware();

protected:

	double *_values;

	int _arrayLength;

	int counter;

};
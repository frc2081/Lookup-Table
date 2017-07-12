#include "TestValidators.h"

TestValidators::TestValidators(double *values, int arrayLength) {
	_values = values;

	_arrayLength = arrayLength;

	counter = 0;
}

double TestValidators::readSignalFromHardware() {

	return _values[(counter++) % _arrayLength];
}
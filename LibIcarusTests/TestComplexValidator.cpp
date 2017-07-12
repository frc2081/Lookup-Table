#include "TestComplexValidator.h"


TestComplexValidator::TestComplexValidator(LookupTable *tableLower, LookupTable *tableGreater, double *values, int arrayLength) : TestValidators(values, arrayLength) {
	_tableLower = tableLower;

	_tableGreater = tableGreater;
}

double TestComplexValidator::TInputGetDouble(TestInput input) {
	return input.decimal;
}
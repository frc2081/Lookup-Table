#include "TestSimpleValidator.h"

TestSimpleValidator::TestSimpleValidator(double *values, int arrayLength, double lower, double greater) : TestValidators(values, arrayLength) {
	this->lower = lower;

	this->greater = greater;
}

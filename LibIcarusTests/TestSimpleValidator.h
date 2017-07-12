#pragma once
#include "SignalSimpleValidator.h"
#include "TestInput.h"
#include "TestValidators.h"
using namespace LibIcarus;


class TestSimpleValidator : SignalSimpleValidator<TestInput>, TestValidators {
public:

	TestSimpleValidator(double *values, int arrayLength, double lower, double greater);

	double readSignalFromHardware();
};
#pragma once
#include "SignalComplexValidator.h"
#include "TestSimpleValidator.h"
#include "TestValidators.h"
#include "TestInput.h"
using namespace LibIcarus;


class TestComplexValidator : SignalComplexValidator<TestInput>, TestValidators {

	TestComplexValidator(LookupTable *tableLower, LookupTable *tableGreater, double *value, int arrayLength);

	double TInputGetDouble(TestInput input);

private:

	LookupTable *_tableLower;

	LookupTable *_tableGreater;
};
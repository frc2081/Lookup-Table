#pragma once
#include "TestSimpleValidator.h"
#include "TestComplexValidator.h"
#include "TestBase.h"

using namespace LibIcarus;
class ValidatorTests : public TestBase
{
public:
	static void simpleTestOne();
	static void simpleTestTwo();
	static void simpleTestThree();
	static void complexTest();

protected:
};
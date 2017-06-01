#pragma once
#include "LookupTable.h"
#include "TestBase.h"

using namespace LibIcarus;
class LookupTableTests : public TestBase
{
public:
	static void LookupTableCaseOne();
	static void LookupTableCaseTwo();

protected:
	static void AssertLookupValue(LookupTable *table, double input, double expected);
};


#include "TestBase.h"
void TestBase::AssertIsTrue(int expression)
{
	if (!expression) throw new char* { "Assertion failed; expression not true." };
}

void TestBase::AssertIsFalse(int expression)
{
	if (expression) throw new char* { "Assertion failed; expression is true." };
}

template<class TValue>
void TestBase::AssertAreEqual(TValue a, TValue b)
{
	if (a != b) throw new char*{ "Equality assertion failed." };
}
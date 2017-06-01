#pragma once

class TestBase
{
protected:
	static void AssertIsTrue(int expression);
	static void AssertIsFalse(int expression);
	
	template <class TValue>
	static void AssertAreEqual(TValue a, TValue b);
};

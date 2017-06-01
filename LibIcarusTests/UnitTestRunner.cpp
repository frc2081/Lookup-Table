#include "UnitTestRunner.h"
#include <stdio.h>

UnitTestRunner::UnitTestRunner(UnitTestSet tests)
{
	_tests = tests;
}

UnitTestRunner::~UnitTestRunner()
{
	_tests.TestCount = 0x0;
	_tests.Tests = 0x0;
}

void UnitTestRunner::Run(UnitTestResult **results, int *resultCount)
{
	int i, testCount;

	testCount = _tests.TestCount;
	*results = new UnitTestResult[testCount];
	*resultCount = testCount;

	for (i = 0; i < _tests.TestCount; i++)
	{
		UnitTest test = _tests.Tests[i];
		UnitTestResult* result = &results[0][i];

		RunTest(test, result);
	}
}

void UnitTestRunner::RunTest(UnitTest test, UnitTestResult *result)
{
	try
	{
		test.Method();
		
		sprintf_s(result->Message, 240, "Test '%s' passed.", test.Name);
		result->ReturnCode = 0;
	}
	catch(char* message)
	{
		sprintf_s(result->Message, 240, "Test '%s' failed with message: %s", test.Name, message);
		result->ReturnCode = 1;
		delete message;
	}
}
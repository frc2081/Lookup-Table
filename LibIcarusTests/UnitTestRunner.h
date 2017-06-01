#pragma once
#include <string.h>

class UnitTestRunner
{
public:

	typedef void(*UnitTestMethod)();
	struct UnitTest
	{
	public:
		UnitTest(){}
		UnitTest(const char* name, UnitTestMethod method)
		{
			Name = name;
			Method = method;
		}

		const char* Name;
		UnitTestMethod Method;
	};

	struct UnitTestSet
	{
	public:
		UnitTestSet(){}
		UnitTestSet(UnitTest *tests, int testCount)
		{
			Tests = tests;
			TestCount = testCount;
		}

		UnitTest* Tests;
		int TestCount;
	};

	struct UnitTestResult
	{
	public:
#define UNIT_TEST_RESULT_MESSAGE_SIZE 250
		UnitTestResult()
		{
			memset(Message, 0x0, UNIT_TEST_RESULT_MESSAGE_SIZE);
		}
		~UnitTestResult()
		{
			memset(Message, 0x0, UNIT_TEST_RESULT_MESSAGE_SIZE);
		}
		UnitTestResult(int returnCode, const char* message)
		{
			ReturnCode = returnCode;
			strcpy_s(Message, message);
		};

		char Message[UNIT_TEST_RESULT_MESSAGE_SIZE];
		int ReturnCode;
	};

	UnitTestRunner(UnitTestSet tests);
	~UnitTestRunner();
	void Run(UnitTestResult **results, int *resultCount);

private:
	UnitTestSet _tests;
	void RunTest(UnitTest test, UnitTestResult *result);
};

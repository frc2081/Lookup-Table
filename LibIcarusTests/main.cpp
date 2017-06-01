#include "UnitTestRunner.h"
#include "LookupTableTests.h"
#include "ConsoleWriter.h"

int LogResult(ConsoleWriter* writer, UnitTestRunner::UnitTestResult *result);

#define IUTS(method, name) UnitTestRunner::UnitTest(name, method) 
int main(int argc, char **argv)
{
	int i, errorCode = 0;
	const int testCount = 2;
	UnitTestRunner::UnitTest tests[testCount] =
	{
		IUTS(LookupTableTests::LookupTableCaseOne, "Lookup Table #1"),
		IUTS(LookupTableTests::LookupTableCaseTwo, "Lookup Table #2"),
	};

	UnitTestRunner::UnitTestSet testSet(tests, testCount);
	UnitTestRunner runner(testSet);
	ConsoleWriter logger(ConsoleWriter::AnsiEscaped);

	int resultCount;
	UnitTestRunner::UnitTestResult *results;
	runner.Run(&results, &resultCount);

	for (i = 0; i < resultCount; i++)
		errorCode |= LogResult(&logger, &results[i]);

	delete[] results;
	return errorCode;
}

int LogResult(ConsoleWriter* writer, UnitTestRunner::UnitTestResult *result)
{
	int errCode = result->ReturnCode;
	void (ConsoleWriter::*logMethod)(const char*) = errCode == 0
		? &ConsoleWriter::WriteInfo
		: &ConsoleWriter::WriteError;

	(writer->*logMethod)(result->Message);
	return errCode;
}
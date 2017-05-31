#include "ConsoleWriter.h"
#include "stdio.h"

ConsoleWriter::ConsoleWriter(Mode mode)
{
	_mode = mode;
}

ConsoleWriter::~ConsoleWriter()
{
	const char escape[1] = {  };
	fwrite(escape, 1, 1, stdout);


	_mode = UnknownMode;
}

void ConsoleWriter::WriteInfo(const char* message)
{
	WriteMessage(InfoMessage, message);
}

void ConsoleWriter::WriteError(const char* message)
{
	WriteMessage(ErrorMessage, message);
}

void ConsoleWriter::ClearColor()
{
	SetColor(ClearAnsiColor);
}

void ConsoleWriter::SetColor(const char* color)
{
	WriteEscape();
	printf(color);
}

void ConsoleWriter::WriteMessage(MessageType messageType, const char* message)
{
	int isAnsi;
	const char *prefix, *color;
	switch (messageType)
	{
		case ErrorMessage:
			prefix = ErrorPrefix;
			color = ErrorColor;
			break;

		default:
			prefix = InfoPrefix;
			color = InfoColor;
	}

	if (isAnsi = IsAnsiMode()) SetColor(color);

	printf("[%s]", prefix);

	if (isAnsi) ClearColor();

	printf(" %s\n", message);
}

int ConsoleWriter::IsAnsiMode()
{
	return _mode == AnsiEscaped;
}

void ConsoleWriter::WriteEscape()
{
	fwrite(AnsiEscape, 1, 2, stdout);
}


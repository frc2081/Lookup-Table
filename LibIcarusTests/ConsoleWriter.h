#pragma once

class ConsoleWriter
{
public:
	enum Mode
	{
		UnknownMode = 0x0,
		AnsiEscaped = 0x1,
		ClearText = 0x2
	};

	ConsoleWriter(Mode mode);
	~ConsoleWriter();

	void WriteInfo(const char* message);
	void WriteError(const char* message);

private:
	Mode _mode;

	const char AnsiEscape[2] = { 0x1b, 0x5B };
	const char* ClearAnsiColor = "0m";

	const char* InfoPrefix = "Info";
	const char* InfoColor = "1;32m";

	const char* ErrorPrefix = "Error";
	const char* ErrorColor = "1;31m";

	enum MessageType
	{
		UnknownMessage = 0x0,
		InfoMessage = 0x1,
		ErrorMessage = 0x2
	};

	void ClearColor();
	void SetColor(const char* color);
	void WriteMessage(MessageType messageType, const char* message);
	int IsAnsiMode();
	void WriteEscape();
};

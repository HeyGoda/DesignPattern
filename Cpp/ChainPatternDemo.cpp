#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


class AbstractLogger
{
public:
	static const int INFO = 1;
	static const int DEBUG = 2;
	static const int ERROR = 3;
protected:
	int level;
	AbstractLogger *nextLogger = NULL;

public:	
	void setNextLogger(AbstractLogger *nextLogger)
	{
		this->nextLogger = nextLogger;
	}

	void logMessage(int level, string message)
	{
		if (this->level <= level)
		{
			write(message);
		}
		if (nextLogger != NULL)
		{
			nextLogger->logMessage(level, message);
		}
	}

protected:
	virtual void write(string message) = 0;
};

class ConsoleLogger: public AbstractLogger
{
public:
	ConsoleLogger(int level)
	{
		this->level = level;
	}

protected:
	void write(string message)
	{
		cout << "Standard Console::Logger: " << message << endl;
	}
};

class ErrorLogger: public AbstractLogger
{
public:
	ErrorLogger(int level)
	{
		this->level = level;
	}

protected:
	void write(string message)
	{
		cout << "Error Console::Logger: " << message << endl;
	}
};

class FileLogger: public AbstractLogger
{
public:
	FileLogger(int level)
	{
		this->level = level;
	}

protected:
	void write(string message)
	{
		cout << "File::Logger: " << message << endl;
	}
};

static AbstractLogger* getChainOfLoggers()
{
	AbstractLogger *errorLogger = new ErrorLogger(AbstractLogger::ERROR);
	AbstractLogger *fileLogger = new FileLogger(AbstractLogger::DEBUG);
	AbstractLogger *consoleLogger = new ConsoleLogger(AbstractLogger::INFO);
	
	errorLogger->setNextLogger(fileLogger);
	fileLogger->setNextLogger(consoleLogger);
	
	return errorLogger;
}

int main(int argc, char** argv)
{
	AbstractLogger *loggerChain = getChainOfLoggers();

	loggerChain->logMessage(AbstractLogger::INFO, "This is an information.");
	loggerChain->logMessage(AbstractLogger::DEBUG, "This is an debug level information.");
	loggerChain->logMessage(AbstractLogger::ERROR, "This is an error information.");

	return 0;
}


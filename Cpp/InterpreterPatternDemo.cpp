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


class Expression
{
public:
	virtual bool interpreter(string context) = 0;
};

class TerminalExpression: public Expression
{
private:
	string data;

public:
	TerminalExpression(string data)
	{
		this->data = data;
	}

	bool interpreter(string context)
	{
		if (context.find(data) != string::npos)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class OrExpression: public Expression
{
private:
	Expression *expr1 = NULL;
	Expression *expr2 = NULL;

public:
	OrExpression(Expression *expr1, Expression *expr2)
	{
		this->expr1 = expr1;
		this->expr2 = expr2;
	}

	bool interpreter(string context)
	{
		return expr1->interpreter(context) || expr2->interpreter(context);
	}
};

class AndExpression: public Expression
{
private:
	Expression *expr1 = NULL;
	Expression *expr2 = NULL;

public:
	AndExpression(Expression *expr1, Expression *expr2)
	{
		this->expr1 = expr1;
		this->expr2 = expr2;
	}

	bool interpreter(string context)
	{
		return expr1->interpreter(context) && expr2->interpreter(context);
	}
};

static Expression* getMaleExpression()
{
	Expression *robert = new TerminalExpression("Robert");
	Expression *john = new TerminalExpression("John");
	return new OrExpression(robert, john);
}

static Expression* getMarriedWomanExpression()
{
	Expression *julie = new TerminalExpression("Julie");
	Expression *married = new TerminalExpression("Married");
	return new AndExpression(julie, married);
}

int main(int argc, char** argv)
{
	Expression *isMale = getMaleExpression();
	Expression *isMarriedWoman = getMarriedWomanExpression();

	cout << "John is male? " << isMale->interpreter("John") << endl;
	cout << "Julie is a married women? " << isMarriedWoman->interpreter("Married Julie") << endl;

	return 0;
}


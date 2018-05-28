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

class State;
class Context
{
private:
	State *state;

public:
	Context()
	{
		state = NULL;
	}

	void setState(State *state)
	{
		this->state = state;
	}

	State* getState()
	{
		return state;
	}
};

class State
{
public:
	virtual void doAction(Context *context) = 0;
	virtual string toString() = 0;
};

class StartState: public State
{
public:
	void doAction(Context *context)
	{
		cout << "Player is in start state" << endl;
		context->setState(this);
	}

	string toString()
	{
		return "Start State";
	}
};

class StopState: public State
{
public:
	void doAction(Context *context)
	{
		cout << "Player is in stop state" << endl;
		context->setState(this);
	}

	string toString()
	{
		return "Stop State";
	}
};

int main(int argc, char** argv)
{
	Context *context = new Context();
	
	StartState *startState = new StartState();
	startState->doAction(context);
	cout << context->getState()->toString() << endl;
	
	StopState *stopState = new StopState();
	stopState->doAction(context);
	cout << context->getState()->toString() << endl;
	
	return 0;
}


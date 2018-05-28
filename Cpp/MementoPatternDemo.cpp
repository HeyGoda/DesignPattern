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


class Memento
{
private:
	string state;

public:
	Memento(string state)
	{
		this->state = state;
	}

	string getState()
	{
		return state;
	}
};

class Originator
{
private:
	string state;

public:
	void setState(string state)
	{
		this->state = state;
	}

	string getState()
	{
		return state;
	}

	Memento* saveStateToMemento()
	{
		return new Memento(state);
	}

	void getStateFromMemento(Memento *memento)
	{
		state = memento->getState();
	}
};

class CareTaker
{
private:
	vector<Memento*> mementoList;

public:
	void add(Memento *state)
	{
		mementoList.push_back(state);
	}

	Memento* get(int index)
	{
		return mementoList.at(index);
	}
};


int main(int argc, char** argv)
{
	Originator *originator = new Originator();
	CareTaker *careTaker = new CareTaker();

	originator->setState("State #1");
	originator->setState("State #2");
	careTaker->add(originator->saveStateToMemento());
	originator->setState("State #3");
	careTaker->add(originator->saveStateToMemento());
	originator->setState("State #4");

	cout << "Current State: " << originator->getState() << endl;

	originator->getStateFromMemento(careTaker->get(0));
	cout << "First saved State: " << originator->getState() << endl;
	originator->getStateFromMemento(careTaker->get(1));
	cout << "Second saved State: " << originator->getState() << endl;

	return 0;
}


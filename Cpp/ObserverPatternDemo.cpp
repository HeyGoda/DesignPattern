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

class Observer; //类Subject和Observer相互引用，需要先声明其中一个才能在另一个类中使用
class Subject
{
private:
	vector<Observer*> observers;
	int state;

public:
	int getState()
	{
		return state;
	}
	void setState(int state)
	{
		this->state = state;
		notifyAllObservers();
	}

	void attach(Observer *observer);
	void notifyAllObservers();
};

class Observer
{
protected:
	Subject *subject;
public:
	virtual void update() = 0;
};

void Subject::attach(Observer *observer)
{
	observers.push_back(observer);
}

void Subject::notifyAllObservers()
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers.at(i)->update();
	}
}

class BinaryObserver: public Observer
{
public:
	BinaryObserver(Subject *subject)
	{
		this->subject = subject;
		this->subject->attach(this);
	}

	void update()
	{
		cout << "Binary String: "
		     << setbase(2) << subject->getState() << endl;
	}
};

class OctalObserver: public Observer
{
public:
	OctalObserver(Subject *subject)
	{
		this->subject = subject;
		this->subject->attach(this);
	}

	void update()
	{
		cout << "Octal String: "
		     << setbase(8) << subject->getState() << endl;
	}
};

class HexaObserver: public Observer
{
public:
	HexaObserver(Subject *subject)
	{
		this->subject = subject;
		this->subject->attach(this);
	}

	void update()
	{
		cout << "Hex String: "
		     << setbase(16) << subject->getState() << endl;
	}
};

int main(int argc, char** argv)
{
	Subject *subject = new Subject();

	new HexaObserver(subject);
	new OctalObserver(subject);
	new BinaryObserver(subject);

	cout << "First state change: 15" << endl;
	subject->setState(15);
	cout << endl << "Second state change: 10" << endl;
	subject->setState(10);

	return 0;
}


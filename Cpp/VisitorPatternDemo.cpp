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

class ComputerPartVisitor;
class ComputerPart
{
public:
	virtual void accept(ComputerPartVisitor *computerPartVisitor) = 0;
};

class Keyboard;
class Mouse;
class Monitor;
class Computer;

class ComputerPartVisitor
{
public:
	virtual void visit(Computer *computer) = 0;
	virtual void visit(Mouse *mouse) = 0;
	virtual void visit(Keyboard *keyboard) = 0;
	virtual void visit(Monitor *monitor) = 0;
};

class Keyboard: public ComputerPart
{
public:
	void accept(ComputerPartVisitor *computerPartVisitor)
	{
		computerPartVisitor->visit(this);
	}
};

class Monitor: public ComputerPart
{
public:
	void accept(ComputerPartVisitor *computerPartVisitor)
	{
		computerPartVisitor->visit(this);
	}
};

class Mouse: public ComputerPart
{
public:
	void accept(ComputerPartVisitor *computerPartVisitor)
	{
		computerPartVisitor->visit(this);
	}
};

class Computer: public ComputerPart
{
private:
	ComputerPart* parts[3];

public:
	Computer()
	{
		parts[0] = new Mouse();
		parts[1] = new Keyboard();
		parts[2] = new Monitor();
	}

	void accept(ComputerPartVisitor *computerPartVisitor)
	{
		for (size_t i = 0; i < sizeof(parts)/sizeof(parts[0]); i++)
		{
			parts[i]->accept(computerPartVisitor);
		}
		computerPartVisitor->visit(this);
	}
};

class ComputerPartDisplayVisitor: public ComputerPartVisitor
{
public:
	void visit(Computer *computer)
	{
		cout << "Displaying Computer." << endl;
	}

	void visit(Mouse *mouse)
	{
		cout << "Displaying Mouse." << endl;
	}

	void visit(Keyboard *keyboard)
	{
		cout << "Displaying Keyboard." << endl;
	}

	void visit(Monitor *monitor)
	{
		cout << "Displaying Monitor" << endl;
	}
};


int main(int argc, char** argv)
{
	ComputerPart *computer = new Computer();
	computer->accept(new ComputerPartDisplayVisitor());

	return 0;
}


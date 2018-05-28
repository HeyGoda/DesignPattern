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

class AbstractCustomer
{
protected:
	string name;
public:
	virtual bool isNil() = 0;
	virtual string getName() = 0;
};

class RealCustomer: public AbstractCustomer
{
public:
	RealCustomer(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}

	bool isNil()
	{
		return false;
	}
};

class NullCustomer: public AbstractCustomer
{
public:
	string getName()
	{
		return "Not Available in Customer Database";
	}

	bool isNil()
	{
		return true;
	}
};

class CustomerFactory
{
public:
	static const string names[3];
	static AbstractCustomer* getCustomer(string name)
	{
		for (unsigned i = 0; i < sizeof(names)/sizeof(names[0]); i++)
		{
			if (names[i].compare(name) == 0)
			{
				return new RealCustomer(name);
			}
		}
		return new NullCustomer();
	}
};
const string CustomerFactory::names[3] = {"Rob", "Joe", "Julie"};

int main(int argc, char** argv)
{
	AbstractCustomer *customer1 = CustomerFactory::getCustomer("Rob");
	AbstractCustomer *customer2 = CustomerFactory::getCustomer("Bob");
	AbstractCustomer *customer3 = CustomerFactory::getCustomer("Julie");
	AbstractCustomer *customer4 = CustomerFactory::getCustomer("Laura");
	
	cout << "Customers" << endl;
	cout << customer1->getName() << endl;
	cout << customer2->getName() << endl;
	cout << customer3->getName() << endl;
	cout << customer4->getName() << endl;
	
	return 0;
}


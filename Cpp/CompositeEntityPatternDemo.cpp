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


class DependentObject1
{
private:
	string data;

public:
	void setData(string data)
	{
		this->data = data;
	}

	string getData()
	{
		return data;
	}
};

class DependentObject2
{
private:
	string data;

public:
	void setData(string data)
	{
		this->data = data;
	}

	string getData()
	{
		return data;
	}
};

class CoarseGrainedObject
{
private:
	DependentObject1 *do1 = new DependentObject1();
	DependentObject2 *do2 = new DependentObject2();

public:
	void setData(string data1, string data2)
	{
		do1->setData(data1);
		do2->setData(data2);
	}

	string* getData()
	{
		string *ss = new string[2];
		ss[0] = do1->getData();
		ss[1] = do2->getData();
		return ss;
	}
};

class CompositeEntity
{
private:
	CoarseGrainedObject *cgo = new CoarseGrainedObject();

public:
	void setData(string data1, string data2)
	{
		cgo->setData(data1, data2);
	}

	string* getData()
	{
		return cgo->getData();
	}
};

class Client
{
private:
	CompositeEntity *compositeEntity = new CompositeEntity();

public:
	void printData()
	{
		for (int i = 0; i < 2; i++)
		{
			cout << "Data: " << compositeEntity->getData()[i] << endl;
		}
	}

	void setData(string data1, string data2)
	{
		compositeEntity->setData(data1, data2);
	}
};

int main(int argc, char** argv)
{
	Client *client = new Client();
	
	client->setData("Test", "Data");
	client->printData();
	client->setData("Second Test", "Data1");
	client->printData();

	return 0;
}


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


class Iterator
{
public:
	virtual bool hasNext() = 0;
	virtual string next() = 0;
};

class Container
{
public:
	virtual Iterator* getIterator() = 0;
};

class NameRepository: public Container
{
public:
	static const string names[4];
	
	Iterator* getIterator()
	{
		return new NameIterator();
	}

private:
	class NameIterator: public Iterator
	{
	private:
		unsigned index = 0;
		
	public:
		bool hasNext()
		{
			if (index < (sizeof(names)/sizeof(names[0])))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		string next()
		{
			if (this->hasNext())
			{
				return names[index++];
			}
			else
			{
				return NULL;
			}
		}
	};
};

const string NameRepository::names[4] = {"Robert", "John", "Julie", "Lora"};


int main(int argc, char** argv)
{
	NameRepository *namesRepository = new NameRepository();
	
	for (Iterator *iter = namesRepository->getIterator(); iter->hasNext();)
	{
		string name = iter->next();
		cout << "Name: " << name << endl;
	}

	return 0;
}


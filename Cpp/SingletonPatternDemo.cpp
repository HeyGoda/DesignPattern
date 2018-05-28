#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class SingleObject
{
private:
	static SingleObject *instance;
	SingleObject()
	{
		instance = new SingleObject();
	}

public:
	static SingleObject* getInstance()
	{
		return instance;
	}

	void showMessage()
	{
		cout << "Hello World!" << endl;
	}
};

int main(int argc, char** argv)
{
	//SingleObject *object = new SingleObject();
	SingleObject *object = SingleObject::getInstance();
	object->showMessage();

	return 0;
}

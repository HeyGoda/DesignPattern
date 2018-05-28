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


class Image
{
public:
	virtual void display() = 0;
};

class RealImage: public Image
{
private:
	string fileName;
	void loadFromDisk(string fileName)
	{
		cout << "Loading " << endl;
	}

public:
	RealImage(string fileName)
	{
		this->fileName = fileName;
		loadFromDisk(fileName);
	}

	void display()
	{
		cout << "Displaying " << fileName << endl;
	}
};

class ProxyImage: public Image
{
private:
	RealImage *realImage = NULL;
	string fileName;

public:
	ProxyImage(string fileName)
	{
		this->fileName = fileName;
	}
	
	void display()
	{
		if (realImage == NULL)
		{
			realImage = new RealImage(fileName);
		}
		realImage->display();
	}
};

int main(int argc, char** argv)
{
	Image *image = new ProxyImage("test.jpg");
	
	image->display();
	cout << endl;
	image->display();

	return 0;
}


#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Shape
{
public:
	virtual void draw() = 0;
};

class Rectangle: public Shape
{
public:
	void draw()
	{
		cout << "Inside Rectangle::draw() method." << endl;
	}
};

class Square: public Shape
{
public:
	void draw()
	{
		cout << "Inside Square::draw() method." << endl;
	}
};

class Circle: public Shape
{
public:
	void draw()
	{
		cout << "Inside Circle::draw() method." << endl;
	}
};

class ShapeFactory
{
public:
	Shape* getShape(string shapeType)
	{
		if(shapeType.empty())
		{
			return NULL;
		}
		
		if (shapeType.compare("CIRCLE") == 0)
		{
			return new Circle();
		}
		else if (shapeType.compare("RECTANGLE") == 0)
		{
			return new Rectangle();
		}
		else if (shapeType.compare("SQUARE") == 0)
		{
			return new Square();
		}
		
		return NULL;
	}
};

int main(int argc, char** argv)
{
	ShapeFactory *shapeFactory = new ShapeFactory();
	
	Shape *shape1 = shapeFactory->getShape("CIRCLE");
	shape1->draw();
	
	Shape *shape2 = shapeFactory->getShape("RECTANGLE");
	shape2->draw();
	
	Shape *shape3 = shapeFactory->getShape("SQUARE");
	shape3->draw();
	
	return 0;
}

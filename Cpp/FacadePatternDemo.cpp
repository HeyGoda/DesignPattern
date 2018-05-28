#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <sstream>

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
		cout << "Rectangle::draw()" << endl;
	}
};

class Circle: public Shape
{
public:
	void draw()
	{
		cout << "Circle::draw()" << endl;
	}
};

class Square: public Shape
{
public:
	void draw()
	{
		cout << "Square::draw()" << endl;
	}
};

class ShapeMaker
{
private:
	Shape *circle, *rectangle, *square;

public:
	ShapeMaker()
	{
		circle = new Circle();
		rectangle = new Rectangle();
		square = new Square();
	}
	
	void drawCircle()
	{
		circle->draw();
	}
	
	void drawRectangle()
	{
		rectangle->draw();
	}
	
	void drawSquare()
	{
		square->draw();
	}
};

int main(int argc, char** argv)
{
	ShapeMaker *shapeMaker = new ShapeMaker();
	
	shapeMaker->drawCircle();
	shapeMaker->drawRectangle();
	shapeMaker->drawSquare();

	return 0;
}


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
		cout << "Shape: Rectangle" << endl;
	}
};

class Circle: public Shape
{
public:
	void draw()
	{
		cout << "Shape: Circle" << endl;
	}
};

class ShapeDecorator: public Shape
{
protected:
	Shape *decoratedShape;

public:
	ShapeDecorator(Shape *decoratedShape)
	{
		this->decoratedShape = decoratedShape;
	}

	void draw()
	{
		decoratedShape->draw();
	}
};

class RedShapeDecorator: public ShapeDecorator
{
public:
	RedShapeDecorator(Shape *decoratedShape)
		: ShapeDecorator(decoratedShape)
	{
	}

	void draw()
	{
		decoratedShape->draw();
		setRedBorder(decoratedShape);
	}

private:
	void setRedBorder(Shape *decoratedShape)
	{
		cout << "Border Color: Red" << endl;
	}
};

int main(int argc, char** argv)
{
	Shape *circle = new Circle();
	Shape *redCircle = new RedShapeDecorator(new Circle());
	Shape *redRectangle = new RedShapeDecorator(new Rectangle());
	
	cout << "Circle with normal border" << endl;
	circle->draw();
	
	cout << "\nCircle of red border" << endl;
	redCircle->draw();
	
	cout << "\nRectangle of redCircle border" << endl;
	redRectangle->draw();

	return 0;
}


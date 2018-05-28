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
		cout << "Inside Square::deaw() method." << endl;
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


class Color
{
public:
	virtual void fill() = 0;
};

class Red: public Color
{
public:
	void fill()
	{
		cout << "Inside Red::fill() method." << endl;
	}
};

class Green: public Color
{
public:
	void fill()
	{
		cout << "Inside Green::fill() method." << endl;
	}
};

class Blue: public Color
{
public:
	void fill()
	{
		cout << "Inside Blue::fill() method." << endl;
	}
};


class AbstractFactory
{
public:
	virtual Color* getColor(string color) = 0;
	virtual Shape* getShape(string shpe) = 0;
};

class ShapeFactory: public AbstractFactory
{
public:
	Shape* getShape(string shapeType)
	{
		if (shapeType.empty())
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

	Color* getColor(string color)
	{
		return NULL;
	}
};

class ColorFactory: public AbstractFactory
{
public:
	Shape* getShape(string shapeType)
	{
		return NULL;
	}
	Color* getColor(string color)
	{
		if (color.empty())
		{
			return NULL;
		}

		if (color.compare("RED") == 0)
		{
			return new Red();
		}
		else if (color.compare("GREEN") == 0)
		{
			return new Green();
		}
		else if (color.compare("BLUE") == 0)
		{
			return new Blue();
		}

		return NULL;
	}
};

class FactoryProducer
{
public:
	static AbstractFactory* getFactory(string choice)
	{
		if (choice.compare("SHAPE") == 0)
		{
			return new ShapeFactory();
		}
		else if (choice.compare("COLOR") == 0)
		{
			return new ColorFactory();
		}
		return NULL;
	}
};

int main(int argc, char** argv)
{
	AbstractFactory *shapeFactory = FactoryProducer::getFactory("SHAPE");

	Shape *shape1 = shapeFactory->getShape("CIRCLE");
	shape1->draw();

	Shape *shape2 = shapeFactory->getShape("RECTANGLE");
	shape2->draw();

	Shape *shape3 = shapeFactory->getShape("SQUARE");
	shape3->draw();

	AbstractFactory *colorFactory = FactoryProducer::getFactory("COLOR");

	Color *color1 = colorFactory->getColor("RED");
	color1->fill();
	
	Color *color2 = colorFactory->getColor("GREEN");
	color2->fill();
	
	Color *color3 = colorFactory->getColor("BLUE");
	color3->fill();

	return 0;
}

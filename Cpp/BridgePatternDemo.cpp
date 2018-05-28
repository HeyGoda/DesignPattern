#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class DrawAPI
{
public:
	virtual void drawCircle(int radius, int x, int y) = 0;
};

class RedCircle: public DrawAPI
{
public:
	void drawCircle(int radius, int x, int y)
	{
		cout << "Drawing Circle[ color: red, radius: "
		     << radius << ", x: " << x << ", y: " << y << " ]" << endl;
	}
};

class GreenCircle: public DrawAPI
{
public:
	void drawCircle(int radius, int x, int y)
	{
		cout << "Drawing Circle[ color: green, radius: "
		     << radius << ", x: " << x << ", y: " << y << " ]" << endl;
	}
};

class Shape
{
protected:
	DrawAPI *drawAPI;
	Shape(DrawAPI *drawAPI)
	{
		this->drawAPI = drawAPI;
	}

public:
	virtual void draw() = 0;
};

class Circle: public Shape
{
private:
	int x, y, radius;

public:
	Circle(int x, int y, int radius, DrawAPI *drawAPI):
		Shape(drawAPI)
	{
		this->x = x;
		this->y = y;
		this->radius = radius;
	}
	
	void draw()
	{
		drawAPI->drawCircle(radius, x, y);
	}
};

int main(int argc, char** argv)
{
	Shape *redCircle = new Circle(100, 100, 10, new RedCircle());
	Shape *greenCircle = new Circle(100, 100, 10, new GreenCircle());
	
	redCircle->draw();
	greenCircle->draw();
	
	return 0;
}

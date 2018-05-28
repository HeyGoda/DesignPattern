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

#include <ext/hash_map>
using namespace __gnu_cxx;
namespace __gnu_cxx
{
    template<> struct hash< std::string >
    {
        size_t operator()( const std::string& x ) const
        {
            return hash< const char* >()( x.c_str() );
        }
    };

    template<> struct hash<long long>
    {
        size_t operator()(long long x) const
        {
            return x;
        }
    };
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


class Shape
{
public:
	virtual void draw() = 0;
};

class Circle: public Shape
{
private:
	string color;
	int x, y, radius;

public:
	Circle(string color)
	{
		this->color = color;
	}

	void setX(int x)
	{
		this->x = x;
	}

	void setY(int y)
	{
		this->y = y;
	}

	void setRadius(int radius)
	{
		this->radius = radius;
	}

	void draw()
	{
		cout << "Circle: Draw() [Color: " << color
		     << ", x: " << x
		     << ", y: " << y
		     << ", radius: " << radius << endl;
	}
};

class ShapeFactory
{
public:
	static hash_map<string, Shape*> circleMap;
	
	static Shape* getCircle(string color)
	{
		Circle *circle = NULL;
		
		if (circleMap.find(color) != circleMap.end())
		{
			circle = (Circle*)circleMap[color];
		}
		else
		{
			circle = new Circle(color);
			circleMap.insert(pair<string, Shape*>(color, circle));
			cout << "Creating circle of color: " << color << endl;
		}
		
		return circle;
	}
};

//必须给出静态成员的定义，否则编译报错 
hash_map<string, Shape*> ShapeFactory::circleMap;

static const string colors[] = 
	  {"Red", "Green", "Blue", "White", "Black"};

static string getRandomColor()
{
	return colors[(int)(rand()%(sizeof(colors)/sizeof(colors[0])))];
}

static int getRandomX()
{
	return (int)(rand()%100);
}

static int getRandomY()
{
	return (int)(rand()%100);
}

int main(int argc, char** argv)
{
	srand((unsigned)time(NULL));
	
	for (int i = 0; i < 20; i++)
	{
		Circle *circle = (Circle*)ShapeFactory::getCircle(getRandomColor());
		circle->setX(getRandomX());
		circle->setY(getRandomY());
		circle->setRadius(100);
		circle->draw();
	}
	
	return 0;
}


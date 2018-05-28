#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

//Interface
class Packing
{
public:
	virtual string pack() = 0;
};

class Wrapper: public Packing
{
public:
	string pack()
	{
		return "Wrapper";
	}
};

class Bottle: public Packing
{
public:
	string pack()
	{
		return "Bottle";
	}
};

//Interface
class Item
{
public:
	virtual string name() = 0;
	virtual Packing* packing() = 0;
	virtual float price() = 0;
};
//Abstract class
class Burger: public Item
{
public:
	Packing* packing()
	{
		return new Wrapper();
	}

	virtual float price() = 0;
};

class ColdDrink: public Item
{
public:
	Packing* packing()
	{
		return new Bottle();
	}

	virtual float price() = 0;
};

class VegBurger: public Burger
{
public:
	float price()
	{
		return 25.0f;
	}

	string name()
	{
		return "Veg Burger";
	}
};

class ChickenBurger: public Burger
{
public:
	float price()
	{
		return 50.5f;
	}

	string name()
	{
		return "Chicken Burger";
	}
};

class Coke: public ColdDrink
{
public:
	float price()
	{
		return 30.0f;
	}

	string name()
	{
		return "Coke";
	}
};

class Pepsi: public ColdDrink
{
public:
	float price()
	{
		return 35.0f;
	}

	string name()
	{
		return "Pepsi";
	}
};

class Meal
{
private:
	vector<Item*> items;

public:
	void addItem(Item *item)
	{
		items.push_back(item);
	}

	float getCost()
	{
		float cost = 0.0f;
		for (size_t i = 0; i < items.size(); i++)
		{
			cost += items.at(i)->price();
		}
		return cost;
	}

	void showItems()
	{
		for (size_t i = 0; i < items.size(); i++)
		{
			cout << "Item : " << items.at(i)->name();
			cout << ", Packing : " << items.at(i)->packing()->pack();
			cout << ", Price : " << items.at(i)->price() << endl;
		}
	}
};

class MealBuilder
{
public:
	Meal* prepareVegMeal()
	{
		Meal *meal = new Meal();
		meal->addItem(new VegBurger());
		meal->addItem(new Coke());
		
		return meal;
	}
	
	Meal* prepareNonVegMeal()
	{
		Meal *meal = new Meal();
		meal->addItem(new ChickenBurger());
		meal->addItem(new Pepsi());
		
		return meal;
	}
};

int main(int argc, char** argv)
{
	MealBuilder *mealBuilder = new MealBuilder();
	
	Meal *vegMeal = mealBuilder->prepareVegMeal();
	cout << "Veg Meal" << endl;
	vegMeal->showItems();
	cout << "Total Cost: " << vegMeal->getCost() << endl;
	cout << endl;
	
	Meal *nonVegMeal = mealBuilder->prepareNonVegMeal();
	cout << "Non-Veg Meal" << endl;
	nonVegMeal->showItems();
	cout << "Total Cost: " << nonVegMeal->getCost() << endl;

	return 0;
}

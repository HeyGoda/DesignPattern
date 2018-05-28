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


class Order
{
public:
	virtual void execute() = 0;
};

class Stock
{
private:
	string name;
	int quantity;

public:
	Stock()
	{
		name = "ABC";
		quantity = 10;
	}

	void buy()
	{
		cout << "Stock [Name: " << name
		     << ", Quantity: " << quantity
		     << "] bought" << endl;
	}

	void sell()
	{
		cout << "Stock [Name: " << name
		     << ", Quantity: " << quantity
		     << "] sold" << endl;;
	}
};

class BuyStock: public Order
{
private:
	Stock *abcStock;

public:
	BuyStock(Stock *abcStock)
	{
		this->abcStock = abcStock;
	}

	void execute()
	{
		abcStock->buy();
	}
};

class SellStock: public Order
{
private:
	Stock *abcStock;

public:
	SellStock(Stock *abcStock)
	{
		this->abcStock = abcStock;
	}

	void execute()
	{
		abcStock->sell();
	}
};

class Broker
{
private:
	vector<Order*> orderList;

public:
	void takeOrder(Order *order)
	{
		orderList.push_back(order);
	}

	void placeOrder()
	{
		for (size_t i = 0; i < orderList.size(); i++)
		{
			orderList.at(i)->execute();
		}
		orderList.clear();
	}
};

int main(int argc, char** argv)
{
	Stock *abcStock = new Stock();
	
	BuyStock *buyStockOrder = new BuyStock(abcStock);
	SellStock *sellStockOrder = new SellStock(abcStock);
	
	Broker *broker = new Broker();
	broker->takeOrder(buyStockOrder);
	broker->takeOrder(sellStockOrder);
	broker->placeOrder();

	return 0;
}


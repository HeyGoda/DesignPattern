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


class HomeView
{
public:
	void show()
	{
		cout << "Displaying Home Page" << endl;
	}
};

class StudentView
{
public:
	void show()
	{
		cout << "Displaying Student Page" << endl;
	}
};

class Dispatcher
{
private:
	StudentView *studentView;
	HomeView *homeView;

public:
	Dispatcher()
	{
		studentView = new StudentView();
		homeView = new HomeView();
	}

	void dispatch(string request)
	{
		if (request.compare("STUDENT") == 0)
		{
			studentView->show();
		}
		else
		{
			homeView->show();
		}
	}
};

class FrontController
{
private:
	Dispatcher *dispatcher;

	bool isAuthenticUser()
	{
		cout << "User is authenticated successfully." << endl;
		return true;
	}

	void trackRequest(string request)
	{
		cout << "Page requested: " << request << endl;
	}

public:
	FrontController()
	{
		dispatcher = new Dispatcher();
	}

	void dispatchRequest(string request)
	{
		trackRequest(request);
		if (isAuthenticUser())
		{
			dispatcher->dispatch(request);
		}
	}
};


int main(int argc, char** argv)
{
	FrontController *frontController = new FrontController();
	
	frontController->dispatchRequest("HOME");
	frontController->dispatchRequest("STUDENT");

	return 0;
}


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


class Filter
{
public:
	virtual void execute(string request) = 0;
};

class AuthenticationFilter: public Filter
{
public:
	void execute(string request)
	{
		cout << "Authenticating request: " << request << endl;
	}
};

class DebugFilter: public Filter
{
public:
	void execute(string request)
	{
		cout << "request log: " << request << endl;
	}
};

class Target
{
public:
	void execute(string request)
	{
		cout << "Executing request: " << request << endl;
	}
};

class FilterChain
{
private:
	vector<Filter*> *filters = new vector<Filter*>();
	Target *target;

public:
	void addFilter(Filter *filter)
	{
		filters->push_back(filter);
	}

	void execute(string request)
	{
		for (size_t i = 0; i < filters->size(); i++)
		{
			filters->at(i)->execute(request);
		}
		target->execute(request);
	}

	void setTarget(Target *target)
	{
		this->target = target;
	}
};

class FilterManager
{
private:
	FilterChain *filterChain;

public:
	FilterManager(Target *target)
	{
		filterChain = new FilterChain();
		filterChain->setTarget(target);
	}

	void setFilter(Filter *filter)
	{
		filterChain->addFilter(filter);
	}

	void filterRequest(string request)
	{
		filterChain->execute(request);
	}
};

class Client
{
private:
	FilterManager *filterManager;

public:
	void setFilterManager(FilterManager *filterManager)
	{
		this->filterManager = filterManager;
	}

	void sendRequest(string request)
	{
		filterManager->filterRequest(request);
	}
};


int main(int argc, char** argv)
{
	FilterManager *filterManager = new FilterManager(new Target());
	filterManager->setFilter(new AuthenticationFilter());
	filterManager->setFilter(new DebugFilter());

	Client *client = new Client();
	client->setFilterManager(filterManager);
	client->sendRequest("HOME");

	return 0;
}


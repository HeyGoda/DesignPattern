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


class Service
{
public:
	virtual string getName() = 0;
	virtual void execute() = 0;
};

class Service1: public Service
{
public:
	void execute()
	{
		cout << "Executing Service1" << endl;
	}

	string getName()
	{
		return "Service1";
	}
};

class Service2: public Service
{
public:
	void execute()
	{
		cout << "Executing Service2" << endl;
	}

	string getName()
	{
		return "Service2";
	}
};

class InitialContext
{
public:
	Service* lookup(string jndiName)
	{
		if (jndiName.compare("SERVICE1") == 0)
		{
			cout << "Looking up and creating a new Service1 object" << endl;
			return new Service1();
		}
		else if (jndiName.compare("SERVICE2") == 0)
		{
			cout << "Looking up and creating a new Service2 object" << endl;
			return new Service2();
		}

		return NULL;
	}
};

class Cache
{
private:
	vector<Service*> *services;

public:
	Cache()
	{
		services = new vector<Service*>();
	}

	Service* getService(string serviceName)
	{
		for (size_t i = 0; i < services->size(); i++)
		{
			if (services->at(i)->getName().compare(serviceName) == 0)
			{
				cout << "Returning cached " << serviceName << " object" << endl;
				return services->at(i);
			}
		}
		return NULL;
	}

	void addService(Service *newService)
	{
		bool exists = false;
		for (size_t i = 0; i < services->size(); i++)
		{
			if (services->at(i)->getName().compare(newService->getName()) == 0)
			{
				exists = true;
			}
		}
		if (!exists)
		{
			services->push_back(newService);
		}
	}
};

class ServiceLocator
{
private:
	static Cache *cache;

public:
	static Service* getService(string jndiName)
	{
		Service *service = cache->getService(jndiName);
		if (service != NULL)
		{
			return service;
		}

		InitialContext *context = new InitialContext();
		Service *service1 = (Service*)context->lookup(jndiName);
		cache->addService(service1);
		return service1;
	}
};
Cache* ServiceLocator::cache = new Cache();

int main(int argc, char** argv)
{
	Service *service = ServiceLocator::getService("SERVICE1");
	service->execute();

	service = ServiceLocator::getService("SERVICE2");
	service->execute();

	service = ServiceLocator::getService("SERVICE1");
	service->execute();//结果错误 

	service = ServiceLocator::getService("SERVICE2"); 
	service->execute();//结果错误 

	return 0;
}


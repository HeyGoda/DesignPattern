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


class BusinessService
{
public:
	virtual void doProcessing() = 0;
};

class EJBService: public BusinessService
{
public:
	void doProcessing()
	{
		cout << "Processing task by invoking EJB Service" << endl;
	}
};

class JMSService: public BusinessService
{
public:
	void doProcessing()
	{
		cout << "Processin task by invoking JMS Service" << endl;
	}
};

class BusinessLookUp
{
public:
	BusinessService* getBusinessService(string serviceType)
	{
		if (serviceType.compare("EJB") == 0)
		{
			return new EJBService();
		}
		else
		{
			return new JMSService();
		}
	}
};

class BusinessDelegate
{
private:
	BusinessLookUp *lookupService = new BusinessLookUp();
	BusinessService *businessService;
	string serviceType;

public:
	void setServiceType(string serviceType)
	{
		this->serviceType = serviceType;
	}

	void doTask()
	{
		businessService = lookupService->getBusinessService(serviceType);
		businessService->doProcessing();
	}
};

class Client
{
private:
	BusinessDelegate *businessService;

public:
	Client(BusinessDelegate *businessService)
	{
		this->businessService = businessService;
	}

	void doTask()
	{
		businessService->doTask();
	}
};

int main(int argc, char** argv)
{
	BusinessDelegate *businessDelegate = new BusinessDelegate();
	businessDelegate->setServiceType("EJB");

	Client *client = new Client(businessDelegate);
	client->doTask();

	businessDelegate->setServiceType("JMS");
	client->doTask();

	return 0;
}


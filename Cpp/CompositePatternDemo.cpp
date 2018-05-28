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

class Employee
{
private:
	string name, dept;
	int salary;
	vector<Employee*> *subordinates;

public:
	Employee(string name, string dept, int sal)
	{
		this->name = name;
		this->dept = dept;
		this->salary = sal;
		subordinates = new vector<Employee*>;
	}

	void add(Employee *e)
	{
		subordinates->push_back(e);
	}

	void remove(Employee *e)
	{
		vector<Employee*>::iterator it = find(subordinates->begin(), subordinates->end(), e);
		if (it != subordinates->end())
		{
			subordinates->erase(it);
		}
	}

	vector<Employee*>* getSubordinates()
	{
		return subordinates;
	}

	string toString()
	{
		ostringstream oss;
		oss << "Employee: [ Name: " << name << ", dept: " << dept << ", salary: " << salary << " ]";
		return oss.str();
	}
};

int main(int argc, char** argv)
{
	Employee *CEO = new Employee("John", "CEO", 30000);
	Employee *headSales = new Employee("Robert", "Head Sales", 20000);
	Employee *headMarketing = new Employee("Michel", "Head Marketing", 20000);
	Employee *clerk1 = new Employee("Laura", "Marketing", 10000);
	Employee *clerk2 = new Employee("Bob", "Marketing", 10000);
	Employee *salesExecutive1 = new Employee("Richard", "Sales", 10000);
	Employee *salesExecutive2 = new Employee("Rob", "Sales", 10000);

	CEO->add(headSales);
	CEO->add(headMarketing);

	headSales->add(salesExecutive1);
	headSales->add(salesExecutive2);

	headMarketing->add(clerk1);
	headMarketing->add(clerk2);

	cout << CEO->toString() << endl;

	for (size_t i = 0; i < CEO->getSubordinates()->size(); i++)
	{
		Employee* ee = CEO->getSubordinates()->at(i);
		cout << "  " << ee->toString() << endl;
		for (size_t j = 0; j < ee->getSubordinates()->size(); j++)
		{
			cout << "    " << ee->getSubordinates()->at(i)->toString() << endl;
		}
	}

	return 0;
}


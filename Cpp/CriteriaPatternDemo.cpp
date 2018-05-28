#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Person
{
private:
	string name, gender, maritalStatus;

public:
	Person(string name, string gender, string maritalStatus)
	{
		this->name = name;
		this->gender = gender;
		this->maritalStatus = maritalStatus;
	}

	string getName()
	{
		return name;
	}

	string getGender()
	{
		return gender;
	}

	string getMaritalStatus()
	{
		return maritalStatus;
	}
};

class Criteria
{
public:
	virtual vector<Person*>* meetCriteria(vector<Person*> persons) = 0;
};

class CriteriaMale: public Criteria
{
public:
	vector<Person*>* meetCriteria(vector<Person*> persons)
	{
		vector<Person*> *malePersons = new vector<Person*>;
		for (size_t i = 0; i < persons.size(); i++)
		{
			if ((persons.at(i)->getGender().compare("MALE") == 0)
			        ||(persons.at(i)->getGender().compare("male") == 0))
			{
				malePersons->push_back(persons.at(i));
			}
		}
		return malePersons;
	}
};

class CriteriaFemale: public Criteria
{
public:
	vector<Person*>* meetCriteria(vector<Person*> persons)
	{
		vector<Person*> *femalePersons = new vector<Person*>;
		for (size_t i = 0; i < persons.size(); i++)
		{
			if ((persons.at(i)->getGender().compare("FEMALE") == 0)
			        ||(persons.at(i)->getGender().compare("female") == 0))
			{
				femalePersons->push_back(persons.at(i));
			}
		}
		return femalePersons;
	}
};

class CriteriaSingle: public Criteria
{
public:
	vector<Person*>* meetCriteria(vector<Person*> persons)
	{
		vector<Person*> *singlePersons = new vector<Person*>;
		for (size_t i = 0; i < persons.size(); i++)
		{
			if ((persons.at(i)->getMaritalStatus().compare("SINGLE") == 0)
			        ||(persons.at(i)->getMaritalStatus().compare("single") == 0))
			{
				singlePersons->push_back(persons.at(i));
			}
		}
		return singlePersons;
	}
};

class AndCriteria: public Criteria
{
private:
	Criteria *criteria, *otherCriteria;
public:
	AndCriteria(Criteria *criteria, Criteria *otherCriteria)
	{
		this->criteria = criteria;
		this->otherCriteria = otherCriteria;
	}
	
	vector<Person*>* meetCriteria(vector<Person*> persons)
	{
		vector<Person*> *firstCriteriaPersons = criteria->meetCriteria(persons);
		
		return otherCriteria->meetCriteria(*firstCriteriaPersons);
	}
};

class OrCriteria: public Criteria
{
private:
	Criteria *criteria, *otherCriteria;
public:
	OrCriteria(Criteria *criteria, Criteria *otherCriteria)
	{
		this->criteria = criteria;
		this->otherCriteria = otherCriteria;
	}
	
	vector<Person*>* meetCriteria(vector<Person*> persons)
	{
		vector<Person*> *firstCriteriaItems = criteria->meetCriteria(persons);
		vector<Person*> *otherCriteriaItems = otherCriteria->meetCriteria(persons);
		
		for (size_t i = 0; i < otherCriteriaItems->size(); i++)
		{
			vector<Person*>::iterator it;
			it = find(firstCriteriaItems->begin(), firstCriteriaItems->end(), otherCriteriaItems->at(i));
			if (it != firstCriteriaItems->end())
			{
				firstCriteriaItems->push_back(otherCriteriaItems->at(i));
			}
		}
		
		return firstCriteriaItems;
	}
};

static void printPersons(vector<Person*> *persons)
{
	for (size_t i = 0; i < persons->size(); i++)
	{
		cout << "Person : [ Name : " << persons->at(i)->getName()
		     << ", Gender : " << persons->at(i)->getGender()
		     << ", Marital Status : " << persons->at(i)->getMaritalStatus()
		     << " ]" << endl;
	}
}

int main(int argc, char** argv)
{
	vector<Person*> persons;
	
	persons.push_back(new Person("Robert", "MALE", "SINGLE"));
	persons.push_back(new Person("John", "MALE", "Married"));
	persons.push_back(new Person("Laura", "FEMALE", "Married"));
	persons.push_back(new Person("Diana", "FEMALE", "SINGLE"));
	persons.push_back(new Person("Bobby", "MALE", "SINGLE"));
	persons.push_back(new Person("Robert", "MALE", "SINGLE"));
	
	Criteria *male = new CriteriaMale();
	Criteria *female = new CriteriaFemale();
	Criteria *single = new CriteriaSingle();
	Criteria *singleMale = new AndCriteria(single, male);
	Criteria *singleOrFemale = new OrCriteria(single, female);
	
	cout << "Males: " << endl;
	printPersons(male->meetCriteria(persons));
	
	cout << "\nFemales: " << endl;
	printPersons(female->meetCriteria(persons));
	
	cout << "\nSingle Males: " << endl;
	printPersons(singleMale->meetCriteria(persons));
	
	cout << "\nSingle Or Females: " << endl;
	printPersons(singleOrFemale->meetCriteria(persons));
	
	return 0;
}


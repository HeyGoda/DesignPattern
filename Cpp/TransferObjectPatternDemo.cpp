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


class StudentVO
{
private:
	string name;
	int rollNo;

public:
	StudentVO(string name, int rollNo)
	{
		this->name = name;
		this->rollNo = rollNo;
	}

	string getName()
	{
		return name;
	}

	void setName(string name)
	{
		this->name = name;
	}

	int getRollNo()
	{
		return rollNo;
	}

	void setRollNo(int rollNo)
	{
		this->rollNo = rollNo;
	}
};

class StudentBO
{
private:
	vector<StudentVO*> *students;

public:
	StudentBO()
	{
		students = new vector<StudentVO*>();
		StudentVO *student1 = new StudentVO("Robert", 0);
		StudentVO *student2 = new StudentVO("John", 1);
		students->push_back(student1);
		students->push_back(student2);
	}

	void deleteStudent(StudentVO *student)
	{
		//students->erase(student->getRollNo());
		vector<StudentVO*>::iterator itor;
		for(itor=students->begin(); itor!=students->end();)
		{
			if(student->getRollNo() == (*itor)->getRollNo())
			{
				itor=students->erase(itor);
			}
			else
			{
				itor++;
			}
		}
		cout << "Student: Roll No " << student->getRollNo()
		     << ", deleted from database" << endl;
	}

	vector<StudentVO*>* getAllStudents()
	{
		return students;
	}

	StudentVO* getStudent(int rollNo)
	{
		return students->at(rollNo);
	}

	void updateStudent(StudentVO *student)
	{
		students->at(student->getRollNo())->setName(student->getName());
		cout << "Student: Roll No " << student->getRollNo()
		     << ", updated in the database" << endl;
	}
};


int main(int argc, char** argv)
{
	StudentBO *studentBusinessObject = new StudentBO();

	for (size_t i = 0; i < studentBusinessObject->getAllStudents()->size(); i++)
	{
		cout << "Student: [RollNo: " << studentBusinessObject->getAllStudents()->at(i)->getRollNo()
		     << ", Name: " << studentBusinessObject->getAllStudents()->at(i)->getName()
		     << " ]" << endl;
	}

	StudentVO *student = studentBusinessObject->getAllStudents()->at(0);
	student->setName("Michael");
	studentBusinessObject->updateStudent(student);

	studentBusinessObject->getStudent(0);
	cout << "Student: [RollNo: " << student->getRollNo()
	     << ", Name: " << student->getName()
	     << "]" << endl;

	return 0;
}


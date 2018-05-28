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


class Student
{
private:
	string rollNo, name;

public:
	string getRollNo()
	{
		return rollNo;
	}

	void setRollNo(string rollNo)
	{
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
};

class StudentView
{
public:
	void printStudentDetails(string studentName, string studentRollNo)
	{
		cout << "Student: " << endl
		     << "Name: "    << studentName << endl
		     << "Roll No: " << studentRollNo << endl;
	}
};

class StudentController
{
private:
	Student *model;
	StudentView *view;
public:
	StudentController(Student *model, StudentView *view)
	{
		this->model = model;
		this->view = view;
	}

	void setStudentName(string name)
	{
		model->setName(name);
	}

	string getStudentName()
	{
		return model->getName();
	}

	void setStudentRollNo(string rollNo)
	{
		model->setRollNo(rollNo);
	}

	string getStudentRollNo()
	{
		return model->getRollNo();
	}

	void updateView()
	{
		view->printStudentDetails(model->getName(), model->getRollNo());
	}
};

static Student *retriveStudentFromDatabase()
{
	Student *student = new Student();

	student->setName("Robert");
	student->setRollNo("10");
	return student;
}


int main(int argc, char** argv)
{
	Student *model = retriveStudentFromDatabase();

	StudentView *view = new StudentView();

	StudentController *controller = new StudentController(model, view);

	controller->updateView();
	controller->setStudentName("John");
	controller->updateView();

	return 0;
}


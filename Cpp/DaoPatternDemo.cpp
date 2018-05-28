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
	string name;
	int rollNo;

public:
	Student(string name, int rollNo)
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

class StudentDao
{
public:
	virtual vector<Student*>* getAllStudents() = 0;
	virtual Student* getStudent(int rollNo) = 0;
	virtual void updateStudent(Student *student) = 0;
	virtual void deleteStudent(Student *student) = 0;
};

class StudentDaoImpl: public StudentDao
{
private:
	vector<Student*> *students;

public:
	StudentDaoImpl()
	{
		students = new vector<Student*>();
		Student *student1 = new Student("Robert", 0);
		Student *student2 = new Student("John", 1);
		students->push_back(student1);
		students->push_back(student2);
	}

	void deleteStudent(Student *student)
	{
		students->erase(students->begin()+student->getRollNo());
		cout << "Student: Roll No " << student->getRollNo()
		     << "+, deleted from database" << endl;
	}

	vector<Student*>* getAllStudents()
	{
		return students;
	}

	Student* getStudent(int rollNo)
	{
		return students->at(rollNo);
	}

	void updateStudent(Student *student)
	{
		students->at(student->getRollNo())->setName(student->getName());
		cout << "Student: Roll No " << student->getRollNo()
		     << ", updated in the database" << endl;
	}
};


int main(int argc, char** argv)
{
	StudentDao *studentDao = new StudentDaoImpl();

	for (size_t i = 0; i < studentDao->getAllStudents()->size(); i++)
	{
		cout << "Student: [RollNo : " << studentDao->getAllStudents()->at(i)->getRollNo()
		     << ", Name : " << studentDao->getAllStudents()->at(i)->getName() << endl;
	}

	Student *student = studentDao->getAllStudents()->at(0);
	student->setName("Michael");
	studentDao->updateStudent(student);

	studentDao->getStudent(0);
	cout << "Student: [RollNo : " << student->getRollNo()
	     << ", Name : " << student->getName() << " ]" << endl;

	return 0;
}


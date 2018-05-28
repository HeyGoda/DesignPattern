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


class User
{
private:
	string name;

public:
	User(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}

	void setName(string name)
	{
		this->name = name;
	}

	void sendMessage(string message);
};

class ChatRoom
{
public:
	static void showMessage(User *user, string message);
};


void User::sendMessage(string message)
{
	ChatRoom::showMessage(this, message);
}

void ChatRoom::showMessage(User *user, string message)
{
	time_t now = time(NULL);
	char* dt = ctime(&now);

	cout << dt << "  [" << user->getName() << "]: " << message << endl;
}


int main(int argc, char** argv)
{
	User *robert = new User("Robert");
	User *john = new User("John");
	
	robert->sendMessage("Hi, John");
	john->sendMessage("Hello, Robert");

	return 0;
}


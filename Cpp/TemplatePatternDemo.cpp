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

class Game
{
private:
	virtual void initialize() = 0;
	virtual void startPlay() = 0;
	virtual void endPlay() = 0;

public:
	const void paly()
	{
		initialize();
		startPlay();
		endPlay();
	}
};

class Cricket: public Game
{
private:
	void endPlay()
	{
		cout << "Cricket Game Finished!" << endl;
	}

	void initialize()
	{
		cout << "Cricket Game Initialized! Start palying." << endl;
	}

	void startPlay()
	{
		cout << "Cricket Game Started. Enjoy the game!" << endl;
	}
};

class Football: public Game
{
private:
	void endPlay()
	{
		cout << "Football Game Finished!" << endl;
	}

	void initialize()
	{
		cout << "Football Game Inialized! Start playing." << endl;
	}

	void startPlay()
	{
		cout << "Football Game Started. Enjoy the game!" << endl;
	}
};


int main(int argc, char** argv)
{
	Game *game = new Cricket();
	
	game->paly();
	cout << endl;
	game = new Football();
	game->paly();

	return 0;
}


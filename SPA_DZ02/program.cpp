#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
#include <ctime>
using namespace std;

int main() {
	game_of_life the_game;
	the_game.start = true;
	bool again;
	do {
		the_game.draw(the_game.start);
		the_game.next_generation();

		cout << "Continue (1/0): ";
		cin >> again;
		system("cls");
		the_game.start = false;

	} while (again);

	return 0;
}
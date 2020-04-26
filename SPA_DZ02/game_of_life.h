#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life
{
private:
	static const unsigned int COLUMN = 40;
	static const unsigned int ROW = 20;
	bool _generation[ROW][COLUMN];
	bool _next_generation[ROW][COLUMN];
	bool random_value();
	bool cell_taken(int i, int j);
	int count_neighbours(int row, int column);

public:
	game_of_life();
	void next_generation();
	void draw(bool start);
	bool start = true;
};
#endif

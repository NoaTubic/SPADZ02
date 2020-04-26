#include "game_of_life.h"
#include <ctime>

bool game_of_life::random_value()
{
	
	int rndn = 1 + (rand() % 100 );
	if (rndn % 4 == 0) // 25% chance of surviving
	{
		return true;
	}

	else return false;
}

bool game_of_life::cell_taken(int i, int j)
{
	//if  * _gen is true, everything else false
	if (this->_generation[i][j])
		return true;
	else	
		return false;
}

int game_of_life::count_neighbours(int row, int column)
{
	int counter = 0;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if ((_generation[i][j] == true) && (_generation[i][j] != _generation[row][column]))
			{
				counter++;
			}
		}
	}
	return counter;
}

game_of_life::game_of_life()
{
}

void game_of_life::next_generation()
{
	int counter;
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 40; column++)
		{
			this->_generation[row][column] = cell_taken(row, column); //check if taken
			counter = count_neighbours(row, column); // catch number of neighbours
			if ((counter == 2 || counter == 3) && (this->_generation[row][column] = true))
			{
				this->_next_generation[row][column] = true;
			}
			else if ((counter <= 2 || counter >= 3) && (this->_generation[row][column] = true))	
			{
				this->_next_generation[row][column] = false;
			}
			else if (counter == 3 && (this->_generation[row][column] = false))	
			{
				this->_next_generation[row][column] = true;
			}
		}

	}
}

void game_of_life::draw(bool start)
{
	// 1.st draw out
	if (start)
	{
		srand((unsigned)time(0));
		for (int row = 0; row < 20; row++) {			//for every pixel
			for (int column = 0; column < 40; column++) {
				if (random_value()) {
					this->_generation[row][column] = true;	//true = alive					
					cout << "*";
				}
				else {
					this->_generation[row][column] = false;		//false = dead
					cout << "-";
				}
			}
			cout << endl;
		}

	}

	// for every next DO
	if (!start) {
		for (int row = 0; row < 20; row++) {
			for (int column = 0; column < 40; column++) {
				if (this->_next_generation[row][column] == true)  //draw* if alive
					cout << "*";
				else
					cout << "-";
			}
			cout << endl;
		}
	}

	
}

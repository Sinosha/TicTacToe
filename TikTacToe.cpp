#include <iostream>
#include "Header.h"

using namespace std;


int main()
{
	init();
	while (!is_game_over()) {
		next_move();
	}
	get_winner();	
	myprint();
}


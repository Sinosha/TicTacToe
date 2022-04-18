#include <iostream>
#include "Header.h"

using namespace std;


int main()
{
	init();
	while (!is_game_over) {
		get_coords();
		myprint();
	}
	myprint();
}


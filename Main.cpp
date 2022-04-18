#include <iostream>
#include<cctype>

using namespace std;

char board[3][3];
enum {EMPTY = ' ',CROSS = 'X', ZERO = 'O' };
char player_char;
char computer_char;


bool is_full()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == EMPTY) {
				return false;
			}
		}
	}
	return true;
}


bool is_game_over()
{
	for (int i = 0; i < 3; i++) {
		if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
			return true;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
			return true;
		}
	}
	if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
		return true;
	}
	if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
		return true;
	}
	return is_full();
}

void init()
{
	cout << "Choose prefered symbol to play with (X or O) \n";
	do {
		cin >> player_char;
		player_char = toupper(player_char);
	} while (player_char != 'X' && player_char != 'O');

	computer_char = (player_char == 'X' ? 'O' : 'X');

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = EMPTY;
		}
	}
}

void get_coords() 
{
	int row, col;
	do {
		cout << "Write coordinates (from 1 to 3) \n";
		cin >> col >> row;
		col--;
		row--;
	} while (col < 0 || col > 2 || row < 0 || row > 2 || board[row][col] != EMPTY);

	board[row][col] = player_char;
}

void AI_move()
{

}

void myprint()
{
	for (int i = 0; i < 3; i++) {
		cout << board[i][0];
		for (int j = 1; j < 3; j++) {
			cout << " | " << board[i][j];
		}
		cout << '\n';
		if (i == 2)
			break;
		for (int j = 0; j < 3; j++) {
			cout << "---" << ((j == 2) ? '\n' : '+');

		}
	}
}


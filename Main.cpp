#include <iostream>
#include<cctype>

using namespace std;

char board[3][3];
enum {EMPTY = ' ',CROSS = 'X', ZERO = 'O' };
char player_char;
char computer_char;

void init()
{
	cout << "Choose prefered symbol to play with (X or O) \n";
	do {
		cin >> player_char;
		player_char = toupper(player_char);
	} while (player_char != 'X' && player_char != 'O');

	computer_char = (player_char == 'X' ? 'O' : 'X');
}

void get_coords(int& row, int& col) 
{
	do {
		cout << "Write coordinates (from 1 to 3) \n";
		cin >> col >> row;
		col--;
		row--;
	} while (col < 0 || col > 2 || row < 0 || row > 2 || board[row][col] != EMPTY);
}

void AI_move()
{

}

void print(char board[3][3])
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

bool is_full(char board[3][3])
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
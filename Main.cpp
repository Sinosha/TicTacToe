#include <iostream>
#include<cctype>
#include<cstdlib>
#include<ctime>
#include"Header.h"

using namespace std;

char board[3][3];
enum {EMPTY = ' ',CROSS = 'X', ZERO = 'O' };
char player_char;
char computer_char;

bool is_player_move;


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
	char winner = get_winner();
	bool board_is_full = is_full();
	if (winner != EMPTY) {
		cout << "Winner is - " << winner << '\n';
	}
	else if (board_is_full) {
		cout << " Draw! \n";
	}
	return winner != EMPTY || board_is_full;
}

void init()
{
	cout << "Choose prefered symbol to play with (X or O) \n";
	srand(time(0));
	do {
		cin >> player_char;
		player_char = toupper(player_char);
	} while (player_char != 'X' && player_char != 'O');

	is_player_move = player_char == 'O';

	computer_char = (player_char == 'X' ? 'O' : 'X');

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = EMPTY;
		}
	}
}

void make_player_move() 
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
	int row, col;
	do {
		row = rand() % 3;
		col = rand() % 3;
	} while (board[row][col] != EMPTY);
	board[row][col] = computer_char;
}

void next_move()
{
	if (is_player_move) {
		make_player_move();
		is_player_move = false;
	}
	else {
		AI_move();
		is_player_move = true;
	}
	myprint();
	cout << '\n';
}

void myprint()
{
	for (int i = 0; i < 3; i++) {
		cout << ' ' << board[i][0];
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
	cout << '\n';
}

char get_winner()
{
	for (int i = 0; i < 3; i++) {
		if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
			return board[i][0];
		}
	}
	for (int i = 0; i < 3; i++) {
		if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
			return board[0][i];
		}
	}
	if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
		return board[0][0];
	}
	if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
		return board[0][2];
	}
	return EMPTY;
}


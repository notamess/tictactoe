#include <stdio.h>
#include <stdlib.h>

// tictactoe
// by me

const char* BANNER = "This is a banner\nYaaay!\n";

const char c0 = ' ';
const char c1 = 'X';
const char c2 = 'O';

char board[3][3] = {
	{c0, c0, c0},
	{c0, c0, c0},
	{c0, c0, c0}
};


void print_board () {
	for (int row = 0; row < 3; row++) {
		printf(" ");

		for (int column = 0; column < 3; column++) {
			printf("%c", board[row][column]);

			if (column < 2) printf(" | ");
		}

	printf(" \n");
	if (row < 2) printf("-----------\n");
	}

	return;
}


int get_num () {
	int n;
	char buffer[1024];

	do {
		fgets(buffer, 1024, stdin);

		n = atoi(buffer);
	} while (n == 0);

	return n;
}


int get_row () {
	int loop = 1;
	int n;
	char c;

	printf("Row: ");

	while (loop) {
		n = get_num();

		if (n > 3 || n < 1) {
			printf("Row (1-3):");
		} else {
			loop = 0;
		}
	}

	return n - 1;
}


int get_column () {
	int loop = 1;
	int n;
	char c;

	printf("Column: ");

	while (loop) {
		n = get_num();

		if (n > 3 || n < 1) {
			printf("Column (1-3):");
		} else {
			loop = 0;
		}
	}

	return n - 1;
}


int check_move (int d1, int d2) {
	if (board[d1][d2] == c0)
		return 1;

	return 0;
}


char check_lines () {
	for (int row = 0; row < 3; row++) {
		if (board[row][0] != c0 && board[row][0] == board[row][1] && board[row][0] == board[row][2])
			return board[row][0];
	}
	
	for (int column = 0; column < 3; column++) {
		if (board[0][column] != c0 && board[0][column] == board[1][column] && board[0][column] == board[2][column])
			return board[0][column];
	}
	
	// diagonals
	if (board[0][0] != c0 && board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return board[0][0];

	if (board[0][2] != c0 && board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return board[0][2];

	return c0;
}


void next_turn (char* c) {
	if (*c == c1)
		*c = c2;
	else if (*c == c2)
		*c = c1;
	else
		printf("idk: %c\n", *c);
	return;
}


int main () {
	printf(BANNER);
	printf("\n");

	char turn = c1;
	char winner = c0;
	int done = 0;

	while (!done) {
		print_board();
		printf("\n");

		int d1;
		int d2;

		d1 = get_row();
		d2 = get_column();

		while (!check_move(d1, d2)) {
			printf("Not a valid move!\n");

			d1 = get_row();
			d2 = get_column();
		}

		printf("\n");

		board[d1][d2] = turn;

		winner = check_lines();

		if (winner == c0) {
			next_turn(&turn);
		} else {
			printf("done\n");
			done = 1;
		}
	}

	print_board();
	printf("\n");

	printf("Game over, %c won!\n", winner);
}

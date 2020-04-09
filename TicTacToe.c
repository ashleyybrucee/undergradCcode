// Program Name: Exercise 4.2
// Author: Ashley Bruce
// Date 12-7-19
// Description: Tic Tac Toe

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 3
#define COLUMNS 3

void initializeboard (char board [ROWS][COLUMNS]);
void userInput (char board [ROWS][COLUMNS], int player);
int checkWinner (char board [ROWS][COLUMNS]);
int randomPlayer ();

int main (void) {
	
	char board [ROWS][COLUMNS];	
	int winner = 0;
	int turnCount = 0;
	int player = randomPlayer ();
	char newGame = 'N';
	int xWins = 0;
	int oWins = 0;
	
	printf ("TIC TAC TOE \n");
	
	do {
		initializeBoard (board);
		printBoard (board);
	
		while (winner == 0) {
			userInput (board, player);
			printBoard (board);
			winner = checkWinner (board);
			turnCount++;
			player++;
			if (player > 2)
				player = 1;
		
			if (turnCount == 9)
				winner = 3;
		}
	
		if (winner == 1) {
			printf ("Player 1 Wins \n");
			xWins ++;
		}
		else if (winner == 2) {
			printf ("Player 2 Wins \n");
			oWins++;
		}
		else 
			printf ("Tie \n");
			
		printf ("X Wins: %i  O Wins: %i \n", xWins, oWins);
			
		printf ("New Game? Type 'Y' to continue > ");
		scanf ("\n%c", &newGame);
		printf ("\n");
		
	} while (newGame == 'Y');
	
	return (0);
}

int randomPlayer () {
	time_t seed;
	(void)time(&seed);
	srand((long)seed);
	return (rand()%2 + 1);
}

void initializeBoard (char board [ROWS][COLUMNS]) {
	int i, j;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			board [i][j] = ' ';
		}
	}
}

void printBoard (char board [ROWS][COLUMNS]) {
	int i, j;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf (" %c", board[i][j]);
			if (j < COLUMNS - 1) {
				printf (" |");
			}
		}
		if (i < ROWS - 1) {
			printf ("\n-----------\n");
		}
	}
	printf ("\n");
}

void userInput (char board [ROWS][COLUMNS], int player) {
	int row, column;
	char symbol;
	int validInput = 0;
	
	if (player == 1)
		symbol = 'X';
	else
		symbol = 'O';
	
	while (validInput == 0) {
		printf ("Player %i - Enter %c with spaces: Row, Col> ", player, symbol);
		scanf ("%i %i", &row, &column);
		
		if (row > 3 || row < 1) {
			printf ("Choice out of bounds \n");
			validInput = 0;
			break;
		}
		else if (column > 3 || column < 1) {
			printf ("Choice out of bounds \n");
			validInput = 0;
			break;
		}
		
		row = row -1;
		column = column -1;
		if (board [row][column] != ' ') {
			printf ("That spot on the board is taken \n");
			validInput = 0;
		}
		else {
			validInput = 1;
			board [row][column] = symbol;
		}		
	}
}

/* 
returns 0 if no winner
returns 1 if player 1 wins (x)
returns 2 if player 2 wins (O)
*/
int checkWinner (char board [ROWS][COLUMNS]) {
	// 8 ways to win
	
	// diagonal win 
	if (board [0][0] != ' ' && board [0][0] == board [1][1] && board [1][1] == board [2][2]) {
		if (board [0][0] == 'X') {
			return 1;
		}
		else {
			return 2;
		}
	}
	if (board [1][2] != ' ' && board [1][2] == board [1][1] && board [1][1] == board [2][0]) {
		if (board [1][2] == 'X') {
			return 1;
		}
		else {
			return 2;
		}
	}
	
	int xCount = 0;
	int oCount = 0;
	int i, j;
	
	// row win
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			if (board [i][j] == 'X') 
				xCount++;
			if (board [i][j] == 'O')
				oCount++;
		}
		if (xCount == 3)
			return 1;
		if (oCount == 3)
			return 2;
		xCount = 0;
		oCount = 0;	
	}
	
	//column win
	for (j = 0; j < COLUMNS; j++) {
		for (i = 0; i < ROWS; i++) {
			if (board [i][j] == 'X')
				xCount++;
			if (board [i][j] == 'O')
				oCount++;
		}
		if (xCount == 3)
			return 1;
		if (oCount == 3)
			return 2;
		xCount = 0;
		oCount = 0;
	}
	return 0;
}






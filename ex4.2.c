//ex4.2.c

// Add:
// * 


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void initBoard(char[ROWS][COLS]);
void clear_grid(char [ROWS][COLS]);
void printBoard(char [ROWS][COLS]);
int input(char [ROWS][COLS], int, char, int);
int checkWin(char[ROWS][COLS]);

int flip(int i) {
    if(i == 1)
        return 2;
    else
        return 1;
}

char randomSymbol() {
    time_t seed;
    (void)time(&seed);
    srand((long)seed);
    int isX = rand() % 2;
    if(isX)
        return 'X';
    else
        return 'O';
}

int main (void) {

    int ai = 0;
    char aiSelect;
    printf("Would you like a computer to play against? y/n >");
    scanf("%c", &aiSelect);
    if(aiSelect == 'y')
        ai = 1;

    int p1Wins = 0;
    int p2Wins = 0;
    int firstPlayerTurn;
    int playerTurn;
    char player1Char = randomSymbol();
    char player2Char;
    if(player1Char == 'X') {
        firstPlayerTurn = 1;
        player2Char = 'O';
    }
    else {
        firstPlayerTurn = 2;
        player2Char = 'X';
    }
    playerTurn = firstPlayerTurn;

    char board[ROWS][COLS];
    initBoard(board);
    int turn = 1;

    int play = 1;

    printf("TIC TAC TOE\n");
    printBoard(board);

    while(play) {
        char curPlayerChar;
        if(playerTurn == 1)
            curPlayerChar = player1Char;
        else 
            curPlayerChar = player2Char;
        
        if(!input(board, playerTurn, curPlayerChar, ai)) {
            printBoard(board);
        
            int result = checkWin(board);
            if(result == 1) {
                printf("Player 1 wins\n");
                p1Wins++;
                printf("Player 1 has %i wins! Player 2 has %i wins!\n", p1Wins, p2Wins);
                clear_grid(board);
                turn = 0;
                player1Char = randomSymbol();
                firstPlayerTurn = flip(firstPlayerTurn);
                playerTurn = firstPlayerTurn;
                
                char playAgain;
                printf("Play again? y/n> ");
                scanf("\n%c", &playAgain);
                
                if(playAgain != 'y')
                    play = 0;
            } else if(result == 2) {
                printf("Player 2 wins\n");
                p2Wins++;
                printf("Player 1 has %i wins! Player 2 has %i wins!\n", p1Wins, p2Wins);
                clear_grid(board);
                turn = 0;
                player1Char = randomSymbol();
                firstPlayerTurn = flip(firstPlayerTurn);
                playerTurn = firstPlayerTurn;
                char playAgain;
                printf("Play again? y/n> ");
                scanf("\n%c", &playAgain);
                if(playAgain != 'y')
                    play = 0;
            } else if(turn >= 9) {
                printf("Tie game\n");
                clear_grid(board);
                turn = 0;
                player1Char = randomSymbol();
                firstPlayerTurn = flip(firstPlayerTurn);
                playerTurn = firstPlayerTurn;
                char playAgain;
                printf("Play again? y/n> ");
                scanf("\n%c", &playAgain);
                if(playAgain != 'y')
                    play = 0;
            } else {
                turn++;
                playerTurn = flip(playerTurn);
            }
        }
    }

}

int checkWin(char board[ROWS][COLS]) {

    int xCount = 0;
    int oCount = 0;

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == 'X')
                xCount++;
            else if(board[i][j] == 'O')
                oCount++;
        }

        if(xCount == 3) 
            return 1;
        if(oCount == 3)
            return 2;
        xCount = 0;
        oCount = 0;
    }

    for(int i = 0; i < COLS; i++) {
        for(int j = 0; j < ROWS; j++) {
            if(board[j][i] == 'X')
                xCount++;
            else if(board[j][i] == 'O')
                oCount++;
        }

        if(xCount == 3) 
            return 1;
        if(oCount == 3)
            return 2;
        xCount = 0;
        oCount = 0;
    }

    for(int i = 0; i < COLS; i++) {
        if(board[i][i] == 'X')
            xCount++;
        else if(board[i][i] == 'O')
            oCount++;
    }

    if(xCount == 3) 
        return 1;
        
    if(oCount == 3)
        return 2;
    
    xCount = 0;
    oCount = 0;

    for(int i = 0; i < COLS; i++) {
        for(int j = 0; j < ROWS; j++) {
            if(i == 0 && j == 2) {
                if(board[i][j] == 'X')
                    xCount++;
                else if(board[i][j] == 'O')
                    oCount++;
            }
            if(i == 1 && j == 1) {
                if(board[i][j] == 'X')
                    xCount++;
                else if(board[i][j] == 'O')
                    oCount++;
            }
            if(i == 2 && j == 0) {
                if(board[i][j] == 'X')
                    xCount++;
                else if(board[i][j] == 'O')
                    oCount++;
            }
        }
    }

    if(xCount == 3) 
        return 1;
    if(oCount == 3)
        return 2;
    
    return -1;
}

int input(char board[ROWS][COLS], int turn, char symbol, int ai) {
    int row, col;
    char team;

    if(!ai || turn == 1) {
        printf("Player %i enter with spaces: Row, Col, %c>", turn, symbol);
        scanf("%i %i %c", &row, &col, &team);
        row -= 1;
        col -= 1;

        if(row >= ROWS || col >= COLS) {
            printf("Please chose a spot on the board\n");
            return 1;
        }

        if(team != symbol) {
            printf("Please enter an %c\n", symbol);
            return 1;
        }

        if(board[row][col] == ' ') {
            board[row][col] = team;
            return 0;
        } else {
            printf("[%i, %i] is taken\n", row, col);
            return 1;
    }

    } else {
        printf("\nthinking...\n\n");
        int x, y;
        //ai chooses move
            //check for win
                //Put symbol in place
                //Check win
                //If no win, remove it
        
        for(int i = 0; i < COLS; i++) {
            for(int j = 0; j < ROWS; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = symbol;
                    if(checkWin(board) == 2) {
                        return 0;
                    } 
                    char other = 'X';
                    if(symbol == 'X')
                        other = 'O';
                    board[i][j] = other; //not symbol
                    if(checkWin(board) == 1) {
                       board[i][j] = symbol;
                       return 0;
                    }
                    board[i][j] = ' ';
                }
            }
        }


        time_t seed;
        (void)time(&seed);
        srand((long)seed);
        int spot = rand() % 9;

        int searching = 1;

        while(searching) {
            switch (spot)
            {
            case 0:
                if(board[0][0] == ' ') {
                    board[0][0] = symbol;
                    searching = 0;
                } else {
                    spot++;
                }
                break;
            case 1:
                if(board[0][1] == ' ') {
                    board[0][1] = symbol;
                    searching = 0;
                } else {
                    spot++;
                }
                break;
            case 2:
                if(board[0][2] == ' ') {
                    board[0][2] = symbol;
                    searching = 0;
                } else {
                    spot++;
                }
                break;
            case 3:
                if(board[1][0] == ' ') {
                    board[1][0] = symbol;
                    searching = 0;
                } else {
                    spot++;
                }
                break;
            case 4:
                if(board[1][2] == ' ') {
                    board[1][2] = symbol;
                    searching = 0;
                } else {
                    spot++;
                }
                break;
            case 5:
                if(board[2][0] == ' ') {
                    board[2][0] = symbol;
                    searching = 0;
                } else {
                    spot++;
                }
                break;
            case 6:
                if(board[2][1] == ' ') {
                    board[2][1] = symbol;
                    searching = 0;
                } else {
                    spot++;
                }
                break;
            case 7:
                if(board[2][2] == ' ') {
                    board[2][2] = symbol;
                    searching = 0;
                } else {
                    spot++;
                }
                break;
            case 8:
                if(board[0][0] == ' ') {
                    board[0][0] = symbol;
                    searching = 0;
                } else {
                    spot = 0;
                }
                break;
            default:
                break;
            }
            return 0;
        }

            //check for loss
                //put enemy symbol in place
                //Check win
                //If no win, remove it
                //If win, replace with friendly symbol

            //make random selection
                //chose a random number 1 - 9. Fill in this spot.
                // If it is full, scan right until an empty spot is found

        //ai makes move
        board[x][y] = symbol;
        return 0;
    }

    return 1;
}

void initBoard(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void clear_grid(char board [ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}


void printBoard(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf(" %c", board[i][j]);
            if(j < COLS - 1) {
                printf(" |");
            }
        }
        if(i < ROWS - 1)
            printf("\n-----------\n");
    }
    printf("\n");
}


#include <stdio.h>
#include "lifefunc.h"
#include <stdbool.h>

void reset(char board[][BOARD_SIZE + 1])
{
    //resets the board to empty
    int i;
    int j;

    for (i = 0; i < BOARD_SIZE; ++i)
    {
        for (j = 0; j < BOARD_SIZE; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void disp(char board[][BOARD_SIZE + 1])
{
    //display the board
    int i;
    int j;
    printf("┌");
    for (i = 0; i <= BOARD_SIZE -1; ++i)
    {
        printf("-");
    }
    printf("┐");
    printf("\n");
    for (i = 0; i < BOARD_SIZE; ++i)
    {
        printf("|");
        for (j = 0; j < BOARD_SIZE; ++j)
        {
            printf("%c", board[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("└");
    for (i = 0; i <= BOARD_SIZE-1; ++i)
    {
        printf("-");
    }
    printf("┘");
    printf("\n");
}

void play(char board[][BOARD_SIZE+1]){
    // advances the board based on the game rules
    int i,j;
    int k;
    int counterDead = 0;
    int counterAlive = 0;
    char arrayForCheck[BOARD_SIZE][BOARD_SIZE+1];

    for (i = 0; i < BOARD_SIZE; ++i)
        for(j = 0; j < BOARD_SIZE; ++j) 
            arrayForCheck[i][j] = board[i][j];


    for (i = 0; i < BOARD_SIZE; ++i){
        for(j = 0; j < BOARD_SIZE; ++j){
                if (isValidIndex(i-1,j-1)) {
                    if(arrayForCheck[i-1][j-1] == 'X') counterAlive++;
                }
                
                if (isValidIndex(i-1,j)) {
                    if(arrayForCheck[i-1][j] == 'X') counterAlive++;
                }

                if (isValidIndex(i-1,j+1)) {
                    if(arrayForCheck[i-1][j+1] == 'X') counterAlive++;
                }
                
                if (isValidIndex(i,j+1)) {
                    if(arrayForCheck[i][j+1] == 'X') counterAlive++;
                }

                if (isValidIndex(i+1,j+1)) {
                    if(arrayForCheck[i+1][j+1] == 'X') counterAlive++;
                }

                if (isValidIndex(i+1,j)) {
                    if(arrayForCheck[i+1][j] == 'X') counterAlive++;
                }

                if (isValidIndex(i+1,j-1)) {
                    if(arrayForCheck[i+1][j-1] == 'X') counterAlive++;
                }

                if (isValidIndex(i,j-1)) {
                    if(arrayForCheck[i][j-1] == 'X') counterAlive++;
                }

                switch (arrayForCheck[i][j])
                {
                case ' ':
                    if(counterAlive == 3) board[i][j] = 'X';
                    break;
                case 'X':
                    if(counterAlive != 2 && counterAlive !=3) board[i][j] = ' ';
                    break;
                default:
                    printf("Error\n");
                }

                counterAlive = 0;
        }
    }
}
void  AddCell(char board[][BOARD_SIZE+1], int row, int col){
    // add a cell based on row and column
    board[row][col] = 'X';
}

void RemoveCell(char board[][BOARD_SIZE+1], int row, int col){
    // removes a cell based on row and column
    board[row][col] = ' ';
}
 
bool isValidIndex(int row, int col){
    // checks if the index is valid for the board
    if (row >=0 && row< BOARD_SIZE && col>=0 && col< BOARD_SIZE) return true;
    else return false;
}

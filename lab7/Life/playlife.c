/*
Name: Sviatoslav Oleksiienko
Section: Lab 02
Problem: Lab 7: Conway's Game of Life
Purpose: a program that simulates the playing or animation of Conway's Game of Life on a 40-by-40 board, displayed as Xs (live cells) and blank spaces (dead cells).
*/
#include <stdio.h>
#include <string.h>
#include "lifefunc.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char board[BOARD_SIZE][BOARD_SIZE + 1]; // I will assume that the number of columns will always equal the number of rows
    FILE *openedFile;
    bool isFinished = false;
    bool isFile = false;
    char choiceChar;
    int row;
    int col;
    reset(board);
    if (argc == 2)
    {
        isFile = true;
        openedFile = fopen(argv[1], "r");
        if (openedFile == NULL)
        {
            printf("Couldn't open the file\n");
            return -1;
        }
    }
    else if (argc > 2)
    {
        printf("Error. Too many arguments.\n");
        return -1;
    }

    while (!isFinished)
    {
        disp(board);
        if (isFile)
        {
            fscanf(openedFile, " %c", &choiceChar);
        }
        else
        {
            printf("Enter your choice: \n");
            scanf(" %c", &choiceChar);
        }
        switch (choiceChar)
        {
        case 'a':
            if (isFile)
            {
                fscanf(openedFile, "%d %d", &row, &col);
            }
            else
            {
                scanf("%d %d", &row, &col);
            }
            AddCell(board, row, col);

            break;
        case 'r':
            if (isFile)
            {
                fscanf(openedFile, "%d %d", &row, &col);
            }
            else
            {
                scanf("%d %d", &row, &col);
            }
            RemoveCell(board, row, col);
            break;
        case 'n':
            play(board);
            break;
        case 'q':
            isFinished = true;
            break;
        case 'p':
            if (openedFile != NULL)
            {
                fclose(openedFile);
            }
            while (true)
            {

                play(board);
                disp(board);

                usleep(200000); // Sleep for 200 milliseconds (0.2 seconds)
                system("clear");
            }
            break;
        default:
            printf("Unknown command!\n");
            break;
        }
    }
}
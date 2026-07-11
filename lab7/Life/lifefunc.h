#include <stdbool.h>

#define BOARD_SIZE 40
void reset(char[][BOARD_SIZE+1]);
void disp(char[][BOARD_SIZE+1]);
void play(char[][BOARD_SIZE+1]);
void AddCell(char [][BOARD_SIZE+1],int,int);
void RemoveCell(char [][BOARD_SIZE+1], int,int);
bool isValidIndex(int row, int col);
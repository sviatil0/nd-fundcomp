
/*
Author: Sviatoslav Oleksiienko
Lab: section 02
Date: 12/15
Purpuse: a growing snake game. Please, use arrows to play. 
*/
#include "gfx.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int x;
    int y;
} Location;
typedef struct
{
    int horizontal;
    int vertical;
} Velocity;

typedef struct
{
    Velocity velocity;
    int snakeDrawingRadius;
    Location *body;
    int bodyLength;
} SnakeInstance;


// Required for switch case as it only accepts compile time constants
#define ARROW_UP 'R' 
#define ARROW_DOWN 'T'
#define ARROW_RIGHT 'S'
#define ARROW_LEFT 'Q'

bool HasContactedBooster(Location booster, SnakeInstance snake);

void CreateBoosterByChance(Location *booster, int screenWidth, int screenHeight, int sideLength);
void DrawBoosters(Location booster, int sideLength);
bool HasSnakeDied(SnakeInstance snake, int screenWidth, int screenHeight);

bool HasSnakeDied(SnakeInstance snake, int screenWidth, int screenHeight);
void AdvanceSnake (SnakeInstance *snake );
void ArrayRightShiftLocation(Location * array, int length);
void DrawCircle(Location lc, int radius);

void DrawSquare(Location lc, int halfSideLenght);

int GenerageNumberInBounds(int lb, int hb);

Location GenerateRandomLocation(int radius, int screenWidth, int screenHeight);

SnakeInstance InitializeSnakeInstance(Location *snakeBody, int inLength, int radius, int screenWidth, int screenHeight);

void DrawSnakeInstance(SnakeInstance snake);

void AppendTail(SnakeInstance *snake);
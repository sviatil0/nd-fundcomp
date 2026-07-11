
/*
Author: Sviatoslav Oleksiienko
Lab: section 02
Date: 12/15
Purpuse: a growing snake game. Please, use arrows to play. 
*/
#include "gfx.h"
#include "func.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void AppendTail(SnakeInstance *snake){
  snake->bodyLength++;
  Location tailLocation;
  tailLocation.x = snake->body[snake->bodyLength-2].x + snake->velocity.horizontal;
  tailLocation.y = snake->body[snake->bodyLength-2].y + snake->velocity.horizontal;

  snake->body[snake->bodyLength-1] = tailLocation;
}
void AdvanceSnake (SnakeInstance * snake ){
    ArrayRightShiftLocation(snake->body, snake->bodyLength);
    snake->body[0].y += snake->velocity.vertical;
    snake->body[0].x += snake->velocity.horizontal;
    DrawSnakeInstance(*snake);

}
void DrawCircle(Location lc, int radius)
{
    // Base step
    if (radius < 1)
        return;

    // Main step
    gfx_circle(lc.x, lc.y, radius);

    // Recursion step
    // Draws a solid circle
    DrawCircle(lc, radius - 1);
}
void ArrayRightShiftLocation(Location * array, int length){
    if (length <= 1 ) return;
    for(int i = length-1; i >= 1; --i){
        array[i] = array[i-1];
    }
}
void DrawSquare(Location lc, int halfSideLenght)
{
    // Base step
    if (halfSideLenght < 1)
    {
        return;
    }

    // Main step
    int x1 = lc.x - halfSideLenght;
    int y1 = lc.y - halfSideLenght;

    int x2 = lc.x - halfSideLenght;
    int y2 = lc.y + halfSideLenght;

    int x3 = lc.x + halfSideLenght;
    int y3 = lc.y + halfSideLenght;

    int x4 = lc.x + halfSideLenght;
    int y4 = lc.y - halfSideLenght;

    gfx_line(x1, y1, x2, y2);
    gfx_line(x2, y2, x3, y3);
    gfx_line(x3, y3, x4, y4);
    gfx_line(x4, y4, x1, y1);

    // Recursion step
    //  Draws a solid square
    Location newLocation = {lc.x - 1, lc.y - 1};
    DrawSquare(newLocation, halfSideLenght - 1);
}
int GenerageNumberInBounds(int lb, int hb)
{
    return rand() % (hb + 1 - lb) + lb;
}

Location GenerateRandomLocation(int radius, int screenWidth, int screenHeight)
{
    Location lc = {GenerageNumberInBounds(radius, screenWidth - radius), GenerageNumberInBounds(radius, screenHeight - radius)};
    return lc;
}

SnakeInstance InitializeSnakeInstance(Location *snakeBody, int inLength, int radius, int screenWidth, int screenHeight)
{
    SnakeInstance snake;
    Location inLocation = GenerateRandomLocation(radius*2*inLength, screenWidth, screenHeight);
    snake.bodyLength = inLength;
    snake.snakeDrawingRadius = radius;
    snake.velocity.horizontal = snake.snakeDrawingRadius;
    snake.velocity.vertical = 0;
    snakeBody[0] = inLocation;
    for (int i = 1; i < snake.bodyLength; ++i)
    {
        snakeBody[i].x = snakeBody[i - 1].x + snake.snakeDrawingRadius *2;
        snakeBody[i].y = snakeBody[0].y;
    }
    snake.body = snakeBody;
    return snake;
}
void DrawSnakeInstance(SnakeInstance snake)
{
    gfx_clear();
    gfx_color(255,0,0);
    DrawCircle(snake.body[0], snake.snakeDrawingRadius);
    
    gfx_color(255,255,255);
    for (int i = 1; i < snake.bodyLength; ++i)
    {
        DrawCircle(snake.body[i], snake.snakeDrawingRadius);
    }
    gfx_flush();
}
bool HasSnakeDied(SnakeInstance snake, int screenWidth, int screenHeight){
    // Checkes for touching the outer bounds
    if(snake.body[0].x + snake.snakeDrawingRadius >= screenWidth || snake.body[0].x - snake.snakeDrawingRadius <= 0 || snake.body[0].y + snake.snakeDrawingRadius  >= screenHeight || snake.body[0].y - snake.snakeDrawingRadius <= 0) 
        return true;

    for(int i = 2; i < snake.bodyLength; ++i){

    if(abs(snake.body[0].x - snake.body[i].x)< snake.snakeDrawingRadius*2 && abs(snake.body[0].y - snake.body[i].y) < snake.snakeDrawingRadius*2) 
        return true; 
    }
    return false;
}
bool HasContactedBooster(Location booster, SnakeInstance snake){
        //    distance = sqrt(pow(snake.body[0].x-boosters->locations[j].x,2) + pow(snake.body[0].y-boosters->locations[j].y,2)) ;
            if((abs(snake.body[0].x - booster.x)< snake.snakeDrawingRadius*1.5) && (abs(snake.body[0].y - booster.y) < 1.5* snake.snakeDrawingRadius)) {
                // RemoveBooster(boosters, j);
                return true; 
            }

    return false;
}
void CreateBoosterByChance(Location *booster, int screenWidth, int screenHeight, int sideLength){

    Location newLocation = GenerateRandomLocation(sideLength, screenWidth, screenHeight);
    *booster = newLocation;
}
void DrawBoosters(Location booster, int sideLength){
    //    gfx_color(GenerageNumberInBounds(127,255),GenerageNumberInBounds(127,255), GenerageNumberInBounds(127,255));
       DrawSquare(booster, sideLength/2);
        gfx_flush(); 
    // gfx_color(255,255,255);
}

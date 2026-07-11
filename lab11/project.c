/*
Author: Sviatoslav Oleksiienko
Lab: section 02
Date: 12/15
Purpuse: a growing snake game. Please, use arrows to play. 
*/
#include <stdio.h>
#include "gfx.h"
#include "func.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>


int main(){
    // Defining variables 
    srand(time(NULL));
    int width = 700, height = width; // Need a square
    int snakeRadius = width/28;
    int initialSnakeLength = 3;
    char inputKey;
    bool isFinished = false;
    bool userWon = false;
    int lengthToWin = 12;
    int score = 0;
    int desiredScore = lengthToWin- initialSnakeLength;
    Velocity UP_VELOCITY = {0,-snakeRadius*2};
    Velocity DOWN_VELOCITY = {0,snakeRadius*2};
    Velocity LEFT_VELOCITY = {-snakeRadius*2,0};
    Velocity RIGHT_VELOCITY = {snakeRadius*2,0};
    Location * snakeBody;
    snakeBody = (Location *)malloc(sizeof(Location) * initialSnakeLength);
    SnakeInstance snake1 = InitializeSnakeInstance(snakeBody,initialSnakeLength, snakeRadius, width,height); 
    snake1.velocity = LEFT_VELOCITY; // default velocity
    Location booster;
    gfx_open(width,height,"Snake game"); 

    gfx_text(width/2-200,height/2,"Use arrows to play! Score board is at the right top corner.");
    gfx_text(width/2-250,height/2+50,"The red part is the snake's head. You can eat squares with it to grow the snake.");
    char scoreResult[20];
    gfx_flush();
    sleep(5); 
    CreateBoosterByChance(&booster, width, height,snakeRadius);
    while(!isFinished){
        if (gfx_event_waiting()){
            inputKey=gfx_wait();
        
        switch(inputKey){
            case ARROW_UP:
        //Can only turn if if not moving vertically already
                if(snake1.velocity.vertical == 0)
                    snake1.velocity = UP_VELOCITY;
                break;
            case ARROW_DOWN:
                if(snake1.velocity.vertical ==0)
                    snake1.velocity = DOWN_VELOCITY;
                break;
            case ARROW_LEFT:
                if(snake1.velocity.horizontal == 0 )
                    snake1.velocity = LEFT_VELOCITY;
                break;
            case ARROW_RIGHT:
                if(snake1.velocity.horizontal ==0 )
                    snake1.velocity = RIGHT_VELOCITY;
                break;
            case 'q':
                isFinished = true;
            break;
            default:
                // printf("Invalid key!\n");
            break;
        }}
        AdvanceSnake(&snake1);
        gfx_flush();
        if (HasContactedBooster(booster, snake1)){
        AppendTail(&snake1);
        CreateBoosterByChance(&booster, width, height,snakeRadius);
        score++;
        }
        if(HasSnakeDied(snake1, width, height)) {
            isFinished = true;
            break;
        }else if (snake1.bodyLength == lengthToWin){
            userWon = true;
            break;
        }
        sprintf(scoreResult, "Your score %d / %d", score, desiredScore);
        gfx_text(width-200,20, scoreResult);
        DrawBoosters(booster,snakeRadius);
        usleep(200000);
    } 
    gfx_clear();
    if (userWon){
    gfx_text(width/2,height/2,"You win!");
    }else{
    gfx_text(width/2,height/2,"Game over!");
    }
    gfx_flush();
    sleep(2); 
    return 0;
}




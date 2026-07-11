/*
Name: Sviatoslav Oleksiienko
Lab section: 02
Assignment: Part 2: prime numbers 
Purpose: undentifies and outputs the prime numbers from 1 to 1000 
*/

#include <stdio.h>
#include <math.h>

int main(){
    int i,j;
    const int ARRAY_LENGTH = 1000;
    int numbers[ARRAY_LENGTH]; 
    int startingIndex = 2;
    int counter = 0; // needed for proper allignment of the output

    // Initializing array with ones
    for (i=0; i < ARRAY_LENGTH; ++i){
        numbers[i] = 1;
    }

    // Implementing the sieve algorithm
    for (i = startingIndex; i < ARRAY_LENGTH; ++i ){
       if (numbers[i] == 1){
            for (j = i+1; j <= ARRAY_LENGTH; ++j){
               if (j % i == 0) {
                    numbers[j] = 0;
               }
            }
       }   
    }

    // Printing the elements of the array
    for (i = startingIndex; i < ARRAY_LENGTH; ++i){
        if (numbers[i] == 1){
            printf("%5d",i);
            counter++;
        } 
        if (counter == 10){
             printf("\n");
             counter = 0;
        }
    }
    printf("\n");
    
    return 0;
}

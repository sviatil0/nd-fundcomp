/*
Name: Sviatoslav Oleksiienko
Section: lab section 02
Assignment: Lab 2. Part 1: Multiplication Table
Purpose: Asks the user for the size of the table 
and then displays the multiplication table exactly this 
size.
*/

#include <stdio.h>

int main(){
    //Declaring variables   
    int X,Y,i,j,product; // numberOfSpacesInTab;
   // numberOfSpacesInTab = 8; //because the length of the \t can differ in different enviroments, necessary assumption needed to make a good separator between header and the main body. 8 is a very common number of spaces in tab

    //User input 
    printf("Please enter the horizontal size:\t");
    scanf("%d", &X);
    printf("\n");   

    printf("Please enter the vertical size:  \t");
    scanf("%d",&Y);
    printf("\n");
    //Nested loops that build the table 

        // Displaying the horizontal header
        printf("*\t");
        for (i = 1; i <= X; ++i ){

            printf("%d", i);
            if (i != X ){ //prints the tab if it is not the last value in the horizontal header 
                printf("\t");
            }
        }
        printf("\n");
        // Displaying the separater of the main header with main part of the table 
        printf(" \t"); //needed to fix the indentation of the separator 
         
        for (i = 1; i <= X; ++i){
            printf("_");
            if (i != X){
                printf("\t");
                /*for (i =0; i < numberOfSpacesInTab; ++i){
                printf("_"); //assuming the previously defined number of spaces in \t symbol 
                }
                */
            }
        }

        printf("\n");
        // Diplaying the vertical header with the main table

        for (j = 1; j <= Y; ++j){ // The loop that iterates vertically
            printf("%d |\t", j);

            for (i = 1; i <= X; ++i){ // The loop that iterates horizontally
                product = i*j;  
                printf("%d", product);
                if (i != X){ //prints tab if not the last number
                    printf("\t");
                }   
            }
            printf("\n");
        }
       
       
       
       
return 0;




}
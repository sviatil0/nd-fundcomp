
/*
Name: Sviatoslav Oleksiienko
Lab section: 02
Assignment: Part 1: a simple array
Purpose: The program finds length, average, and standard deviation for the hard codded array of grades. 
*/

#include <stdio.h>
#include <math.h>
// function prototypes ...
float FindAverage(int array [], int size);
float FindStdv(int array[], int size);

int main()
{
  int grades[] =
    { 96,73,62,87,80,63,93,79,71,99,
      82,83,80,97,89,82,93,92,95,89,
      71,97,91,95,63,81,76,98,64,86,
      74,79,98,82,77,68,87,70,75,97,
      71,94,68,87,79 };
  const int ARRAY_LENGTH = sizeof(grades) / sizeof(grades[0]); // finds an array length by dividign the size in bytes of the array compared to the size in bytes of the one element of the array

  float average = FindAverage(grades, ARRAY_LENGTH);
  float stdv = FindStdv(grades, ARRAY_LENGTH);

  // rest of program goes here 
  printf("Number of grades: %d\n", ARRAY_LENGTH); 
  printf("The average grade: %.2f\n", average);  
  printf("Standard Deviation: %.2f\n", stdv); 

  return 0;
}

// function definitions ...

float FindAverage(int array [], int size){
  // the program computes and returns the average
  float totalSum = 0;
  float average; 
  int i;
  for (i = 0; i < size; ++i){
    totalSum += array[i];
  }
  average = totalSum / size;
  return average; 
}
float FindStdv(int array[], int size){ 
  // the function finds the standard deviation based on this formula https://prnt.sc/DGhwbWTnVbqM
  float sumForStdv = 0;
  float stdv;
  float average = FindAverage(array, size);
  int i;
  for (i = 0; i < size; ++i){
    sumForStdv += pow((array[i] - average),2 );
  }
  stdv = sqrt(sumForStdv / size);
  return stdv; 
}
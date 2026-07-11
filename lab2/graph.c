/*
Name: Sviatoslav Oleksiienko
Section: lab section 02
Assignment: Lab 2. Part 3: ASCII Plot 
Purpose: Creates the graph using the ASKII characters for the function y = 13 * (1 + cos(1.0/2.0 * x)).
The program also displays extreme points (min and max).

*/
#include <stdio.h>
#include <math.h>

float myMathF(float x){
    //Computes my custom function based on the x and returns y value
    float y = 13 * (1 + cos(1.0/2.0 * x));
    return y;
}

char * graphLine(float currentValue, float minPossibleV, float maxPossibleV, float accuracyValue){
    /*The function returns a string that represent the ASKII lines on the graph
    it splits the graph values into 10 groups, and each group has an increment of symbol
    "#" by one, based on the possible min and max values. If the user uses the current number that is above
    the max possible, it would return 11 symbols.
   
   */ 
    float deviation = maxPossibleV - minPossibleV;
    float firstBoundary = minPossibleV + ( 1.0/10.0 * deviation);
    float secondBoundary = minPossibleV + (2.0/10.0 * deviation);
    float thirdBoundary = minPossibleV + (3/10.0 * deviation);
    float fourthBoundary = minPossibleV + (4/10.0 * deviation);
    float fifthBoundary = minPossibleV + (5/10.0 * deviation);
    float sixthBoundary = minPossibleV + (6/10.0 * deviation);
    float seventhBoundary = minPossibleV + (7/10.0 * deviation);
    float eighthBoundary = minPossibleV + (8/10.0 * deviation);
    float ninthBoundary = minPossibleV + (9/10.0 * deviation);
    float tenthBoundary = minPossibleV + (10/10.0 * deviation);
// Because of imperfaction of == with floats, I used the method that relies on the accuracy of the difference between them determined by accuracyValue 
    if (((currentValue > minPossibleV) || (fabs(currentValue - minPossibleV) < accuracyValue)) && 
        (currentValue < firstBoundary)) {
        return "#";
    } else if (((currentValue > firstBoundary) || (fabs(currentValue - firstBoundary) < accuracyValue)) && 
               (currentValue < secondBoundary)) {
        return "##";
    } else if (((currentValue > secondBoundary) || (fabs(currentValue - secondBoundary) < accuracyValue)) && 
               (currentValue < thirdBoundary)) {
        return "###";
    } else if (((currentValue > thirdBoundary) || (fabs(currentValue - thirdBoundary) < accuracyValue)) && 
               (currentValue < fourthBoundary)) {
        return "####";
    } else if (((currentValue > fourthBoundary) || (fabs(currentValue - fourthBoundary) < accuracyValue)) && 
               (currentValue < fifthBoundary)) {
        return "#####";
    } else if (((currentValue > fifthBoundary) || (fabs(currentValue - fifthBoundary) < accuracyValue)) && 
               (currentValue < sixthBoundary)) {
        return "######";
    } else if (((currentValue > sixthBoundary) || (fabs(currentValue - sixthBoundary) < accuracyValue)) && 
               (currentValue < seventhBoundary)) {
        return "#######";
    } else if (((currentValue > seventhBoundary) || (fabs(currentValue - seventhBoundary) < accuracyValue)) && 
               (currentValue < eighthBoundary)) {
        return "########";
    } else if (((currentValue > eighthBoundary) || (fabs(currentValue - eighthBoundary) < accuracyValue)) && 
               (currentValue < ninthBoundary)) {
        return "#########";
    } else if (((currentValue > ninthBoundary) || (fabs(currentValue - ninthBoundary) < accuracyValue)) && 
               (currentValue < tenthBoundary)) {
        return "##########";
    } else {
        // For values greater than tenthBoundary
        return "##########";
    }

}


int main(){
    //Variable initialization
    float xMin = 0.0;
    float xMax = 30.2;
    float maxIndex = 0.0;
    float minIndex = 0.0;
    float incremValue = 0.2;
    float tolleranceValue = 3e-3; //needed to solve the float comparion problem (== or <= or >= wouldn't work great for floats), shows how accurate the comparison will be 
    float i; // to maintain a convention, will be used in for loop
    float tempValue;
    

    // Used to compare the values later to find the max and min
    float minValue = myMathF(xMin);
    float maxValue = myMathF(xMin);


    // Program header
    printf("Plot for y = 13 * (1 + cos(1.0/2.0 * x)) from %.2f to %.2f\n", xMin, xMax);
 
    // First, I want to find the max and min value in order to find the scale for printing

    for (i = xMin + incremValue; i <= xMax; i+=incremValue){   
        tempValue = myMathF(i);
       // Determening max and min values 
        if (tempValue > maxValue){ 
            maxValue = tempValue;
            maxIndex = i; 
        }
        if (tempValue < minValue){
            minValue = tempValue;
            minIndex = i;
        }

    }

    // Printing the talbe and the graph
    printf("X\t Y\n"); //header 
    for (i = xMin; (i < xMax) || (fabs(i-xMax) < tolleranceValue); i+=incremValue){     
        tempValue = myMathF(i);
        printf("%.2f\t %.2f\t",i,tempValue);
        char * currestLine = graphLine(tempValue, minValue, maxValue, tolleranceValue); // calling the function to get the line for the current values
        printf("%s\n", currestLine);
        
    }
    // Priting the results about the max and min values and one of their locations on the graph
    printf("The maximum is %.2f at %.2f\n",maxValue,maxIndex);
    printf("The minimum is %.2f at %.2f\n", minValue, minIndex);

    return 0;
}

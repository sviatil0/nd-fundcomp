/*
Name: Sviatoslav Oleksiienko
Lab-section: 02
Assignment: Part 1 Distance
Purpose: A program that find finds the distance length of a path through a sequence of points in an x-y plane, and print out the points.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
 
typedef struct{
    float x;
    float y;
} Points;

//Functions prototypes
void readFileName(char[], int);
float findDistanceLengthBetweenTwoPoints(Points, Points);
int ReadPointsFromFile(FILE*, Points[]);
void PrintPoints(Points[],int);
float FindTotalDistance(Points[],int);

int main(){
    int maxFileNameSize = 30;
    int maxNumberOfPoints = 30;
    int pointsNumber;
    FILE* openedFile;
    char fileName[maxFileNameSize];
    Points userPoints[maxNumberOfPoints];

    // Get file name
    readFileName(fileName,maxFileNameSize);
    // Open the file
    openedFile = fopen(fileName,"r");

    if (openedFile == NULL){
        printf("Failed to open the file.");
        return -1;
    }

    // Read points from file
    pointsNumber = ReadPointsFromFile(openedFile,userPoints);

    // Print the points from the data structure
    PrintPoints(userPoints, pointsNumber);

    // Find total distance 
    
    //Close the file
    fclose(openedFile);
}


float FindTotalDistance(Points userPoints[],int length){
    int i;
    float totalDistance = 0;

    for(i = 0; i < length -1; ++i){
        totalDistance+= findDistanceLengthBetweenTwoPoints(userPoints[i],userPoints[i+1]); 
    }
    return totalDistance;
}
void PrintPoints(Points userPoints [], int length){
    int i;
    float totalLength = FindTotalDistance(userPoints,length);
    printf("There are %d points:\n\n",length);
    printf("    x   |   y    \n");
    printf("--------+--------\n");

    for (i= 0; i < length; ++i){
        
        printf("%7g | %7g\n",userPoints[i].x,userPoints[i].y);
    }
    printf("\nThe length of the path through them is %.2f\n", totalLength);


}
void readFileName(char fileNameString[], int maxSize){
    printf("Plese enter your file name:\n");
    fgets(fileNameString,maxSize,stdin);
    fileNameString[strlen(fileNameString) -1 ] = '\0';
}

int ReadPointsFromFile(FILE* openedFile, Points pointsArray []){
    int i = 0;
    int counter = 0;

    for (i = 0; !feof(openedFile); ++i){
        counter++;
        fscanf(openedFile, "%f %f",&pointsArray[i].x,&pointsArray[i].y); 
    }
    return counter;
}

float findDistanceLengthBetweenTwoPoints(Points firstPoint, Points secondPoint){
    float distance = sqrt(pow((firstPoint.x-secondPoint.x),2) + pow((firstPoint.y-secondPoint.y),2));
    return distance;
}

/*
Name: Sviatoslav Oleksiienko
Lab section: 02
Assignment: Part 3: ND football
Purpose:  a program that has the wins and losses data stored into arrays, and provides a user with a menu of questions on the data. It allows to dipslay the record for a given year, the number of years with at least of some number loses or wins, compare two years for their wins and losses, see the total number of wins and losses for the whole dataset, and see the number of wins and losses between the provided years.
*/

#include <stdio.h>
#include "nd_data.h" // Includes win[] and loses[]
#include <stdbool.h> //needed to create a boolean flag

// Functions prototypes
// basic functions
void DisplayRecordForAYear(int year);
void DisplayYearsWithAtLeastNWins(int n);
void DisplayYearsWithAtLeastNLosses(int n);
void PrintMenuOptions();

// my own functionality
void DisplayTotalNumberOfWinsBetweenTheYears(int year1, int year2);
void DisplayTotalNumberOfLossesBetweenTheYears(int year1, int year2);
void CompareTwoYears(int year1, int year2);
void DisplayTotalNumberOfLossesAndWins();

int main()
{
    bool isFinished = false;
    int choice;
    int year;
    int minNumber;
    int year1,year2;
    while (!isFinished)
    {
        PrintMenuOptions();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Pleae enter the year: ");
            scanf("%d", &year);
            DisplayRecordForAYear(year);
            break;
        case 2:
            printf("Enter minimum number of losses: ");
            scanf("%d", &minNumber);
            DisplayYearsWithAtLeastNLosses(minNumber);
            break;
        case 3:
            printf("Enter minimum number of wins: ");
            scanf("%d", &minNumber);
            DisplayYearsWithAtLeastNWins(minNumber);
            break;
        case 4:
            printf("Enter year1 and year2: ");
            scanf("%d %d",&year1,&year2);
            DisplayTotalNumberOfWinsBetweenTheYears(year1,year2);
            break;
        case 5:
            printf("Enter year1 and year2: ");
            scanf("%d %d",&year1,&year2);
            DisplayTotalNumberOfLossesBetweenTheYears(year1,year2);
            break;
        case 6:
            DisplayTotalNumberOfLossesAndWins();
            break;
        case 7: 
            printf("Enter year1 and year2: ");
            scanf("%d %d",&year1,&year2);
            CompareTwoYears(year1,year2);
            break;
        case 8:
            printf("Good bye!\n");
            isFinished = true;
            break;
        default:
            printf("Invalid input, try again.\n\n");
            break;
        }
    }
    return 0;
}

void DisplayRecordForAYear(int year)
{
    int winsNumber = wins[year - 1900]; // needed to accomodate the arrays size
    int lossesNumber = losses[year - 1900];
    printf("Wins: %d, Loses: %d", winsNumber, lossesNumber);
    printf("\n\n");

}

void DisplayYearsWithAtLeastNWins(int n)
{
    int i;
    int size = sizeof(wins) / sizeof(wins[0]);
    int tempYear;
    printf("Years with at least %d wins: ", n);
    for (i = 0; i < size; ++i)
    {
        if (wins[i] >= n)
        {
            tempYear = i + 1900;
            printf("%d ", tempYear);
        }
    }
    printf("\n\n");
}

void DisplayYearsWithAtLeastNLosses(int n)
{
    int i;
    int size = sizeof(losses) / sizeof(losses[0]);
    int tempYear;
    printf("Years with at least %d losses: ", n);
    for (i = 0; i < size; ++i)
    {
        if (losses[i] >= n)
        {
            tempYear = i + 1900;
            printf("%d ", tempYear);
        }
    }
    printf("\n\n");
}

void PrintMenuOptions()
{
    printf("1: display the record for a given year.\n");
    printf("2: display years with at least \"n\" losses.\n");
    printf("3: display years with at least \"n\" wins.\n");
    printf("4: display total number of wins between \"year1\" and \"year2\" (inclusive year1 and year2).\n");  
    printf("5: display total number of losses between \"year1\" and \"year2\" (inclusive year1 and year2).\n");
    printf("6: display total number of losses and wins for the whole dataset.\n");
    printf("7: diplays the values of losses and wins for two years to compare them.\n");
    printf("8: exit.\n");
    printf("Enter your choice: ");
}


void DisplayTotalNumberOfWinsBetweenTheYears(int year1, int year2) {
    // Displays the total number of wins between the year1 and year2 (inclusive year1 and year2)
    int temp; 
    if (year2 > year1){
       temp = year2;
       year2 = year1;
       year1 = temp; 
    }

    int totalWins = 0;
    int startIndex = year2-1900-1;
    int endIndex = year1-1900-1;
    int i;

    for (i = startIndex; i <= endIndex; ++i){
        totalWins += wins[i];
    }
    printf("Total number of wins between %d and %d is %d.",  year2, year1, totalWins);
    printf("\n\n");
    
}
void DisplayTotalNumberOfLossesBetweenTheYears(int year1, int year2){

    int temp; 
    if (year2 > year1){
       temp = year2;
       year2 = year1;
       year1 = temp; 
    }

    int totalLosses = 0;
    int startIndex = year2-1900-1;
    int endIndex = year1-1900-1;
    int i;

    for (i = startIndex; i <= endIndex; ++i){
        totalLosses += losses[i];
    }
    printf("Total number of losses between %d and %d is %d.",  year2, year1, totalLosses);
    printf("\n\n");
    
}
void CompareTwoYears(int year1, int year2){
    int year1Losses = losses[year1-1900-1];
    int year2Losses = losses[year2-1900-1];

    int year1Wins = wins[year1-1900-1];
    int year2Wins = wins[year2-1900-1];

    printf("%d had %d losses, while %d had %d losses.\n",year1,year1Losses,year2,year2Losses);
    printf("%d had %d wins, while %d had %d wins.", year1,year1Wins,year2,year2Wins);
    printf("\n\n");
}
void DisplayTotalNumberOfLossesAndWins(){
    // Display the total nubmer of losses and wins for the whole dataset
    int totalLoses = 0;
    int totalWins = 0;
    int i;
    const int ARRAY_LENGTH = sizeof(wins) / sizeof(wins[0]);
    int firstYear = 1900;
    int lastYear = 1900 + ARRAY_LENGTH;

    for (i = 0; i  <ARRAY_LENGTH; ++i){
        totalLoses += losses[i];
        totalWins += wins[i];
    }
    printf("Since %d up until %d there have been %d losses and %d wins.", firstYear,lastYear,totalLoses,totalWins);
    printf("\n\n"); 
}
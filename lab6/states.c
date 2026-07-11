/*
Name: Sviatoslav Oleksiienko
Lab-section: 02
Assignment: Part 2: US States and Capitals 
Purpose: a program that will provide an educational tool for middle schoolers where they can learn some basic information about the US states. 
*/

//These are estimates and the ones that are for strings account for the null character
#define MAX_STATE_NAME_LENGTH 21
#define ABBREVIATION_LENGTH 3
#define MAX_STATE_CAPITAL_LENGTH 21
#define MAX_DATABASE_LINE_LENGTH 46
#define MAX_FILE_NAME_SIZE 21

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char abbreviation[ABBREVIATION_LENGTH];
    char name[MAX_STATE_NAME_LENGTH];
    char capital[MAX_STATE_CAPITAL_LENGTH];
    int year;
} State;

//Functions protypes
State SplitAStringAndFormState(char stringFromTheDatabase[], char delimeters[]);
void GetFileName(char name[]);
int ReadStatesFromFile(State states[], FILE* openedFile, char delimeters[]);
void PrintMenuOptions();
void PrintInformationAboutAllStates(State states[], int size);
void ListStatesInfoBasedOnAbbreviation(char abbreviation[], State states[], int size);
void NormalizeCaseForAbb(char abbreviation[]);
void GetLineInput(char line[]);
void PrintStatesCapitalBasedOnAbb(char abbreviation[], State states[], int size);
void NormalizeCaseForName(char name[]);
void PrintStatesCapitalBasedOnName(char name[], State states[], int size);
void ListStatesInfoBasedOnYear(int year, State states[], int size);
void ListStatesInfoBasedOnYearAfter(int year, State states[], int size);
void ListStatesInfoBasedOnYearBefore(int year, State states[], int size);
void sortStatesBasedOnYear(State states[], int size);
void swap(State* st1, State* st2);

int main(){

    //Initialize variables
    char delimeters[] = ","; // Since csv is the format of the data file
    char fileName[MAX_FILE_NAME_SIZE];
    const int maxNumberOfStates = 100;
    State states[maxNumberOfStates];
    char inputedAbb[ABBREVIATION_LENGTH];
    char inputedName[MAX_STATE_NAME_LENGTH];
    FILE* openedFile;
    bool isFinished = false;
    int choice;
    int numberOfStates;
    int tempYear; 
    // Get the file name
    GetFileName(fileName);
    // Open the file
    openedFile = fopen(fileName,"r");

    if(openedFile == NULL) {
        printf("Error. Couldn't open the fie\n");
        return -1;
    }

    numberOfStates = ReadStatesFromFile(states, openedFile, delimeters);
    while(!isFinished){
    PrintMenuOptions();
    printf("\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
        printf("\n\n");
           PrintInformationAboutAllStates(states, numberOfStates);

        printf("\n\n");
            break;
        case 2:

        printf("\n\n");
            printf("Please input state's abbreviation:\n");
            GetLineInput(inputedAbb);
            NormalizeCaseForAbb(inputedAbb);
            ListStatesInfoBasedOnAbbreviation(inputedAbb, states, numberOfStates);
            inputedAbb[0] = '\0';
        printf("\n\n");
            break;

        case 3:
            
        printf("\n\n");

            printf("Please input state's abbreviation:\n");
            GetLineInput(inputedAbb);
            NormalizeCaseForAbb(inputedAbb);
            PrintStatesCapitalBasedOnAbb(inputedAbb, states, numberOfStates);
            inputedAbb[0] = '\0';
            printf("\n\n");
            break;
        case 4:
            printf("\n\n");
            printf("Please input state's name:\n");
            GetLineInput(inputedName);
            NormalizeCaseForName(inputedName);
            PrintStatesCapitalBasedOnName(inputedName, states, numberOfStates);
            inputedName[0] = '\0';
            printf("\n\n");
            break;
        case 5:
            printf("\n\n");
            printf("Please enter the year number: ");
            scanf("%d",&tempYear); 
            ListStatesInfoBasedOnYear(tempYear, states, numberOfStates);
            printf("\n\n");
            break;
        case 6:
            printf("\n\n");
            printf("Please enter the year number: ");
            scanf("%d",&tempYear); 
            ListStatesInfoBasedOnYearBefore(tempYear, states, numberOfStates);
            printf("\n\n");
            break;
        case 7: 
            printf("\n\n");
            printf("Please enter the year number: ");
            scanf("%d",&tempYear); 
            ListStatesInfoBasedOnYearAfter(tempYear, states, numberOfStates);
            printf("\n\n");
            break;
        case 8:            
            printf("\n\n");
            sortStatesBasedOnYear(states, numberOfStates);
            PrintInformationAboutAllStates(states, numberOfStates);
            printf("\n\n");
            break;
        case 9:
            isFinished = true;
            break;
        default:
            printf("Invalid input. Please, try again.");
    }
    }

    // Close the file
    fclose(openedFile);
    return 0;
}

void sortStatesBasedOnYear(State states[], int size){
    //Sorts the array based on years of joining the union
   int i;
   bool isSorted = false;

   while(!isSorted) {
        isSorted = true;
     for(i = 0; i < size-1; ++i){
        if(states[i].year > states[i+1].year){
            swap(&states[i], &states[i+1]);
            isSorted = false;
        }
     }
   }
}
void swap(State* st1, State* st2){
    // Swaps two values in the array. Needed to sort the State array
    State temp = *st1;
    *st1 = *st2;
    *st2 = temp; 
}
void NormalizeCaseForName(char name[]){
    //Normalizes the case for the name (makes first cap and other lowercase)
    name[0] = toupper(name[0]);
    int i;
    for(i=1; i<strlen(name); ++i){
        name[i] = tolower(name[i]);
    }
}
void PrintStatesCapitalBasedOnName(char name[], State states[], int size){
    //Prints states capital based on its name
   int i;
   for (i=0; i < size; ++i){
    if(strcmp(states[i].name,name) ==0) printf("Capital: %s\n",states[i].capital);
   }
}
void PrintStatesCapitalBasedOnAbb(char abbreviation[], State states[], int size){
//Prints states capital based on abbreviation
   int i;
   for (i=0; i < size; ++i){
    if(strcmp(states[i].abbreviation,abbreviation) ==0) printf("Capital: %s\n",states[i].capital);
   }

}
void NormalizeCaseForAbb(char abbreviation[]){
    // Normalizes the case for the abbreviation. Makes it all caps
    int i;
    for (i = 0; i < strlen(abbreviation); ++i){
        abbreviation[i] = toupper(abbreviation[i]);
    }

}
void GetLineInput(char line[]){
    // Used for user input of abbreviation, state name, etc.
    getchar();
    fgets(line, MAX_STATE_CAPITAL_LENGTH, stdin); //use the capital length becase its the longest possible input for one unit of information
    if(line[strlen(line)-1] == '\n') line[strlen(line) - 1] =  '\0';
}

void ListStatesInfoBasedOnYear(int year, State states[], int size){
    // Prints states which year is equal to the given one
   int i;
    printf("               State Abbreviation              Capital Year Joined The Union\n");
    printf("-------------------------------------------------------------------------------\n");
   for (i=0; i < size; ++i){
    if(year == states[i].year)  printf("%21s%12s%21s %21d\n",states[i].name,states[i].abbreviation,states[i].capital, states[i].year);
   }
}

void ListStatesInfoBasedOnYearBefore(int year, State states[], int size){
    // Prints states which year is lower than the given one
   int i;
    printf("               State Abbreviation              Capital Year Joined The Union\n");
    printf("-------------------------------------------------------------------------------\n");
   for (i=0; i < size; ++i){
    if( states[i].year < year)  printf("%21s%12s%21s %21d\n",states[i].name,states[i].abbreviation,states[i].capital, states[i].year);
   }
}

void ListStatesInfoBasedOnYearAfter(int year, State states[], int size){
    //Prints states which year is higher than the given one
   int i;
    printf("               State Abbreviation              Capital Year Joined The Union\n");
    printf("-------------------------------------------------------------------------------\n");
   for (i=0; i < size; ++i){
    if( states[i].year > year)  printf("%21s%12s%21s %21d\n",states[i].name,states[i].abbreviation,states[i].capital, states[i].year);
   }
}
void ListStatesInfoBasedOnAbbreviation(char abbreviation[], State states[], int size){
    //Prints states that fit the abbreviation
   int i;
    printf("               State Abbreviation              Capital Year Joined The Union\n");
    printf("-------------------------------------------------------------------------------\n");
   for (i=0; i < size; ++i){
    if(strcmp(states[i].abbreviation,abbreviation) ==0) printf("%21s%12s%21s %21d\n",states[i].name,states[i].abbreviation,states[i].capital, states[i].year);
   }
}
void PrintInformationAboutAllStates(State states[], int size){
    //Print the information about all the states
   int i;

    printf("               State Abbreviation              Capital Year Joined The Union\n");
    printf("-------------------------------------------------------------------------------\n");
   for (i=0; i < size; ++i){
    printf("%21s%12s%21s %21d\n",states[i].name,states[i].abbreviation,states[i].capital, states[i].year);
   }
}
void PrintMenuOptions(){
    // Prints menu options
    printf("1 - list all data\n");
    printf("2 - list a state's info based on its abbreviation\n");
    printf("3 - list a state's capital based on its abbreviation\n"); 
    printf("4 - list a state's capital based on its name\n");
    printf("5 - list states who joined a given year\n");
    printf("6 - list states who joined before a given year\n");
    printf("7 - list states who joined after a given year\n");
    printf("8 - list states in states in the order of joing the union\n");
    printf("9 - exit\n");
}
int ReadStatesFromFile(State states[], FILE* openedFile, char delimters[]){
    // Reads states from the file 
    int counter = 0;
    char tempStr[MAX_DATABASE_LINE_LENGTH];

    while(fgets(tempStr,MAX_DATABASE_LINE_LENGTH, openedFile) != NULL){
        counter++;
        if (tempStr[strlen(tempStr) -1] == '\n') tempStr[strlen(tempStr)-1] = '\0';
        states[counter -1]  = SplitAStringAndFormState(tempStr, delimters);
        tempStr[0] = '\0';
    }

    return counter;
}
void GetFileName(char name[]){
    // The function reads the file name from CLI input
    printf("Please, enter file name:\n");
    fgets(name,MAX_FILE_NAME_SIZE,stdin);

    name[strlen(name)-1] = '\0';
}
State SplitAStringAndFormState(char stringFromTheDatabase[], char delimeters[]){
    // The function splits a string based on the delimeter and place the values into State format
    // we will assume that the database is valid
   State state;
   char *token;
   char *saveptr;
   int year;
   token = strtok_r(stringFromTheDatabase, delimeters, &saveptr);
   if (token == NULL) printf("Error with the database\n");
   else strcpy(state.abbreviation, token); 


   token = strtok_r(NULL, delimeters, &saveptr);
   if (token == NULL) printf("Error with the database\n");
   else strcpy(state.name, token); 


   token = strtok_r(NULL, delimeters, &saveptr);
   if (token == NULL) printf("Error with the database\n");
   else strcpy(state.capital, token); 


   token = strtok_r(NULL, delimeters, &saveptr);
   if (token == NULL) printf("Error with the database\n");
   else {
    year = atoi(token);
    state.year = year; 
   }

   return state;
}

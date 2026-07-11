/*
Name: Sviatoslav Oleksiienko
Section: Lab 02
Assignment: Part 2: A sayings manager
Purpose: a program that store and manage many of your favorite sayings; they could be movie quotes, lines from songs, proverbs, adages, etc.; basically any memorable lines you can think of.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{ // needed to return both array and totla elements from the function
    char **array;
    int totalElements;
} ArrayResult;
// Functions prototypes
void PrintMenuOptions();
char *GetFileName(int);
ArrayResult ReadSayingsFromFile(FILE *, int, int);
void DisplayTheDatabase(ArrayResult, int);
void GetStringFromCLI(char[], int);
void ListSayingsContainingSubstr(char[], int, char **);
void EnterInformationIntoTheFile(FILE *, char **, int, int);
int main()
{
    // Variables initialization
    int i;
    int optionSelected;
    FILE *startupFile;
    FILE *newFile;
    bool isFinished = false;
    const int fileNameMaxSize = 31; // accomodates the null character
    char *fileName;
    ArrayResult resultedArray;
    // For the main data structure - string array
    const int oneStringMaxSize = 257; // for the null character is accounted later
    const int maxNumberOfSayings = 50;
    char **arraySayings;
    int arraySayingsSize;
    char tempStringForCLIEnter[oneStringMaxSize];
    char *newFileName;
    // Openning and reading the startup file
    fileName = GetFileName(fileNameMaxSize);
    printf("\n");
    startupFile = fopen(fileName, "r");

    if (startupFile == NULL)
    {
        printf("Failed to open the file.\n");
        printf("Check the file name entered and try again.\n");
        return -1;
    }

    resultedArray = ReadSayingsFromFile(startupFile, oneStringMaxSize, maxNumberOfSayings);
    arraySayings = resultedArray.array;
    arraySayingsSize = resultedArray.totalElements;

    // Start the main loop to ask user for the commands
    while (!isFinished)
    {
        PrintMenuOptions();
        scanf("%d", &optionSelected);
        switch (optionSelected)
        {
        case 1:
            printf("\n\n");
            DisplayTheDatabase(resultedArray, oneStringMaxSize);
            printf("\n\n");
            break;
        case 2:
            printf("\n\n");
            GetStringFromCLI(tempStringForCLIEnter, oneStringMaxSize);
            strcpy(arraySayings[arraySayingsSize - 1], tempStringForCLIEnter);
            arraySayingsSize++;
            tempStringForCLIEnter[0] = '\0'; // making a string empty
            printf("\n\n");
            break;
        case 3:
            printf("\n\n");
            GetStringFromCLI(tempStringForCLIEnter, oneStringMaxSize);
            printf("These sayings contain selected substring:\n");
            ListSayingsContainingSubstr(tempStringForCLIEnter, arraySayingsSize, arraySayings);
            printf("\n\n");
            break;
        case 4:
            printf("\n\n");
            getc(stdin); // clear the buffer
            newFileName = GetFileName(fileNameMaxSize);
            newFile = fopen(newFileName, "w");
            newFileName[0] = '\0'; //cleares it so that I can reuse it
            if (newFile == NULL)
            {
                printf("Failed to create a new file.\n");
                return -1;
            }
            EnterInformationIntoTheFile(newFile, arraySayings, arraySayingsSize, oneStringMaxSize);
            fclose(newFile);
            free(newFileName);
            printf("\n\n");
            break;
        case 5:
            isFinished = true;
            break;
        default:
            printf("\n\n");
            printf("Invalid input, try again.\n");
            printf("\n\n");
            break;
        }
    }

    // Freeing memory
    fclose(startupFile);
    free(fileName);
    for (i = 0; i < maxNumberOfSayings; ++i)
    {
        free(arraySayings[i]);
    }
    free(arraySayings);
    return 0;
}

void EnterInformationIntoTheFile(FILE *file, char **array, int arraySize, int strMaxSize)
{
    int i;
    char tempStr[strMaxSize];
    for (i = 0; i < arraySize; ++i)
    {
        strcpy(tempStr,array[i]);
        fprintf(file, "%s", tempStr);
        tempStr[0] = '\0';

        if(i < arraySize-2 ) fprintf(file,"\n");
    }
}
void ListSayingsContainingSubstr(char substr[], int size, char **sayings)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        if (strstr(sayings[i], substr) != NULL)
        {
            printf("%s\n", sayings[i]);
        }
    }
}
void GetStringFromCLI(char line[], int maxLineSize)
{
    printf("Your input: ");
    fgetc(stdin); // clear the buffer from new line character
    fgets(line, maxLineSize, stdin);
    line[strlen(line) - 1] = '\0';
}
void PrintMenuOptions()
{
    printf("1. display all sayings currently in the database.\n");
    printf("2. enter a new saying into the database.\n");
    printf("3. list sayings that contain a given substring entered by the user.\n");
    printf("4. save all sayings in a new text file\n");
    printf("5. quit the program. \n");
    printf("Please enter your choice: ");
}
void DisplayTheDatabase(ArrayResult arrayAndLength, int maxCharactersInString)
{
    int arrayLength = arrayAndLength.totalElements;
    char **arrayLines = arrayAndLength.array;
    char tempString[maxCharactersInString];
    int i;

    for (i = 0; i < arrayLength; ++i)
    {
        strcpy(tempString, arrayLines[i]);
        printf("%s\n", tempString);
    }
}
ArrayResult ReadSayingsFromFile(FILE *openedFile, int maxLineSize, int maxLineNumber)
{
    int i;
    int numLines = 0;
    ArrayResult result;
    char tempString[maxLineSize];
    if (openedFile == NULL)
    {
        printf("Error accessing the file");
        result.array = NULL;
        result.totalElements = -1;
        return result;
    }

    char **linesArray = (char **)malloc(sizeof(char *) * maxLineNumber); // allocating dynamic two dimensional array
    // Allocating space for each string in the array of strings

    if (linesArray == NULL)
    {
        printf("Memmory allocation failed");
        result.array = NULL;
        result.totalElements = -1;
        return result;
    }
    for (i = 0; i < maxLineNumber; ++i)
    {
        linesArray[i] = (char *)malloc(sizeof(char) * (maxLineSize));
        if (linesArray[i] == NULL)
        {
            printf("Memmory allocation failed");
            result.array = NULL;
            result.totalElements = -1;
            return result;
        }
    }

    for (i = 0; i < maxLineNumber && !feof(openedFile); ++i)
    {
       if(fgets(tempString, maxLineSize, openedFile) == NULL) break;
        numLines++;
        if (tempString[strlen(tempString) - 1] == '\n')
        {
            tempString[strlen(tempString) - 1] = '\0';
        }
        strcpy(linesArray[i], tempString);
        tempString[0] = '\0';
    }
    result.array = linesArray;
    result.totalElements = numLines;
    return result;
}
char *GetFileName(int maxSize)
{
    // Used to get a file name from the input and returns a pointer(a string) for the file name
    char *fileName = (char *)malloc(sizeof(char) * (maxSize + 1)); // a dynamic array initialization, maxSize +1 to account for null character
    if (fileName == NULL)
    {
        printf("Memory not allocated");
        return NULL;
    }
    int fileNameLength;
    printf("Please enter the file name: ");
    fgets(fileName, maxSize, stdin);
    fileNameLength = strlen(fileName);

    if (fileName[fileNameLength - 1] == '\n')
    {
        fileName[fileNameLength - 1] = '\0';
    }
    return fileName;
}
    
    
/*
Name: Sviatoslav Oleksiienko
Section: Lab 02
Assignment: Part 1: Justifying Scrabble's letter point values
Purpose: Count the frequencies of appearance of the each letter of the alphabet in the txt file.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Functions Prototypes
char *GetFileName(int maxSize);
int *PreallocateWithZeros(int size);
void PrintGeneralResults(char *fileName, int totalC, int totalNumLet);

int main()
{
    // Initialize the variables
    FILE *readFile;
    const int alphSize = 26;
    const int maxFileNameSize = 30;
    int *frequencies;
    char *fileName;
    char firstLetterInTheAlph = 'a';
    char tempChar;
    char lowerTempChar;
    int letterCorrespondingNumber;
    int i;
    int totalCharacters = 0;
    int totalNumberOfLetters = 0;
    float percentageForLetter;

    // Get the file name
    fileName = GetFileName(maxFileNameSize);
    // Open the file
    readFile = fopen(fileName, "r");

    if (readFile == NULL)
    {
        printf("Could not open the file!\n");
        return -1;
    }

    // Initialize the array of frequiencies with 0
    frequencies = PreallocateWithZeros(alphSize);
    // Start couting the number of letters
    while (!feof(readFile))
    {
        tempChar = fgetc(readFile);
        if (tempChar != EOF){

         totalCharacters++;
        if (isalpha(tempChar))
        {
            totalNumberOfLetters++;
            if (isupper(tempChar))
            {

                lowerTempChar = tolower(tempChar);
            }
            else
            {

                lowerTempChar = tempChar;
            }
            letterCorrespondingNumber = lowerTempChar - firstLetterInTheAlph;
            frequencies[letterCorrespondingNumber] += 1;
        }
        }
    }

    // Output the list of frequencies
    // General Infromation
    PrintGeneralResults(fileName, totalCharacters, totalNumberOfLetters);
    // Output of counts
    printf("Letter counts:\n");
    for (i = 0; i < alphSize; ++i)
    {
        tempChar = firstLetterInTheAlph + i;
        printf("%3c:%7d", tempChar, frequencies[i]);
        if ((i + 1) % 6 == 0)
        {
            printf("\n");
        }
    }
    printf("\n\n");

    // Output of percentages:
    printf("Letter percentages:\n");
    for (i = 0; i < alphSize; ++i)
    {
        tempChar = firstLetterInTheAlph + i;
        percentageForLetter = (float)frequencies[i] / totalNumberOfLetters * 100.0;

        printf("%3c:%5.1f%%", tempChar, percentageForLetter);
        if ((i + 1) % 6 == 0)
        {
            printf("\n");
        }
    }
    printf("\n\n");
    fclose(readFile);
    free(fileName); // Frees the pointer to a first element in the string
    free(frequencies);
    return 0;
}

char *GetFileName(int maxSize)
{
    // Used to get a file name from the input and returns a pointer(a string) for the file name
    char *fileName = (char *)malloc(sizeof(char) * (maxSize + 1)); // a dynamic array initialization, maxSize +1 to account for null character
    if (fileName == NULL){
        printf("Memory not allocated");
        return NULL;
    }
    int fileNameLength;
    printf("Please enter the file name: ");
    fgets(fileName, 30, stdin);
    fileNameLength = strlen(fileName);

    if (fileName[fileNameLength - 1] == '\n')
    {
        fileName[fileNameLength - 1] = '\0';
    }
    return fileName;
}
int *PreallocateWithZeros(int size)
{
    // Returns an array with zeros preallocated for a given size
    int i;
    int *array = (int *)malloc(sizeof(int) * size);
    if (array == NULL){
        printf("Memory not alocated");
        return NULL;
    }
    for (i = 0; i < size; i++)
    {
        array[i] = 0;
    }
    return array;
}

void PrintGeneralResults(char *fileName, int totalC, int totalNumLet)
{
// Prints general results after analyzing the characters on the txt file
    printf("General summary for %s:\n", fileName);
    printf("    there were %d total characters\n", totalC);
    printf("    there were %d letters\n", totalNumLet);
}
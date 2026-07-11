/* Name: Sviatoslav Oleksiienko
Section: lab 02
Assignment: Part 3 text menu calculator
Purpose: This program acts as a  text menu-driven basic calculator for the four simple arithmetic operations:
add, subtract, multiply, divide.
*/

#include <stdio.h>
#include <stdbool.h> //needed to create a flag for the program

void displayAdd(double, double);
void displaySubtract(double, double);
void displayMultiply(double, double);
void displayDivide(double, double);

int main()
{
    bool finishProgram = false;
    int command;
    double first, second;
    while (!finishProgram)
    {
        printf("What would you like to do?\n");
        printf(" 1 for addition\n");
        printf(" 2 for subtraction\n");
        printf(" 3 for multiplication\n");
        printf(" 4 for division\n");
        printf(" 5 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &command);
        if (command == 5)
        {
            finishProgram = true;
            printf("Good bye!\n");
        }
        else
        {

            switch (command)
            {
            case 1:

                printf("Please, enter two numbers: ");
                scanf("%lf %lf", &first, &second);
                displayAdd(first, second);
                break;
            case 2:

                printf("Please, enter two numbers: ");
                scanf("%lf %lf", &first, &second);
                displaySubtract(first, second);
                break;
            case 3:

                printf("Please, enter two numbers: ");
                scanf("%lf %lf", &first, &second);
                displayMultiply(first, second);
                break;
            case 4:

                printf("Please, enter two numbers: ");
                scanf("%lf %lf", &first, &second);
                displayDivide(first, second);
                break;
            default:
                printf("Invalid input, please try again!\n");
            }
            printf("\n");
        }
    }
    return 0;
}

void displayAdd(double num1, double num2)
{
    // Displays the result of addition num1 and num2
    double result = num1 + num2;
    printf("(%.2lf) + (%.2lf) = %.2lf\n", num1, num2, result);
}

void displaySubtract(double num1, double num2)
{
    // displays the result of subtraction of num2 from num1
    double result = num1 - num2;
    printf("(%.2lf) - (%.2lf) = %.2lf\n", num1, num2, result);
}
void displayMultiply(double num1, double num2)
{
    // displyas the result of multiplication of num1 by num2
    double result = num1 * num2;
    printf("(%.2lf) * (%.2lf) = %.2lf\n", num1, num2, result);
}
void displayDivide(double num1, double num2)
{
    // displays the result of division of num1 by num2
    // if the user tries to divide by zero, the program
    // displays an error
    double result = num1 / num2;
    if (num2 == 0)
    {
        printf("Error. Division by zero.\n");
    }
    else
    {
        printf("(%.2lf) / (%.2lf) = %.2lf\n", num1, num2, result);
    }
}

/*
Name: Sviatoslav Oleksiienko
Section: lab section 02
Assignment: Lab 2. Part 2: Mortgage Calculator 
Purpose: Allow for the user to calculate the final cost
of the house that is assosiated with taking on morgage.
*/

#include <stdio.h>
#include <stdbool.h> //needed for the boolean type to work
int main(){
    // initializing the variables using the users input 
    float balance, intRate, monthlyP, totalPayed; 
    totalPayed = 0;
    int i;
    int yearsPaid,additionalMonthPaid;
    float trueMonthPay, montlyInterest; //needed for the loop
        //flags that are needed for error validation
        bool inputValidated = false;
        bool lowMontlyPayErrorOccured = false;
    //input validation  loop
        while(!inputValidated){
            
        printf("pricipal: ");
        scanf("%f", &balance);
        printf("\n");

        printf("interest rate: ");
        scanf("%f",&intRate);
        printf("\n");
        intRate = intRate/100; // needed to simplify calculations

        printf("montly payment: ");
        scanf("%f", &monthlyP);
        printf("\n");
        
        if (balance < 0 || intRate < 0 || monthlyP < 0){
            printf("invalid input. please try again.\n");

        } else{
            inputValidated = true;
        }
        }

    // working on creating a payment table
    printf("month\tpaymenet\tinterest\tbalance\n"); //header

    for (i = 1; balance > 0; ++i){
        montlyInterest = (intRate/12) * balance;
    if (montlyInterest >= monthlyP ){
        printf("Error. your desired monthly payment is too small. Your balance will only go up. restart the program to try again.\n");
        lowMontlyPayErrorOccured = true;        
        break;
    }


    if(monthlyP < balance){
            trueMonthPay = monthlyP;
            balance = balance - monthlyP + montlyInterest;
        } else{
            trueMonthPay = balance+montlyInterest;
            balance = 0;
            yearsPaid = i/12;
            additionalMonthPaid = i%12; 
        }
        totalPayed += trueMonthPay; 
        printf("%d\t$%.2f\t\t$%.2f\t\t$%.2f\n",i,trueMonthPay, montlyInterest, balance);        
    }
    if (!lowMontlyPayErrorOccured){
    printf("you paid %.2f in %d years and %d month.\n",totalPayed,yearsPaid,additionalMonthPaid);
    }
}




    

/*
*Name: Sviatoslav Oleksiienko
*Class: Lab section 02
*Assignment: Part 2: Formula Calculator
*Purpose: After the user inputs the value for the coefficients a,b,c, the program outputs the real solutions for the quadratic equation ax^2+bx+c=0 
*/



#include <stdio.h>
#include <math.h>

int main(){
	float a;
	float b;
	float c;
	printf("Please input a: ");
	scanf("%f",&a);
	printf("\n");

	printf("Please input b: ");
	scanf("%f",&b);
	printf("\n");

	printf("Plase input c: ");
	scanf("%f",&c);

	float D = pow(b,2) - (4*a*c);

	if (D > 0){
		float x1 = (-b+sqrt(D))/(2*a);
		float x2 =  (-b-sqrt(D))/(2*a);
		printf("x1: %f, x2: %f.\n",x1,x2);


	}else{

		if (D==0){
			float x = (-b)/(2*a);
			printf("x: %f.\n",x);
		}else {

			printf("No solutions.\n");	

		}

	}
	return 0;	
}

/*
 *Name: Sviatoslav Oleksiienko
 *Class: Lab section 02
 * Assignment: Part 1: multiple quadratics
 * Purpose: After user inputs the value for the coefficients a,b,c, the program otputs the real solutions for the quadratic equation ax^2+bx+c=0. The porgram continuies until the user enters 0 for the value of a
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h> // needed to create a boolen flag, which lead to better readibility

float findDiscriminant(float a, float b, float c);

int main()
{
	float a;
	float b;
	float c;
	bool exitProgram = false;

	while (!exitProgram)
	{
		printf("Please input a, b, and c: ");
		scanf("%f %f %f", &a, &b, &c);
		printf("\n");
		if (a == 0)
		{
			exitProgram = true;
		}
		else
		{
			float D = findDiscriminant(a, b, c);

			if (D > 0)
			{
				float x1 = (-b + sqrt(D)) / (2 * a);
				float x2 = (-b - sqrt(D)) / (2 * a);
				printf("x1: %f, x2: %f.\n", x1, x2);
			}
			else
			{

				if (D == 0)
				{
					float x = (-b) / (2 * a);
					printf("x: %f.\n", x);
				}
				else
				{

					printf("No solutions.\n");
				}
			}
		}
	}
	return 0;
}

float findDiscriminant(float a, float b, float c)
{

	float D = pow(b, 2) - 4 * a * c;
	return D;
}
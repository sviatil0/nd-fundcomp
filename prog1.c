 *Name: Sviatoslav Oleksiienko
 *Class: Lab section 02
 * Assignment: Part 1: Football Score Formula
 * Purpose: Considering the data of touchdowns, extra points, field goals, and of safeties, calculate and print the total number of points scored by the team./*
 *Name: Sviatoslav Oleksiienko
 *Class: Lab section 02
 * Assignment: Part 1: Footbll Score Formula
 * Purpose: Considering the data of touchdowns, extre points, field goals, and of safeties, calcutate and print the total number of points scored by the team.
 */


#include <stdio.h>

int main(){
	int touchDowns;
	int extraPoints;
        int fieldGoals;
	int ofSafeties;
	printf(	"Touch downs: ");
	scanf("%d",&touchDowns);
	printf("\n");

	printf(	"Extra Points: ");
	scanf("%d",&extraPoints);
	printf("\n");

	printf(	"Field Goals: ");
	scanf("%d",&fieldGoals);
	printf("\n");

	printf(	"Of Safeties: ");
	scanf("%d",&ofSafeties);	
	printf("\n");
	
	int totalPoints = touchDowns * 6 + extraPoints*1+fieldGoals*3+ofSafeties*2;
	printf("Total points: %d. \n",totalPoints);
	return 0;	
		

}

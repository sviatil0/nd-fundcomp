/* Name: Sviatoslav Oleksiienko
Section: lab 02
Assignment: Part 2 quadrants and polar coordinates
Purpose: This program takes the cartersian coordinates as an input
and prints which quadrant belong to, and its radius and angle in 
polar coordinates. 
*/

#include <stdio.h>
#include <math.h>
int get_quadrant(double, double);
double get_radius(double, double);
double get_angle(double, double);
void show_info(int, double, double);
int main()
{
    double x,y;
    int quadrant;
    printf("Please enter x and y: ");
    scanf("%lf %lf", &x,&y);

    quadrant = get_quadrant(x,y);
    show_info(quadrant,x,y);

    return 0;
}



double get_radius(double x, double y){
    // based on x and y in Cartesian coordinate system, returns the radius for this point in polar coordinate system 
    double radius = sqrt(pow(x,2) + pow(y,2));
    return radius;
}
double get_angle(double x, double y){
    // based on x and y input in Cartesian coordinate system returns the angle in radians for the polar coordinates for the particular points

    double angle_rad = atan2(y,x);
    double angle_deg = angle_rad / M_PI * 180;
    return angle_deg;
}
int get_quadrant(double x, double y)
{
    /*
   Based on the point in Caretesian coordinates returns the quadrant where it's located 
    */
    if ((x == 0) || (y == 0))
    {
        return -1; // means that the point does not belong to any of the quadrants (is at the origin or lie on x or y axis)
    }
    else if (x > 0)
    {
        if (y > 0)
        {
            return 1; // quadrant 1
        }
        else
        {
            return 4;
        }
    }
    else if (y > 0)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

void show_info(int quadrant, double x, double y){
    // displays the infor about the quadrant the point belongs to, and
    // its radius and angle in polar coordinates.
    double radius = get_radius(x,y);
    double angle = get_angle(x,y);
    if (quadrant == -1){
        printf("The point does not belong to any quadrant.\n");
    } else{
    printf("The point is in %d quadrant.\n",quadrant);
    } 
    printf("In polar coordinates, it has an angle of %.2lf degrees and a radius %.2lf.\n", angle,radius ); 
}
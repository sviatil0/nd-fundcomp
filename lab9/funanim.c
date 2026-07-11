#include "gfx.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define _USE_MATH_DEFINES
#define SIZE 50


int GenerageNumberInBounds(int lb, int hb);
void DrawPolygon(int numberOfSides, int xcenter, int ycenter, int r, int g, int b, double startAngleDeg, bool useCircumcircleRadius);
int main()
{
    srand(time(NULL)); //initialize randomizing with the current time
    const int xsize = 500;
    const int ysize = 500;
    gfx_open(xsize, ysize, "Part 1: Symbolic Typewriter.");

    int input;
    int sides = 3;
    bool isFinished = false;
    int number;
    int lb = 0;
    int hb = 255;
    int r,g,b;
    int xpos = 200;
    int ypos = 200;
    int angle = 0;
    while (!isFinished)
    {
        gfx_clear();
        angle++;
        if (gfx_event_waiting())
        {
            input = (int)gfx_wait();
            gfx_clear();
        r = GenerageNumberInBounds(lb,hb);
        g = GenerageNumberInBounds(lb,hb);
        b = GenerageNumberInBounds(lb,hb);
        }
        number = input - '0';
        if (input == 'q')
            isFinished = true;
        else if (number >= 1 && number <= 9){
            sides = number;
        }
        DrawPolygon(sides, xpos,ypos, r,g,b, angle, true);
        gfx_flush();
        usleep(10000);

    }

    return 0;
}

void DrawPolygon(int numberOfSides, int xcenter, int ycenter, int r, int g, int b, double startAngleDeg, bool useCircumcircleRadius)
{
    gfx_color(r, g, b);
    double angle = (2 * M_PI) / numberOfSides;
    double startAngleRad = startAngleDeg * M_PI / 180;
    double totalAngle = startAngleRad;
    double R;
    if (useCircumcircleRadius)
        R = SIZE / 2; // when SIZE means the size of the diameter of the circumcircle
    else
        R = SIZE / (2 * sin(M_PI / numberOfSides)); // when SIZE means the size of the side
    int x1;
    int x2;
    int y1, y2;
    for (int i = 1; i <= numberOfSides; ++i)
    {
        x1 = (int)(R * cos(totalAngle) + xcenter);
        y1 = (int)(R * sin(totalAngle) + ycenter);

        totalAngle += angle;
        x2 = (int)(R * cos(totalAngle) + xcenter);
        y2 = (int)(R * sin(totalAngle) + ycenter);
        gfx_line(x1, y1, x2, y2);
    }
}
int GenerageNumberInBounds(int lb, int hb)
{
    return rand() % (hb + 1 - lb) + lb;
}
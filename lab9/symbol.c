#include "gfx.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES
#define SIZE 50

void DrawSquare(int xcenter, int ycenter, int r, int g, int b);
void DrawIsoscelesTriangle(int xcenter, int ycenter, int r, int g, int b);
void DrawPolygon(int numberOfSides, int xcenter, int ycenter, int r, int g, int b, double startAngleDeg, bool useCircumcircleRadius);
int main()
{
    const int xsize = 500;
    const int ysize = 500;
    gfx_open(xsize, ysize, "Part 1: Symbolic Typewriter.");

    int input;
    bool isFinished = false;
    int number;
    int purple_r = 128;
    int purple_g = 0;
    int purple_b = 128;
    int white_r = 255;
    int white_g = 255;
    int white_b = 255;

    int blue_r = 0;
    int blue_g = 0;
    int blue_b = 255;

    int green_r = 0;
    int green_g = 255;
    int green_b = 0;
    while (!isFinished)
    {
        input = (int)gfx_wait();

        switch (input)
        {
        case 1:
            DrawSquare(gfx_xpos(), gfx_ypos(), blue_r, blue_g, blue_b);
            break;
        case 'c':
            gfx_color(white_r, white_g, white_b); // white color
            gfx_circle(gfx_xpos(), gfx_ypos(), SIZE / 2);
            break;
        case 't':
            DrawIsoscelesTriangle(gfx_xpos(), gfx_ypos(), green_r, green_g, green_b);
            break;
        case 'q':
            isFinished = true;
            break;
        case 27: // its ESC symbol
            gfx_clear();
            break;
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            number = input - '0';
            DrawPolygon(number, gfx_xpos(), gfx_ypos(), purple_r, purple_g, purple_b, 0, true);
            break;
        }
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
void DrawIsoscelesTriangle(int xcenter, int ycenter, int r, int g, int b)
{
    gfx_color(r, g, b);
    int x1, x2, x3, y1, y2, y3;
    int h = SIZE;
    x1 = xcenter;
    y1 = ycenter - h / 2;
    x2 = xcenter - h / 2;
    y2 = ycenter + h / 2;
    x3 = xcenter + h / 2;
    y3 = ycenter + h / 2;
    gfx_line(x1, y1, x2, y2);
    gfx_line(x2, y2, x3, y3);
    gfx_line(x3, y3, x1, y1);
}
void DrawSquare(int xcenter, int ycenter, int r, int g, int b)
{
    DrawPolygon(4, xcenter, ycenter, r, g, b, 45, false);
}
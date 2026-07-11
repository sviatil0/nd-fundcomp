/*
Author: Sviatoslav Oleksiienko
Section: lab 02
Problems: 1-10 Lab 10
Description:
The program will first open a large blank window and wait for user input. When the user presses any of the keys 1 through 8, the program will clear the screen, and then draw the corresponding fractal shape. Then, for each new number key (1-8) pressed, that fractal will be displayed. The program exits when the user presses the 'q' key. For any other key pressed, nothing is displayed (blank screen).
Fractals that will be drawn (https://prnt.sc/YRviTz1R-evb)
*/
#include "gfx.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3);
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);

void ShrinkingSquares(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void DrawSqare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void SpiralSquares(int radius, int x_in, int y_in, double angle,int);
void CircularLace(int radius, int x, int y);
void DrawSnowflake(int xCenter, int yCenter, int radius);
void DrawBranches(int xTail, int yTail, int radius, double inAngle);
void DrawFern(int xTail, int yTail, int radius, double inAngle);
// void DrawSpiralOfSpirals(int maxRadius, int xCenter, int yCenter, double radiusDecrement, double angleIncrement);
void DrawSpiralOfSpirals(double xCenter, double yCenter, double angle);
// void DrawSpiral(double x, double y, double length, double direction) ;
int main()
{
  bool isFinished = false;
  int width = 700, height = 700, mrgn = 20, mrgn2 = 500;
  char input;
  int in_radius3 = 5;
  int in_radius4 = 200;
  gfx_open(width, height, "Lab 10");

  while (!isFinished)
  {
    if (gfx_event_waiting())
    {
      input = gfx_wait();
      gfx_clear();
      switch (input)
      {
      case '1':
        sierpinski(mrgn, mrgn, width - mrgn, mrgn, width / 2, height - mrgn);
        break;
      case '2':
        ShrinkingSquares(mrgn2, mrgn2, mrgn2, height - mrgn2, width - mrgn2, height - mrgn2, width - mrgn2, mrgn2);
        break;
      case '3':
        SpiralSquares(in_radius3,width/2,height/2,M_PI/4, 1);
        break;
      case '4':
        CircularLace(in_radius4,width/2,height/2);
        break; 
      case '5':
        DrawSnowflake(width/2,height/2,height/4); //has to be 180
        break;
      case '6':
        DrawBranches(width/2,height-mrgn, height/3,3*M_PI/2); //has to be 225 break;
        break;
      case '7':
        DrawFern(width/2,height-mrgn, height/7,3*M_PI/2); //has to be 225 break;
        break;
      case '8':
      //  DrawSpiralOfSpirals(1000,width/2,height/2,10,0.5);
      DrawSpiralOfSpirals(width/2,height/2,3000);
        break;
      case 'q':
        isFinished = true;
      }
      gfx_flush();
    }
  }
}

void DrawSpiralOfSpirals(double xCenter, double yCenter, double angle){
  gfx_point(xCenter,yCenter);
  double radius, newX,newY,newAngle;
  if((exp(angle*(M_PI/180))/(2*M_PI))/1.6<1) return;

  for(double i = 0; i < angle; i+=40){
      radius = (exp(i*(M_PI/180)/(2*M_PI))) /1.6;
      newX = xCenter+radius*(cos(i*(M_PI/180)));
      newY = yCenter - radius*(sin(i*(M_PI/180)));
      newAngle = i-360;
      DrawSpiralOfSpirals(newX,newY ,newAngle);
  }

}
// void DrawSpiralOfSpirals(int maxRadius, int xCenter, int yCenter, double radiusDecrement, double angleIncrement){
//   if (maxRadius < 1) return;
//   // double angleIncrement = 0.5;
//   // double angleIncrement =  0.1;
//   double angle = angleIncrement;
//   int radius = maxRadius;
//   int xOuter, yOuter, xOuter2,yOuter2;
//   while (radius>1){
//   xOuter = xCenter + radius* cos(angle);
//   yOuter = yCenter + radius* sin(angle);
//   angle += angleIncrement;
//   // xOuter2 = xCenter + radius* cos(angle);
//   // yOuter2 = yCenter + radius* sin(angle);
//   gfx_point(xOuter,yOuter);
//   DrawSpiralOfSpirals(radius/5, xOuter,yOuter, radiusDecrement/8,angleIncrement/2);
//   radius /= 1.1;
//   // radius -=radiusDecrement; 
//   }
// }
void DrawFern(int xTail, int yTail, int radius, double inAngle){

  if(radius <2) return;
  double angle1 = inAngle; //to have the same starting point like in the example 

  double thirtyFiveDegToRad = 35* M_PI / 180;
  double angle2 = angle1 -thirtyFiveDegToRad;
  double angle3 = angle1 +  thirtyFiveDegToRad;
  double divisor = 2.5; 

  int xCenter,yCenter;
  for(int i = 0; i<4; ++i){

  xCenter = (int)(xTail + radius*cos(angle1));
  yCenter = (int)(yTail + radius*sin(angle1)); 
  gfx_line(xTail,yTail,xCenter,yCenter);

  DrawFern(xCenter,yCenter,radius/(divisor),angle3);

  DrawFern(xCenter,yCenter,radius/(divisor),angle2);
  xTail = xCenter;
  yTail = yCenter;
  }
}
void DrawBranches(int xTail, int yTail, int radius, double inAngle){
  if(radius < 3) return;
  double angle1 = inAngle; //to have the same starting point like in the example 

  double fourtyFiveDegToRad = 45* M_PI / 180;
  double angle2 = angle1 -fourtyFiveDegToRad;
  double angle3 = angle1 +  fourtyFiveDegToRad;
  double divisor = 1.9;

  int xCenter = (int)(xTail + radius*cos(angle1));
  int yCenter = (int)(yTail + radius*sin(angle1)); 
  
  gfx_line(xTail,yTail,xCenter,yCenter);

  int x2 = (int)(xCenter + (radius/divisor)*cos(angle2));
  int y2 = (int)(yCenter + (radius/divisor)*sin(angle2)); 


  int x3 = (int)(xCenter + (radius/divisor)*cos(angle3));
  int y3 = (int)(yCenter + (radius/divisor)*sin(angle3)); 

  gfx_line(xCenter,yCenter,x2,y2);
  gfx_line(xCenter,yCenter,x3,y3);

  DrawBranches(x3,y3,radius/(divisor),angle3+fourtyFiveDegToRad/2);
  DrawBranches(x3,y3,radius/(divisor),angle3-fourtyFiveDegToRad/2);

  DrawBranches(x2,y2,radius/(divisor),angle2+fourtyFiveDegToRad/2);
  DrawBranches(x2,y2,radius/(divisor),angle2-fourtyFiveDegToRad/2);
}

void DrawSnowflake(int xCenter, int yCenter, int radius){
  if(radius < 1) return;
  double angle = M_PI/ 2; //to have the same starting point like in the example 
  double angleIncrement = (M_PI*2)/5;
  int x_new,y_new; 
  for(int i = 1;i<=6; ++i){
    x_new = (int)(xCenter + radius*cos(angle));
    y_new = (int)(yCenter + radius*sin(angle)); 
    gfx_line(xCenter,yCenter,x_new,y_new);
    DrawSnowflake(x_new,y_new,radius/2.7);
    angle += angleIncrement;
  }
}
void DrawSqare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  gfx_line(x1, y1, x2, y2);
  gfx_line(x2, y2, x3, y3);
  gfx_line(x3, y3, x4, y4);
  gfx_line(x4, y4, x1, y1);
}
void CircularLace(int radius, int x, int y){
  if (radius<1) return;
  gfx_circle(x,y,radius);

  double angle = 0; 
  int newRadius = (int)(radius/2.95);
  int x_new;
  int y_new;
  for(int i = 1; i<=6; ++i){

  x_new = (int)(x + radius*cos(angle));
  y_new = (int)(y + radius*sin(angle)); 
  CircularLace(newRadius, x_new,y_new);
  angle += M_PI/ 3;
  }
}
void SpiralSquares(int radius, int x_in, int y_in, double angle, int halfSideLength){
  if (radius > 400) return;

  int x =(int)( x_in + radius * sin(angle));
  int y = (int)(y_in + radius* cos(angle));

  int x1 = x - halfSideLength;
  int y1 = y - halfSideLength;
  int x2 = x-halfSideLength; 
  int y2 = y + halfSideLength;
  int x3 = x + halfSideLength;
  int y3 = y + halfSideLength;
  int x4 = x +halfSideLength;
  int y4 = y-halfSideLength;

  DrawSqare(x1,y1,x2,y2,x3,y3,x4,y4);
  SpiralSquares(radius+10, x_in,y_in,angle+0.5, halfSideLength+1);
}
void ShrinkingSquares(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  // Base case
  if (abs(x4 - x1) < 1)
    return;
  DrawSqare(x1, y1, x2, y2, x3, y3, x4, y4);

  int halfNewSideLength = (int)(((double)(x4 - x1) / 2.3) / 2);

  ShrinkingSquares(x1 - halfNewSideLength, y1 - halfNewSideLength, x1 - halfNewSideLength, y1 + halfNewSideLength, x1 + halfNewSideLength, y1 + halfNewSideLength, x1 + halfNewSideLength, y1 - halfNewSideLength);
  ShrinkingSquares(x2 - halfNewSideLength, y2 - halfNewSideLength, x2 - halfNewSideLength, y2 + halfNewSideLength, x2 + halfNewSideLength, y2 + halfNewSideLength, x2 + halfNewSideLength, y2 - halfNewSideLength);

  ShrinkingSquares(x3 - halfNewSideLength, y3 - halfNewSideLength, x3 - halfNewSideLength, y3 + halfNewSideLength, x3 + halfNewSideLength, y3 + halfNewSideLength, x3 + halfNewSideLength, y3 - halfNewSideLength);
  ShrinkingSquares(x4 - halfNewSideLength, y4 - halfNewSideLength, x4 - halfNewSideLength, y4 + halfNewSideLength, x4 + halfNewSideLength, y4 + halfNewSideLength, x4 + halfNewSideLength, y4 - halfNewSideLength);
}
void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
  // Base case. 
  if( abs(x2-x1) < 5 ) return;

  // Draw a triangle
  drawTriangle( x1, y1, x2, y2, x3, y3 );

  // Recursive calls
  sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
  sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
  sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}

void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 )
{
  gfx_line(x1,y1,x2,y2);
  gfx_line(x2,y2,x3,y3);
  gfx_line(x3,y3,x1,y1);
}

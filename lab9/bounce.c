#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#define HORIZONTAL_SIZE 1000
#define VERTICAL_SIZE 500

typedef struct
{
    int horizontal;
    int vertical;
} velocity;

typedef struct
{
    int x;
    int y;
} location;

velocity NewVelocity(location lc, int radius, velocity vc);

location GenerateRandomLocation(int radius);
int GenerageNumberInBounds(int lb, int hb);
velocity GenerateRandomVelocity(int lb, int hb);

int main()
{
    srand(time(NULL)); //initialize randomizing with the current time

    gfx_open(HORIZONTAL_SIZE, VERTICAL_SIZE, "Part2: Bouncing Ball");
    gfx_color(255, 255, 255);
    // creating bounds for rand
    int lb_v = 1; // lower bound velocity inclusive
    int hb_v = 4; // higher bound velocity inclusive
    int radius = 30;
    location currentLocation = GenerateRandomLocation(radius);
    velocity currentVelocity = GenerateRandomVelocity(lb_v, hb_v);

    // when placed out of the box, you should check which value is out of bound and make it 0 so it doesn't get stuck
    while (true)
    {
        gfx_circle(currentLocation.x, currentLocation.y, radius);
        currentLocation.x += currentVelocity.horizontal;
        currentLocation.y += currentVelocity.vertical;
        currentVelocity = NewVelocity(currentLocation, radius, currentVelocity);
        gfx_flush();
        usleep(10000);
        gfx_clear();
        if (gfx_event_waiting())
        {

            if (gfx_wait() == 1)
            {
                currentLocation.x = gfx_xpos();
                currentLocation.y = gfx_ypos();
                currentVelocity = GenerateRandomVelocity(lb_v, hb_v);
            }
        }
    }
    return 0;
}
velocity NewVelocity(location lc, int radius, velocity vc)
{
    bool yOutOfRangeNegative = lc.y - radius <= 0;
    bool yOutOfRangePositive = lc.y + radius >= VERTICAL_SIZE;

    bool xOutOfRangeNegative = lc.x - radius <= 0;
    bool xOutOfRangePositive = lc.x + radius >= HORIZONTAL_SIZE;

    if (yOutOfRangeNegative)
        vc.vertical = abs(vc.vertical);
    else if (yOutOfRangePositive)
        vc.vertical = -abs(vc.vertical);

    if (xOutOfRangeNegative)
        vc.horizontal = abs(vc.horizontal);
    else if (xOutOfRangePositive)
        vc.horizontal = -abs(vc.horizontal);

    return vc;
}
location GenerateRandomLocation(int radius)
{
    location lc = {GenerageNumberInBounds(radius, HORIZONTAL_SIZE - radius), GenerageNumberInBounds(radius, VERTICAL_SIZE - radius)};
    return lc;
}

int GenerageNumberInBounds(int lb, int hb)
{
    return rand() % (hb + 1 - lb) + lb;
}
velocity GenerateRandomVelocity(int lb, int hb)
{

    int random_x = GenerageNumberInBounds(lb, hb);
    int random_y = GenerageNumberInBounds(lb, hb);

    // Randomly giving a sign for the velocities
    if (rand() % 2 == 0)
        random_x *= -1;
    if (rand() % 2 == 1)
        random_y *= -1;
    velocity vl = {random_x, random_y};
    return vl;
}
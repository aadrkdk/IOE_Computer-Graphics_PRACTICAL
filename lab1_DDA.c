/*
    Description: DDA(Digital Differential Analyzer) Algoritm to draw a line.
*/
#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, x2, y2, x, y, dx, dy, steps;
    printf(" Enter End points:\n");
    printf(" x1: ");
    scanf("%f", &x1);
    printf(" y1: ");
    scanf("%f", &y1);
    printf(" x2: ");
    scanf("%f", &x2);
    printf(" y2: ");
    scanf("%f", &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    dx = dx / steps;
    dy = dy / steps;

    x = x1;
    y = y1;

    // initializes the graphics system by opening a graphics window of the specified size.
    initwindow(950, 950);
    setbkcolor(COLOR(255, 255, 255)); // window color
    setcolor(BLACK);                  // font color

    int k = 0;
    while (k <= steps)
    {
        putpixel(x, y, BLACK);
        x = x + dx;
        y = y + dy;
        k++;
    }
    bgi_getch();
    return 0;
}

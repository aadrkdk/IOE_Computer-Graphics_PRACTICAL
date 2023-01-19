/*
    Description: Mid-point Circle Drawing Algorithm is implemented to draw circle.
*/
#include <stdio.h>
#include <math.h>
#include <graphics.h>

void drawcircle(int x0, int y0, int r);

int main()
{
    int h, k, r;
    printf(" Enter Center:\n");
    scanf("%d%d", &h, &k);
    printf(" Enter Radius: ");
    scanf("%d", &r);

    // initializes the graphics system by opening a graphics window of the specified size.
    initwindow(950, 950);
    setbkcolor(COLOR(255, 255, 255)); // window color
    drawcircle(h, k, r);

    bgi_getch();
    return 0;
}

void drawcircle(int x0, int y0, int r)
{
    int x = 0;
    int y = r;
    int p = 0;
    while (x >= y)
    {
        putpixel(x0 + x, y0 + y, BLACK);
        putpixel(x0 + x, y0 - y, BLACK);

        putpixel(x0 - x, y0 + y, BLACK);
        putpixel(x0 - x, y0 - y, BLACK);

        putpixel(x0 + y, y0 + x, BLACK);
        putpixel(x0 + y, y0 - x, BLACK);

        putpixel(x0 - y, y0 + x, BLACK);
        putpixel(x0 - y, y0 - x, BLACK);

        if (p <= 0)
        {
            y = y + 1;
            p = p + 2 * y + 1;
        }
        else
        {
            x = x - 1;
            p = p - 2 * x + 1;
        }
    }
}
#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawline(int, int, int, int);

int main()
{
    int x1, y1, x2, y2;
    printf(" Enter the coordinates:\n");
    printf(" x1: ");
    scanf("%d", &x1);
    printf(" y1: ");
    scanf("%d", &y1);
    printf(" x2: ");
    scanf("%d", &x2);
    printf(" y2: ");
    scanf("%d", &y2);

    // initializes the graphics system by opening a graphics window of the specified size.
    initwindow(950, 950);
    setbkcolor(COLOR(255, 255, 255)); // window color

    drawline(x1, y1, x2, y2);

    bgi_getch();
    return 0;
}

void drawline(int x1, int y1, int x2, int y2)
{
    int dx = fabs(x2 - x1);
    int dy = fabs(y2 - y1);

    int x = x1;
    int y = y1;

    int xinc = (x2 > x1) ? 1 : -1;
    int yinc = (y2 > y1) ? 1 : -1;

    int p = 2 * dy - dx;

    while (x < x2)
    {
        if (p >= 0)
        {
            putpixel(x, y, BLACK);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            putpixel(x, y, BLACK);
            p = p + 2 * dy;
        }
        x = x + 1;
    }
}
/*
     Description: Mid-point Algorithm is implemented to draw ellipse.
 */
#include <stdio.h>
#include <graphics.h>

void midPointEllipse(int xc, int yc, int rx, int ry);
void ellipsePlotPoints(int, int, int, int);

int main()
{

    float xc, yc, rx, ry;

    printf("Enter the center of ellipse:\n");
    printf("x-coordinate = ");
    scanf("%f", &xc);
    printf("y-coordinate = ");
    scanf("%f", &yc);
    printf("Enter radius of ellipse:\n");
    printf("Rx = ");
    scanf("%f", &rx);
    printf("Ry = ");
    scanf("%f", &ry);

    /* initializes the graphics system by opening a graphics window of the specified size. */
    initwindow(950, 950);
    setbkcolor(COLOR(255, 255, 255)); // window color

    /* draw the ellipse */
    midPointEllipse(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}

void midPointEllipse(int xc, int yc, int rx, int ry)
{
    int x = 0, y = ry;
    double p = ry * ry - rx * rx * ry + rx * rx / 4.0;

    /* Plot the initial point in each quadrant. */
    ellipsePlotPoints(xc, yc, x, y);

    /* Region 1 */
    while (2.0 * ry * ry * x <= 2.0 * rx * rx * y)
    {
        x++;
        if (p < 0)
            p += 2 * ry * ry * x + ry * ry;
        else
        {
            y--;
            p += 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
        }
        ellipsePlotPoints(xc, yc, x, y);
    }

    /* Region 2 */
    p = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;
    while (y > 0)
    {
        y--;
        if (p > 0)
            p += rx * rx - 2 * rx * rx * y;
        else
        {
            x++;
            p += 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
        }
        ellipsePlotPoints(xc, yc, x, y);
    }
}

/* Plot the ellipse at (xc, yc) */
void ellipsePlotPoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, BLACK);
    putpixel(xc - x, yc + y, BLACK);
    putpixel(xc + x, yc - y, BLACK);
    putpixel(xc - x, yc - y, BLACK);
}

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

int round_float(float a);

int main()
{
    // To Draw a Line Using DDA
    int gd = DETECT, gm;
    int x1, y1, x2, y2, steps, k;
    float xincr, yincr, x, y, dx, dy;

    printf("Enter x1, y1: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter x2, y2: ");
    scanf("%d%d", &x2, &y2);

    initgraph(&gd, &gm, "");

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    xincr = dx / (float)steps;
    yincr = dy / (float)steps;
    x = x1;
    y = y1;

    putpixel(round_float(x), round_float(y), WHITE);
    for (k = 1; k <= steps; k++)
    {
        x += xincr;
        y += yincr;
        putpixel(round_float(x), round_float(y), WHITE);
    }

    outtextxy(200, 20, "Sandesh Prasai");
    outtextxy(x1 + 15, y1 - 5, "(x1, y1)");
    outtextxy(x2 + 5, y2 + 5, "(x2, y2)");

    getch();
    closegraph();

    return 0;
}

int round_float(float a)
{
    return (int)(a + 0.5);
}


#include "Circle.h"
#include<Line.h>

Circle::Circle()
{
    //ctor
}

Circle::~Circle()
{
    //dtor
}

void Circle::displayBresenhamCircle(int xc, int yc, int x, int y)
{
    Line line1 = Line();
    Line line2;
    Line line3;
    Line line4;
    Line line5;
    Line line6;
    Line line7;
    Line line8;

    line1.setPixel(xc+x, yc+y, 0, 0, 0);
    line2.setPixel(xc-x, yc+y, 0, 0, 0);
    line3.setPixel(xc+x, yc-y, 0, 0, 0);
    line4.setPixel(xc-x, yc-y, 0, 0, 0);
    line5.setPixel(xc+y, yc+x, 0, 0, 0);
    line6.setPixel(xc-y, yc+x, 0, 0, 0);
    line7.setPixel(xc+y, yc-x, 0, 0, 0);
    line8.setPixel(xc-y, yc-x, 0, 0, 0);
}

void Circle::drawBresenhamCircle(int xc, int yc, int radius)
{
    int x = 0, y = radius;
    int decesionParameter = 3 - 2 * radius;
    displayBresenhamCircle(xc, yc, x, y);

    while(y >= x)
    {
        x++;
        if(decesionParameter > 0)
        {
            y--;
            decesionParameter = decesionParameter + 4 * (x-y) + 10;
        }
        else
        {
            decesionParameter = decesionParameter + 4 * x + 6;
        }
        displayBresenhamCircle(xc, yc, x, y);
    }
}

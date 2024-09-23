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

void Circle::drawdetailsWheel(int posX, int posY) {
    Line line;
    Color color;

    int xs[4];
    int ys[4];

    //The first wheel
    xs[0] = posX + 90; xs[1] = posX + 70; xs[2] = posX + 110; xs[3] = posX + 90;
    ys[0] = posY + 70; ys[1] = posY + 90; ys[2] = posY + 90; ys[3] = posY + 70;
    line.bezierCurve(xs, ys, false, color.RGB(0, 0, 0));

    xs[0] = posX + 90; xs[1] = posX + 115; xs[2] = posX + 110; xs[3] = posX + 90;
    ys[0] = posY + 70; ys[1] = posY + 55; ys[2] = posY + 90; ys[3] = posY + 70;
    line.bezierCurve(xs, ys, false, color.RGB(0, 0, 0));

    xs[0] = posX + 90; xs[1] = posX + 80; xs[2] = posX + 115; xs[3] = posX + 90;
    ys[0] = posY + 70; ys[1] = posY + 40; ys[2] = posY + 60; ys[3] = posY + 70;
    line.bezierCurve(xs, ys, false, color.RGB(0, 0, 0));

    xs[0] = posX + 90; xs[1] = posX + 60; xs[2] = posX + 90; xs[3] = posX + 90;
    ys[0] = posY + 70; ys[1] = posY + 70; ys[2] = posY + 40; ys[3] = posY + 70;
    line.bezierCurve(xs, ys, false, color.RGB(0, 0, 0));

    xs[0] = posX + 90; xs[1] = posX + 60; xs[2] = posX + 80; xs[3] = posX + 90;
    ys[0] = posY + 70; ys[1] = posY + 60; ys[2] = posY + 90; ys[3] = posY + 70;
    line.bezierCurve(xs, ys, false, color.RGB(0, 0, 0));


    //The second wheel
    xs[0] = posX + 200; xs[1] = posX + 180; xs[2] = posX + 220; xs[3] = posX + 200;
    ys[0] = posY + 10; ys[1] = posY + 30; ys[2] = posY + 30; ys[3] = posY + 10;
    line.bezierCurve(xs, ys, false, color.RGB(0, 0, 0));

    xs[0] = posX + 200; xs[1] = posX + 225; xs[2] = posX + 220; xs[3] = posX + 200;
    ys[0] = posY + 10; ys[1] = posY - 5; ys[2] = posY + 30; ys[3] = posY + 10;
    line.bezierCurve(xs, ys, false, color.RGB(0, 0, 0));

    xs[0] = posX + 200; xs[1] = posX + 190; xs[2] = posX + 225; xs[3] = posX + 200;
    ys[0] = posY + 10; ys[1] = posY - 20; ys[2] = posY + 0; ys[3] = posY + 10;
    line.bezierCurve(xs, ys, false, color.RGB(0, 0, 0));

    xs[0] = posX + 200; xs[1] = posX + 170; xs[2] = posX + 200; xs[3] = posX + 200;
    ys[0] = posY + 10; ys[1] = posY + 10; ys[2] = posY - 20; ys[3] = posY + 10;
    line.bezierCurve(xs, ys, false, color.RGB(0, 0, 0));

    xs[0] = posX + 200; xs[1] = posX + 170; xs[2] = posX + 190; xs[3] = posX + 200;
    ys[0] = posY + 10; ys[1] = posY + 0; ys[2] = posY + 30; ys[3] = posY + 10;
    line.bezierCurve(xs, ys, false, color.RGB(0, 0, 0));
}

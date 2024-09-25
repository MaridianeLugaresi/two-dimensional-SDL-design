#include "Circle.h"
#include<Line.h>

Circle::Circle()
{

}

Circle::Circle(int x, int y, int radius)
{
    this->posX = x;
    this->posY = y;
    this->radius = radius;
}

Circle::~Circle()
{
    //dtor
}

void Circle::displayBresenhamCircle(int x, int y)
{
    Line line1;
    Line line2;
    Line line3;
    Line line4;
    Line line5;
    Line line6;
    Line line7;
    Line line8;

    line1.setPixel(this->posX+x, this->posY+y, 0, 0, 0);
    line2.setPixel(this->posX-x, this->posY+y, 0, 0, 0);
    line3.setPixel(this->posX+x, this->posY-y, 0, 0, 0);
    line4.setPixel(this->posX-x, this->posY-y, 0, 0, 0);
    line5.setPixel(this->posX+y, this->posY+x, 0, 0, 0);
    line6.setPixel(this->posX-y, this->posY+x, 0, 0, 0);
    line7.setPixel(this->posX+y, this->posY-x, 0, 0, 0);
    line8.setPixel(this->posX-y, this->posY-x, 0, 0, 0);
}

void Circle::drawBresenhamCircle()
{
    int x = 0, y = this->radius;
    int decesionParameter = 3 - 2 * this->radius;
    displayBresenhamCircle(x, y);

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
        displayBresenhamCircle(x, y);
    }
}

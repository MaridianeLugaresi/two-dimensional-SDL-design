#include "Wheel.h"
#include<Circle.h>
#include<Point.h>
#include<Line.h>

Wheel::Wheel(Point anchor, int radius)
{
    this->anchor = anchor;
    this->offset = 10;
    this->posX = anchor.getX();
    this->posY = anchor.getY();
    this->circle = Circle(anchor.getX(), anchor.getY(), radius);
    this->firstRadius = Line(Point(this->posX, this->posY - 30), Point(this->posX, this->posY + 30),Color(0,0,0));
    this->secondRadius = Line(Point(this->posX - 30, this->posY), Point(this->posX + 30, this->posY),Color(0,0,0));
}

Wheel::~Wheel()
{
    //dtor
}

void Wheel::draw()
{
    this->firstRadius.draw();
    this->secondRadius.draw();
    this->circle.drawBresenhamCircle();
}

void Wheel::rotate()
{

}

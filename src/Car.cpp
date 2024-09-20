#include "Car.h"
#include<Line.h>
#include<Point.h>
#include<Polygon.h>
#include<stdio.h>
#include<Rectangle.h>

Car::Car()
{
    this->posX = 50;
    this->posY = 350;
    this->anchor = Point(this->posX,this->posY);
    this->angleRotation = -30;
}

Car::~Car()
{
    //dtor
}

void Car::draw() {

    printf("DRAW: %d-%d\n", this->posX, this->posY);

    Rectangle body = Rectangle(Line(Point(this->posX, this->posY), Point(this->posX + 200, this->posY), Color(65,105,225), true),
                               Line(Point(this->posX, this->posY - 100), Point(this->posX + 200, this->posY - 100), Color(50,205,50), true),
                               Line(Point(this->posX, this->posY), Point(this->posX, this->posY - 100), Color(244,164,96), true),
                               Line(Point(this->posX + 200, this->posY), Point(this->posX + 200, this->posY - 100), Color(255,0,255), true));

    body.rotate(this->angleRotation, Point(this->posX, this->posY));

    body.draw();

}

void Car::updatePosition()
{
    int x = this->posX;
    int y = this->posY;

    this->posX = x +2;
    this->posY = y -1;
}

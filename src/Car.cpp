#include "Car.h"
#include<Line.h>
#include<Point.h>
#include<Polygon.h>
#include<stdio.h>
#include<Rectangle.h>
#include<Circle.h>
#include <Color.h>
#include <unistd.h>

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

    Rectangle body = Rectangle(Line(Point(this->posX, this->posY), Point(this->posX + 200, this->posY), Color(0,0,0), true),
                               Line(Point(this->posX, this->posY - 100), Point(this->posX + 200, this->posY - 100), Color(0,0,0), true),
                               Line(Point(this->posX, this->posY), Point(this->posX, this->posY - 100), Color(0,0,0), true),
                               Line(Point(this->posX + 200, this->posY), Point(this->posX + 200, this->posY - 100), Color(0,0,0), true));

    body.rotate(this->angleRotation, Point(this->posX, this->posY));

    body.draw();

    Circle circle;
    circle.drawBresenhamCircle(this->posX + 90,this->posY + 70, 25);
    circle.drawBresenhamCircle(this->posX + 200,this->posY + 10, 25);
    circle.drawdetailsWheel(this->posX, this->posY);

}

void Car::updatePosition()
{
    int x = this->posX;
    int y = this->posY;

    this->posX = x +2;
    this->posY = y -1;
}

#include "Car.h"
#include<Line.h>
#include<Point.h>
#include<Polygon.h>
#include<stdio.h>
#include<Rectangle.h>

Car::Car()
{
    this->anchor = Point(50,350);
    this->angleRotation = -30;
}

Car::~Car()
{
    //dtor
}

void Car::draw() {

    Rectangle body = Rectangle(Line(Point(anchor.getX(), anchor.getY()), Point(anchor.getX() + 200, anchor.getY()), Color(65,105,225), true),
                               Line(Point(anchor.getX(), anchor.getY() - 100), Point(anchor.getX() + 200, anchor.getY() - 100), Color(50,205,50), true),
                               Line(Point(anchor.getX(), anchor.getY()), Point(anchor.getX(), anchor.getY() - 100), Color(244,164,96), true),
                               Line(Point(anchor.getX() + 200, anchor.getY()), Point(anchor.getX() + 200, anchor.getY() - 100), Color(255,0,255), true));

    body.rotate(this->angleRotation, this->anchor);

    body.draw();

}

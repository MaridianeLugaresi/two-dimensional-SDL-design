#include "Car.h"
#include<Line.h>
#include<Point.h>
#include<Polygon.h>
#include<stdio.h>
#include<Rectangle.h>

Car::Car()
{
    this->anchor = Point(50,450);
    this->angleRotation = 30;
}

Car::~Car()
{
    //dtor
}

void Car::draw() {

    Rectangle body = Rectangle(Line(Point(anchor.getX(), anchor.getY()), Point(anchor.getX() + 200, anchor.getY()), Color(0,0,0), true),
                               Line(Point(anchor.getX(), anchor.getY() - 100), Point(anchor.getX() + 200, anchor.getY() - 100), Color(0,0,0), true),
                               Line(Point(anchor.getX(), anchor.getY()), Point(anchor.getX(), anchor.getY() - 100), Color(0,0,0), true),
                               Line(Point(anchor.getX() + 200, anchor.getY()), Point(anchor.getX() + 200, anchor.getY() - 100), Color(0,0,0), true));

    body.rotate(this->angleRotation, this->anchor);

    //inferiorLine.rotateLine(this->angleRotation, this->anchor.getX(), this->anchor.getY());
    //line4.rotateLine(this->angleRotation, this->anchor.getX(), this->anchor.getY());

    body.draw();

}

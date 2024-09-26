#include "Car.h"
#include<Line.h>
#include<Point.h>
#include<Polygon.h>
#include<stdio.h>
#include<Rectangle.h>
#include<Circle.h>
#include <Color.h>
#include <unistd.h>
#include <Wheel.h>
#include<Polygon.h>

Car::Car()
{
    this->posX = 50;
    this->posY = 350;
    this->anchor = Point(this->posX,this->posY);
    this->angleRotation = -30;
    this->offsetWheel = 10;
}

Car::~Car()
{
    //dtor
}

void Car::draw() {

    list<Point> points;

    //SUPERIOR
    points.push_back(Point(this->posX,this->posY - 50));
    points.push_back(Point(this->posX + 50,this->posY - 50));

    //INFERIOR
    points.push_back(Point(this->posX + 50,this->posY));
    points.push_back(Point(this->posX,this->posY));

    Polygon polygon = Polygon(points, 330);

    polygon.rotate();

    polygon.draw();
/*
    Rectangle backBody = Rectangle(Line(Point(this->posX, this->posY), Point(this->posX + 150, this->posY), Color(0,0,0), true),
                                   Line(Point(this->posX, this->posY - 80), Point(this->posX + 150, this->posY - 80), Color(0,0,0), true),
                                   Line(Point(this->posX, this->posY), Point(this->posX, this->posY - 80), Color(0,0,0), true),
                                   Line(Point(this->posX + 150, this->posY), Point(this->posX + 150, this->posY - 80), Color(0,0,0), true));

    Rectangle frontBody = Rectangle(Line(Point(backBody.inferior.end.getX(), backBody.inferior.end.getY() + 20), Point(backBody.inferior.end.getX() + 125, backBody.inferior.end.getY() + 20), Color(0,0,0), true),
                                    Line(Point(backBody.superior.end.getX(), backBody.superior.end.getY()), Point(backBody.superior.end.getX() + 125, backBody.superior.end.getY()), Color(0,0,0), true),
                                    Line(Point(backBody.superior.end.getX(), backBody.superior.end.getY()), Point(backBody.inferior.end.getX(), backBody.inferior.end.getY() + 20), Color(0,0,0), true),
                                    Line(Point(backBody.inferior.end.getX() + 125, backBody.superior.end.getY()), Point(backBody.inferior.end.getX() + 125, backBody.inferior.end.getY() + 20), Color(0,0,0), true));

    backBody.rotate(this->angleRotation, Point(this->posX, this->posY));
    //frontBody.rotate(this->angleRotation, Point(this->posX, this->posY));

    Wheel backWheel = Wheel(Point(this->posX + 80, this->posY + 60), 30, this->offsetWheel);
    Wheel frontWheel = Wheel(Point(this->posX + 160, this->posY + 20), 30, this->offsetWheel);

    backBody.draw();
    //frontBody.draw();

    //frontWheel.rotate();
    //backWheel.rotate();

    frontWheel.draw();
    backWheel.draw();
*/
}

void Car::updatePosition()
{
    /*
    int x = this->posX;
    int y = this->posY;
    int offsetWheel = this->offsetWheel;

    this->posX = x +2;
    this->posY = y -1;
    this->offsetWheel = offsetWheel + 2;
*/
}

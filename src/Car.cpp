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

    Wheel firstWheel = Wheel(Point(this->posX + 80, this->posY + 60), 30);
    Wheel secondWheel = Wheel(Point(this->posX + 180, this->posY + 10), 30);

    backBody.draw();
    //frontBody.draw();

    firstWheel.draw();
    secondWheel.draw();

}

void Car::updatePosition()
{
    int x = this->posX;
    int y = this->posY;

    this->posX = x +2;
    this->posY = y -1;
}

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
    drawBodyCar();
    drawWheelsCar();
    updatePosition();
}

void Car::drawBodyCar()
{
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
}

void Car::drawWheelsCar()
{

}

void Car::updatePosition()
{
    int x = this->posX;
    int y = this->posY;

    this->posX = x +2;
    this->posY = y -1;
}

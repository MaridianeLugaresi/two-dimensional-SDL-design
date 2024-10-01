#include "Point.h"
#include<Radians.h>
#include<cmath>
#include<stdio.h>

Point::Point()
{
    //ctor
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
    //dtor
}


int Point::getX()
{
    return this->x;
}

int Point::getY()
{
    return this->y;
}

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

void Point::Translation(int X, int Y) {

    this->setX(X);
    this->setY(Y);

}

void Point::moveToOrigin(int X, int Y) {

    this->setX(X);
    this->setY(Y);

}

void Point::rotate(double degrees) {

    //p’(x,y) = p(x * cos(θ) - y * sin(θ), x * sin(θ) + y * cos(θ))

    Radians radians = Radians(degrees).toRadians();

    int testeX = this->getX();
    int testeY = this->getY();

    this->setX(testeX * cos(radians.degrees) - testeY * sin(radians.degrees));
    this->setY(testeX * sin(radians.degrees) + testeY * cos(radians.degrees));

}

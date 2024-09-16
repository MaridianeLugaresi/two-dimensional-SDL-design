#include "Point.h"
#include<Radians.h>
#include<cmath>

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

void Point::Rotate(double degrees) {

    //p’(x,y) = p(x * cos(θ) - y * sin(θ), x * sin(θ) + y * cos(θ))

    Radians radians = Radians(degrees).toRadians();

    this->setX(this->getX() * cos(radians.degrees) - this->getY() * sin(radians.degrees));
    this->setY(this->getX() * sin(radians.degrees) + this->getY() * cos(radians.degrees));

}


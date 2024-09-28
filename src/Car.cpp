#include "Car.h"
#include<Line.h>
#include<Point.h>
#include<Polygon.h>
#include<stdio.h>
#include<Circle.h>
#include <Color.h>
#include <unistd.h>
#include <Wheel.h>
#include<Polygon.h>

Car::Car()
{
    this->anchor = Point(0,0);
    this->angleRotation = 330;
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

    points.push_back(Point(34 + this->anchor.getX(), 410 + this->anchor.getY()));
    points.push_back(Point(36 + this->anchor.getX(), 442 + this->anchor.getY()));
    points.push_back(Point(37 + this->anchor.getX(), 457 + this->anchor.getY()));
    points.push_back(Point(41 + this->anchor.getX(), 466 + this->anchor.getY()));
    points.push_back(Point(53 + this->anchor.getX(), 468 + this->anchor.getY()));
    points.push_back(Point(57 + this->anchor.getX(), 448 + this->anchor.getY()));
    points.push_back(Point(62 + this->anchor.getX(), 439 + this->anchor.getY()));
    points.push_back(Point(91 + this->anchor.getX(), 439 + this->anchor.getY()));
    points.push_back(Point(98 + this->anchor.getX(), 445 + this->anchor.getY()));
    points.push_back(Point(104 + this->anchor.getX(), 451 + this->anchor.getY()));
    points.push_back(Point(112 + this->anchor.getX(), 467 + this->anchor.getY()));
    points.push_back(Point(161 + this->anchor.getX(), 471 + this->anchor.getY()));
    points.push_back(Point(235 + this->anchor.getX(), 475 + this->anchor.getY()));
    points.push_back(Point(240 + this->anchor.getX(), 461 + this->anchor.getY()));
    points.push_back(Point(245 + this->anchor.getX(), 448 + this->anchor.getY()));
    points.push_back(Point(250 + this->anchor.getX(), 439 + this->anchor.getY()));
    points.push_back(Point(287 + this->anchor.getX(), 439 + this->anchor.getY()));
    points.push_back(Point(291 + this->anchor.getX(), 443 + this->anchor.getY()));
    points.push_back(Point(297 + this->anchor.getX(), 452 + this->anchor.getY()));
    points.push_back(Point(301 + this->anchor.getX(), 467 + this->anchor.getY()));
    points.push_back(Point(311 + this->anchor.getX(), 467 + this->anchor.getY()));
    points.push_back(Point(324 + this->anchor.getX(), 455 + this->anchor.getY()));
    points.push_back(Point(324 + this->anchor.getX(), 443 + this->anchor.getY()));
    points.push_back(Point(316 + this->anchor.getX(), 433 + this->anchor.getY()));
    points.push_back(Point(311 + this->anchor.getX(), 418 + this->anchor.getY()));
    points.push_back(Point(308 + this->anchor.getX(), 415 + this->anchor.getY()));
    points.push_back(Point(295 + this->anchor.getX(), 411 + this->anchor.getY()));
    points.push_back(Point(284 + this->anchor.getX(), 408 + this->anchor.getY()));
    points.push_back(Point(269 + this->anchor.getX(), 406 + this->anchor.getY()));
    points.push_back(Point(236 + this->anchor.getX(), 402 + this->anchor.getY()));
    points.push_back(Point(203 + this->anchor.getX(), 376 + this->anchor.getY()));
    points.push_back(Point(189 + this->anchor.getX(), 370 + this->anchor.getY()));
    points.push_back(Point(169 + this->anchor.getX(), 367 + this->anchor.getY()));
    points.push_back(Point(62 + this->anchor.getX(), 365 + this->anchor.getY()));
    points.push_back(Point(58 + this->anchor.getX(), 369 + this->anchor.getY()));
    points.push_back(Point(39 + this->anchor.getX(), 369 + this->anchor.getY()));
    points.push_back(Point(32 + this->anchor.getX(), 397 + this->anchor.getY()));

    Polygon polygon = Polygon(points, this->angleRotation);
    polygon.rotate();
    polygon.draw();
}

void Car::drawWheelsCar()
{

}

void Car::updatePosition()
{
    int x = this->anchor.getX();
    int y = this->anchor.getY();

    printf("%d\n", x);

    this->anchor.setX(x + 2);
    this->anchor.setY(y - 1);

    if(x > 300)
    {
        this->anchor.setX(0);
        this->anchor.setY(0);
    }
}

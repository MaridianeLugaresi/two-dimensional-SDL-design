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
    this->offsetWheel = 0;
}

Car::~Car()
{
    //dtor
}

void Car::draw() {
    drawBodyCar();
    drawWheelsCar();
    drawWindowsCar();
    drawWindshieldCar();
    drawRearWindshieldCar();
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
    points.push_back(Point(53 + this->anchor.getX(), 448 + this->anchor.getY()));
    points.push_back(Point(62 + this->anchor.getX(), 427 + this->anchor.getY()));
    points.push_back(Point(90 + this->anchor.getX(), 425 + this->anchor.getY()));
    points.push_back(Point(105 + this->anchor.getX(), 425 + this->anchor.getY()));
    points.push_back(Point(115 + this->anchor.getX(), 440 + this->anchor.getY()));
    points.push_back(Point(116 + this->anchor.getX(), 471 + this->anchor.getY()));
    points.push_back(Point(161 + this->anchor.getX(), 472 + this->anchor.getY()));
    points.push_back(Point(236 + this->anchor.getX(), 475 + this->anchor.getY()));
    points.push_back(Point(237 + this->anchor.getX(), 461 + this->anchor.getY()));
    points.push_back(Point(240 + this->anchor.getX(), 448 + this->anchor.getY()));
    points.push_back(Point(250 + this->anchor.getX(), 439 + this->anchor.getY()));
    points.push_back(Point(287 + this->anchor.getX(), 439 + this->anchor.getY()));
    points.push_back(Point(298 + this->anchor.getX(), 455 + this->anchor.getY()));
    points.push_back(Point(298 + this->anchor.getX(), 480 + this->anchor.getY()));
    points.push_back(Point(301 + this->anchor.getX(), 480 + this->anchor.getY()));
    points.push_back(Point(311 + this->anchor.getX(), 480 + this->anchor.getY()));
    points.push_back(Point(324 + this->anchor.getX(), 465 + this->anchor.getY()));
    points.push_back(Point(324 + this->anchor.getX(), 443 + this->anchor.getY()));
    points.push_back(Point(316 + this->anchor.getX(), 433 + this->anchor.getY()));
    points.push_back(Point(311 + this->anchor.getX(), 418 + this->anchor.getY()));
    points.push_back(Point(308 + this->anchor.getX(), 415 + this->anchor.getY()));
    points.push_back(Point(295 + this->anchor.getX(), 411 + this->anchor.getY()));
    points.push_back(Point(284 + this->anchor.getX(), 408 + this->anchor.getY()));
    points.push_back(Point(269 + this->anchor.getX(), 406 + this->anchor.getY()));
    points.push_back(Point(236 + this->anchor.getX(), 402 + this->anchor.getY()));
    points.push_back(Point(203 + this->anchor.getX(), 356 + this->anchor.getY()));
    points.push_back(Point(189 + this->anchor.getX(), 350 + this->anchor.getY()));
    points.push_back(Point(169 + this->anchor.getX(), 347 + this->anchor.getY()));
    points.push_back(Point(62 + this->anchor.getX(), 345 + this->anchor.getY()));
    points.push_back(Point(58 + this->anchor.getX(), 349 + this->anchor.getY()));
    points.push_back(Point(39 + this->anchor.getX(), 349 + this->anchor.getY()));
    points.push_back(Point(32 + this->anchor.getX(), 397 + this->anchor.getY()));

    Polygon polygon = Polygon(points, this->angleRotation, Color(40,20,100));
    polygon.rotate();
    polygon.draw();
}

void Car::drawWindowsCar()
{
    list<Point> points;

    //Windows borders
    points.push_back(Point(140 + this->anchor.getX(), 290 + this->anchor.getY()));
    points.push_back(Point(160 + this->anchor.getX(), 320 + this->anchor.getY()));
    points.push_back(Point(140 + this->anchor.getX(), 320 + this->anchor.getY()));
    points.push_back(Point(24 + this->anchor.getX(), 320 + this->anchor.getY()));
    points.push_back(Point(14 + this->anchor.getX(), 310 + this->anchor.getY()));
    points.push_back(Point(14 + this->anchor.getX(), 300 + this->anchor.getY()));
    points.push_back(Point(24 + this->anchor.getX(), 290 + this->anchor.getY()));

    Polygon windowBorders = Polygon(points, this->angleRotation, Color(0,0,0));
    windowBorders.rotate();
    windowBorders.draw();

    //Inside window edges
    points.clear();
    points.push_back(Point(53 + this->anchor.getX(), 368 + this->anchor.getY()));
    points.push_back(Point(47 + this->anchor.getX(), 363 + this->anchor.getY()));
    points.push_back(Point(47 + this->anchor.getX(), 353 + this->anchor.getY()));
    points.push_back(Point(53 + this->anchor.getX(), 348 + this->anchor.getY()));

    Polygon edgeOfWindow = Polygon(points, this->angleRotation, Color(75,75,75));
    edgeOfWindow.rotate();
    edgeOfWindow.draw();

    points.clear();
    points.push_back(Point(100 + this->anchor.getX(), 341 + this->anchor.getY()));
    points.push_back(Point(50 + this->anchor.getX(), 342 + this->anchor.getY()));
    points.push_back(Point(50 + this->anchor.getX(), 322 + this->anchor.getY()));
    points.push_back(Point(100 + this->anchor.getX(), 321 + this->anchor.getY()));

    edgeOfWindow.setPoints(points);
    edgeOfWindow.rotate();
    edgeOfWindow.draw();

    points.clear();
    points.push_back(Point(146 + this->anchor.getX(), 314 + this->anchor.getY()));
    points.push_back(Point(96 + this->anchor.getX(), 315 + this->anchor.getY()));
    points.push_back(Point(96 + this->anchor.getX(), 295 + this->anchor.getY()));
    points.push_back(Point(146 + this->anchor.getX(), 294 + this->anchor.getY()));

    edgeOfWindow.setPoints(points);
    edgeOfWindow.rotate();
    edgeOfWindow.draw();

    points.clear();
    points.push_back(Point(140 + this->anchor.getX(), 295 + this->anchor.getY()));
    points.push_back(Point(155 + this->anchor.getX(), 316 + this->anchor.getY()));
    points.push_back(Point(140 + this->anchor.getX(), 315 + this->anchor.getY()));

    edgeOfWindow.setPoints(points);
    edgeOfWindow.rotate();
    edgeOfWindow.draw();
}

void Car::drawWindshieldCar()
{
    list<Point> points;

    points.push_back(Point(160 + this->anchor.getX(), 280 + this->anchor.getY()));
    points.push_back(Point(145 + this->anchor.getX(), 280 + this->anchor.getY()));
    points.push_back(Point(165 + this->anchor.getX(), 310 + this->anchor.getY()));
    points.push_back(Point(210 + this->anchor.getX(), 310 + this->anchor.getY()));

    Polygon windshield = Polygon(points, this->angleRotation, Color(0,0,0));
    windshield.rotate();
    windshield.draw();

    points.clear();
    points.push_back(Point(150 + this->anchor.getX(), 280 + this->anchor.getY()));
    points.push_back(Point(145 + this->anchor.getX(), 280 + this->anchor.getY()));
    points.push_back(Point(165 + this->anchor.getX(), 310 + this->anchor.getY()));
    points.push_back(Point(205 + this->anchor.getX(), 310 + this->anchor.getY()));

    Polygon windshieldInside = Polygon(points, this->angleRotation, Color(75,75,75));
    windshieldInside.rotate();
    windshieldInside.draw();
}

void Car::drawRearWindshieldCar()
{
    list<Point> points;

    points.push_back(Point(12 + this->anchor.getX(), 362 + this->anchor.getY()));
    points.push_back(Point(27 + this->anchor.getX(), 362 + this->anchor.getY()));
    points.push_back(Point(25 + this->anchor.getX(), 392 + this->anchor.getY()));
    points.push_back(Point(10 + this->anchor.getX(), 392 + this->anchor.getY()));

    Polygon rearWindshield = Polygon(points, this->angleRotation, Color(0,0,0));
    rearWindshield.rotate();
    rearWindshield.draw();

    points.clear();
    points.push_back(Point(14 + this->anchor.getX(), 367 + this->anchor.getY()));
    points.push_back(Point(24 + this->anchor.getX(), 367 + this->anchor.getY()));
    points.push_back(Point(22 + this->anchor.getX(), 387 + this->anchor.getY()));
    points.push_back(Point(12 + this->anchor.getX(), 387 + this->anchor.getY()));

    Polygon rearWindshieldInside = Polygon(points, this->angleRotation, Color(75,75,75));
    rearWindshieldInside.rotate();
    rearWindshieldInside.draw();
}

void Car::drawWheelsCar()
{

    Wheel wheelLeft = Wheel(Point(95 + this->anchor.getX(), 425 + this->anchor.getY()), 25, this->offsetWheel);
    wheelLeft.rotate();
    wheelLeft.draw();

    Wheel wheelRight = Wheel(Point(260 + this->anchor.getX(), 340 + this->anchor.getY()), 25, this->offsetWheel);
    wheelRight.rotate();
    wheelRight.draw();

}

void Car::updatePosition()
{
    int x = this->anchor.getX();
    int y = this->anchor.getY();

    this->anchor.setX(x + 2);
    this->anchor.setY(y - 1);

    this->offsetWheel += 2;
    if(this->offsetWheel > 25)
    {
        this->offsetWheel = 0;
    }

    if(x > 300)
    {
        this->anchor.setX(0);
        this->anchor.setY(0);
    }
}

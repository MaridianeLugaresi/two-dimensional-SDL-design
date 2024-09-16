#include "Car.h"
#include<Line.h>
#include<Point.h>
#include<Polygon.h>

Car::Car()
{

    this->topLeftPoint = Point(200,300);
    this->topRightPoint = Point(400,300);
    this->bottomLeftPoint = Point(200,400);
    this->bottomRightPoint = Point(400,400);

    this->topLeftPoint.Rotate(30);
    this->topRightPoint.Rotate(30);
    this->bottomLeftPoint.Rotate(30);
    this->bottomRightPoint.Rotate(30);

}

void Car::draw() {

    Polygon body = Polygon(Color(0, 0, 0));

    body.points.push_back(this->topLeftPoint);
    body.points.push_back(this->topRightPoint);
    body.points.push_back(this->bottomRightPoint);
    body.points.push_back(this->bottomLeftPoint);

    body.draw();
}

Car::~Car()
{
    //dtor
}

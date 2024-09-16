#include "Car.h"
#include<Line.h>
#include<Point.h>
#include<Polygon.h>

Car::Car()
{

    this->topLeftPoint = Point(200,350);
    this->topRightPoint = Point(400,350);
    this->bottomLeftPoint = Point(200,400);
    this->bottomRightPoint = Point(400,400);

}

void Car::draw() {

    Polygon body = Polygon(Color(0,0,0));
    body.points.push_back(this->topLeftPoint);
    body.points.push_back(this->topRightPoint);
    body.points.push_back(this->bottomLeftPoint);
    body.points.push_back(this->bottomRightPoint);

    body.draw();

}



Car::~Car()
{
    //dtor
}

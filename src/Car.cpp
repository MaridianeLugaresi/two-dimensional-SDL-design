#include "Car.h"
#include<Line.h>
#include<Point.h>
#include<Polygon.h>
#include<stdio.h>

Car::Car()
{

    this->topLeftPoint = Point(topLeftPointX,topLeftPointY);
    this->topRightPoint = Point(topRightPointX,topRightPointY);
    this->bottomLeftPoint = Point(bottomLeftPointX,bottomLeftPointY);
    this->bottomRightPoint = Point(bottomRightPointX,bottomRightPointY);
    this->angleRotation = -30;

}

void Car::draw() {

    Polygon body = Polygon(Color(0, 0, 0));


    this->topLeftPoint.Translation(this->topLeftPointX-this->topLeftPointX, this->topLeftPointY-this->topLeftPointY);
    this->topRightPoint.Translation(this->topRightPointX-this->topLeftPointX, this->topRightPointY-this->topRightPointY);
    this->bottomLeftPoint.Translation(this->bottomLeftPointX-this->bottomLeftPointX, this->bottomLeftPointY-this->topLeftPointY);
    this->bottomRightPoint.Translation(this->bottomRightPointX-this->bottomLeftPointX, this->bottomRightPointY-this->topLeftPointY);


    this->topLeftPoint.Rotate(this->angleRotation);
    this->topRightPoint.Rotate(this->angleRotation);
    this->bottomLeftPoint.Rotate(this->angleRotation);
    this->bottomRightPoint.Rotate(this->angleRotation);


    this->topLeftPoint.Translation(this->topLeftPoint.getX() + this->topLeftPointX, this->topLeftPoint.getY() + this->topLeftPointY);
    this->topRightPoint.Translation(this->topRightPoint.getX() + this->topRightPointX, this->topRightPoint.getY() + this->topRightPointY);
    this->bottomLeftPoint.Translation(this->bottomLeftPoint.getX() + this->bottomLeftPointX, this->bottomLeftPoint.getY() + this->bottomLeftPointY);
    this->bottomRightPoint.Translation(this->bottomRightPoint.getX() + this->bottomRightPointX, this->bottomRightPoint.getY() + this->topRightPointY);

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

void Car::updatePosition()
{
    this->topLeftPoint.setX((this->topLeftPoint.getX() - 2));
    this->topLeftPoint.setY(this->topLeftPoint.getY() - 2);
    this->topRightPoint.setX(this->topRightPoint.getX() - 2);
    this->topRightPoint.setY(this->topRightPoint.getY() - 2);
    this->bottomLeftPoint.setX(this->bottomLeftPoint.getX() - 2);
    this->bottomLeftPoint.setY(this->bottomLeftPoint.getY() - 2);
    this->bottomRightPoint.setX(this->bottomRightPoint.getX() - 2);
    this->bottomRightPoint.setY(this->bottomRightPoint.getY() - 2);
}

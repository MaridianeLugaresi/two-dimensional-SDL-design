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

}

void Car::draw() {

    Polygon body = Polygon(Color(0, 0, 0));

    this->topLeftPoint.Translation(this->topLeftPointX-this->topLeftPointX, this->topLeftPointY-this->topLeftPointY);
    this->topRightPoint.Translation(this->topRightPointX-this->topLeftPointX, this->topRightPointY-this->topRightPointY);
    this->bottomLeftPoint.Translation(this->bottomLeftPointX-this->bottomLeftPointX, this->bottomLeftPointY-this->topLeftPointY);
    this->bottomRightPoint.Translation(this->bottomRightPointX-this->bottomLeftPointX, this->bottomRightPointY-this->topLeftPointY);

    #TODO: rotação ao contrário
    this->topLeftPoint.Rotate(30);
    this->topRightPoint.Rotate(30);
    this->bottomLeftPoint.Rotate(30);
    this->bottomRightPoint.Rotate(30);

    #TODO: revisar cálculo
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

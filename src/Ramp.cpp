#include "Ramp.h"
#include<Point.h>
#include<Line.h>
#include<Color.h>
#include<Radians.h>
#include<stdio.h>
#include<Polygon.h>

Ramp::Ramp()
{
    this->anchor = Point(56,479);
    this->angleRotation = 0;
}

void Ramp::draw() {

    list<Point> points;

    points.push_back(Point(this->anchor.getX(), this->anchor.getY()));
    points.push_back(Point(this->anchor.getX() + 583, this->anchor.getY() - 297));
    points.push_back(Point(this->anchor.getX() + 583, this->anchor.getY()));

    Polygon polygon = Polygon(points, this->angleRotation, Color(160,160,160));
    polygon.rotate();
    polygon.draw();

}

Ramp::~Ramp()
{
    //dtor
}

#include "Ramp.h"
#include<Point.h>
#include<Line.h>
#include<Color.h>
#include<Radians.h>
#include<stdio.h>
#include<Polygon.h>

Ramp::Ramp()
{
    this->anchor = Point(50,479);
    this->angleRotation = 0;
}

void Ramp::draw() {

    list<Point> points;

    points.push_back(Point(this->anchor.getX(), this->anchor.getY()));
    points.push_back(Point(this->anchor.getX() + 589, this->anchor.getY() - 299));
    points.push_back(Point(this->anchor.getX() + 589, this->anchor.getY()));

    Polygon polygon = Polygon(points, this->angleRotation, Color(226,226,226));
    polygon.rotate();
    polygon.draw();

}

Ramp::~Ramp()
{
    //dtor
}

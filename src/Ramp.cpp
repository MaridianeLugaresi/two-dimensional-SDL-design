#include "Ramp.h"
#include<Point.h>
#include<Line.h>
#include<Color.h>
#include<Radians.h>
#include<stdio.h>

Ramp::Ramp()
{
    this->anchor = Point(50,479);
    this->angleRotation = 30;
}

void Ramp::draw() {

    Color color = Color(0,0,0);

    Point pointInitial = Point(50,479);
    Point pointEnd = Point(639,479);

    pointEnd.moveToOrigin(pointEnd.getX() - pointInitial.getX(), pointEnd.getY() - pointEnd.getY());
    pointInitial.moveToOrigin(pointInitial.getX() - pointInitial.getX(), pointInitial.getY() - pointInitial.getY());

    pointInitial.rotate(this->angleRotation);
    pointEnd.rotate(this->angleRotation);

    pointInitial.Translation(pointInitial.getX() + this->anchor.getX(), pointInitial.getY() + this->anchor.getY());
    pointEnd.Translation(639, this->anchor.getY() - pointEnd.getY());

    this->line = Line(pointInitial, pointEnd, color);
    this->line.draw();

}

Ramp::~Ramp()
{
    //dtor
}

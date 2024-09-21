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

    pointInitial.Rotate(this->angleRotation);
    pointEnd.Rotate(this->angleRotation);

    pointInitial.Translation(pointInitial.getX() + this->anchor.getX(), pointInitial.getY() + this->anchor.getY());
    pointEnd.Translation(pointEnd.getX() + pointInitial.getX(), this->anchor.getY() - pointEnd.getY());

    printf("Inicial %d    %d \n", pointInitial.getX(), pointInitial.getY());
    printf("Final   %d    %d \n", pointEnd.getX(), pointEnd.getY());

    this->line = Line(pointInitial, pointEnd, color);
    this->line.draw();

}

Ramp::~Ramp()
{
    //dtor
}

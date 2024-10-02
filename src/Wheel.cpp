#include "Wheel.h"
#include<Circle.h>
#include<Point.h>
#include<Line.h>
#include <stdio.h>
#include<cmath>

Wheel::Wheel(Point anchor, int radius, int offset, Color wheelColor, Color radiusColor)
{
    this->anchor = anchor;
    this->offset = offset;
    this->posX = anchor.getX();
    this->posY = anchor.getY();
    this->inCircle = Circle(anchor, radius, Color(200,200,200));
    this->outCircle = Circle(anchor, radius + 5, wheelColor);
    this->firstRadius = Line(Point(this->posX, this->posY - radius), Point(this->posX, this->posY + radius), radiusColor);
    this->secondRadius = Line(Point(this->posX - radius, this->posY), Point(this->posX + radius, this->posY), radiusColor);
}

Wheel::~Wheel()
{
    //dtor
}

void Wheel::draw()
{
    this->outCircle.draw();
    this->inCircle.draw();
    this->firstRadius.draw();
    this->secondRadius.draw();
}

void Wheel::rotate()
{

    //SAVE THE VALUES OF LINES
    Line firstLine = this->firstRadius;
    Line secondLine = this->secondRadius;

    //MOVE TO ORIGIN POSITION AND ROTATE
    this->firstRadius.rotate(Point(firstLine.start.getX(),
                                   firstLine.start.getY()),
                             Point(firstLine.end.getX(),
                                   firstLine.end.getY()),
                             this->offset);

    this->secondRadius.rotate(Point(secondLine.start.getX(),
                                    secondLine.start.getY()),
                              Point(secondLine.end.getX(),
                                    secondLine.end.getY()),
                              this->offset);

    //MOVES TO THE ROTATED POSITION
    this->firstRadius.translation(Point(firstLine.start.getX() + this->offset,
                                        firstLine.start.getY() + this->offset),
                                  Point(firstLine.end.getX() - this->offset,
                                        firstLine.end.getY() - this->offset));

    this->secondRadius.translation(Point(secondLine.start.getX() + this->offset,
                                         secondLine.start.getY() - this->offset),
                                   Point(secondLine.end.getX() - this->offset,
                                         secondLine.end.getY() + this->offset));

}

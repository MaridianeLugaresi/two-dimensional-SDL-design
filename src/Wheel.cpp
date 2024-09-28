#include "Wheel.h"
#include<Circle.h>
#include<Point.h>
#include<Line.h>
#include <stdio.h>
#include<cmath>

Wheel::Wheel(Point anchor, int radius, int offset)
{
    this->anchor = anchor;
    this->offset = offset;
    this->posX = anchor.getX();
    this->posY = anchor.getY();
    this->circle = Circle(anchor.getX(), anchor.getY(), radius);
    this->firstRadius = Line(Point(this->posX, this->posY - radius), Point(this->posX, this->posY + radius),Color(0,0,0));
    this->secondRadius = Line(Point(this->posX - radius, this->posY), Point(this->posX + radius, this->posY),Color(0,0,0));
}

Wheel::~Wheel()
{
    //dtor
}

void Wheel::draw()
{
    this->firstRadius.draw();
    this->secondRadius.draw();
    this->circle.drawBresenhamCircle();

}

void Wheel::rotate()
{

    //SAVE THE VALUES OF LINES
    Line firstLine = this->firstRadius;
    Line secondLine = this->secondRadius;

    //MOVE TO ORIGIN POSITION AND ROTATE
    this->firstRadius.rotate(Point(firstLine.start.getX() - firstLine.start.getX(),
                                   firstLine.start.getY() - firstLine.start.getY()),
                             Point(firstLine.end.getX() - firstLine.end.getX(),
                                   firstLine.end.getY() - firstLine.start.getY()), 30);

    this->secondRadius.rotate(Point(secondLine.start.getX() - secondLine.start.getX(),
                                   secondLine.start.getY() - secondLine.start.getY()),
                             Point(secondLine.end.getX() - secondLine.start.getX(),
                                   secondLine.end.getY() - secondLine.end.getY()), 30);

    //MOVES TO THE ROTATED POSITION
    this->firstRadius.translation(Point(this->firstRadius.start.getX() + this->anchor.getX(),
                                        this->firstRadius.start.getY() + this->anchor.getY()),
                                  Point(this->firstRadius.end.getX() + this->anchor.getX(),
                                        this->firstRadius.end.getY() + this->anchor.getY()));

    this->secondRadius.translation(Point(this->secondRadius.start.getX() + this->anchor.getX(),
                                        this->secondRadius.start.getY() + this->anchor.getY()),
                                  Point(this->secondRadius.end.getX() + this->anchor.getX(),
                                        this->secondRadius.end.getY() + this->anchor.getY()));

}

#include "Polygon.h"
#include<Point.h>
#include<list>
#include<Line.h>
#include<stdio.h>

Polygon::Polygon(list<Point> points, int degrees)
{
    this->points = points;
    this->degrees = degrees;
}

Polygon::~Polygon()
{
    //dtor
}

void Polygon::setPoints(list<Point> newPoints)
{
    this->points = newPoints;
}

void Polygon::rotate()
{
    Point first;
    Point before;
    Point atual;
    bool primeiro = true;
    list<Point> newPoints;

    for(Point p : this->points)
    {
        if(primeiro)
        {
            first = p;
            primeiro = false;
        }

        atual.setX(p.getX() - first.getX());
        atual.setY(p.getY() - first.getY());

        p.moveToOrigin(atual.getX(), atual.getY());
        p.rotate(this->degrees);
        p.Translation(p.getX() + first.getX(),p.getY() + first.getY());

        newPoints.push_back(p);
    }

    this->setPoints(newPoints);
}

void Polygon::draw()
{
    Point primeiro = this->points.front();
    Point anterior = this->points.front();
    Point atual;
    Line line;

    int i = 0;
    for(Point p : this->points)
    {
        if(i>0)
        {
            atual = p;
            line.drawWuLine(anterior.getX(), anterior.getY(), atual.getX(), atual.getY(), Color(0,0,0));
            anterior = atual;
        }
        i++;
    }
    line.drawWuLine(atual.getX(), atual.getY(), primeiro.getX(), primeiro.getY(), Color(0,0,0));
}

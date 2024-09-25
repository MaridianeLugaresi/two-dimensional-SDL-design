#include "Polygon.h"
#include<Point.h>
#include<list>
#include<Line.h>

Polygon::Polygon(list<Point> points)
{
    this->points = points;
}

Polygon::~Polygon()
{
    //dtor
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

#include "Polygon.h"
#include<Point.h>
#include<list>
#include<Line.h>
#include<stdio.h>
#include "Context.h"

Polygon::Polygon(list<Point> points, int degrees, Color color)
{
    this->points = points;
    this->degrees = degrees;
    this->color = color;
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
            line.drawWuLine(anterior.getX(), anterior.getY(), atual.getX(), atual.getY(), this->color);
            anterior = atual;
        }
        i++;
    }
    line.drawWuLine(atual.getX(), atual.getY(), primeiro.getX(), primeiro.getY(), this->color);
    scanFill();
}

void Polygon::scanFill()
{
    SDL_Surface * window_surface = Context::getInstance()->getWindowSurface();

    int le[window_surface->h], re[window_surface->h], i, j;
    bool firstPoint = true;
    Point first;
    Point before;
    Line line;

    for (i = 0; i < window_surface->h; i++) {
        le[i] = window_surface->w;
        re[i] = 0;
    }

    for (Point p : this->points)
    {
        if (!firstPoint)
        {
            edgeDetected(before.getX(),
                         before.getY(),
                         p.getX(),
                         p.getY(),
                         le, re);
        }

        if (firstPoint)
        {
            first = p;
            firstPoint = false;
        }
        before = p;
    }

    edgeDetected(before.getX(),
                 before.getY(),
                 first.getX(),
                 first.getY(),
                 le, re);

    for (j = 0; j < window_surface->h; j++)
    {
        if (le[j] <= re[j]) {
            for (i = le[j]; i < re[j]; i++) {
                line.setPixel(i, j, this->color);
            }
        }
    }
}

void Polygon::edgeDetected(float x1, float y1, float x2, float y2, int *le, int *re)
{
    float temp, x, mx;
    int i;

    if (y1 > y2)
    {
        temp = x1, x1 = x2, x2 = temp;
        temp = y1, y1 = y2, y2 = temp;
    }

    if (y1 == y2)
        mx = 0;
    else
        mx = (x2 - x1) / (y2 - y1);

    x = x1;

    for (i = (int)y1; i <= (int)y2; i++)
    {
        if (x < (float)le[i]) le[i] = (int)x;
        if (x > (float)re[i]) re[i] = (int)x;
        x += mx;
    }
}

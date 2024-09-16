#include "Polygon.h"
#include<list>
#include<Line.h>
#include<Color.h>
#include<Point.h>
#include<stdio.h>

Polygon::Polygon(Color color)
{
    this->color = color;
}

void Polygon::draw() {

    Point primeiro = this->points.front();
    Point anterior = this->points.front();
    Point atual;

    Line line = Line(anterior, atual, this->color, 1);

    int i = 0;

    for(Point p : this->points) {
        if(i>0) {
            atual = p;
            line.start.setX(anterior.getX());
            line.start.setY(anterior.getY());
            line.end.setX(atual.getX());
            line.end.setY(atual.getY());

            printf("Passei aqui X: %d Y: %d \n", p.getX(), p.getY());

            line.draw();
            anterior = atual;
        }
        i++;
    }

    line.start.setX(atual.getX());
    line.start.setY(atual.getY());
    line.end.setX(primeiro.getX());
    line.end.setY(primeiro.getY());
    line.draw();

}

Polygon::~Polygon()
{
    //dtor
}

#include "Rectangle.h"
#include<Line.h>
#include<stdio.h>

Rectangle::Rectangle(Line superior, Line inferior, Line left, Line right)
{
    this->superior = superior;
    this->inferior = inferior;
    this->left = left;
    this->right = right;
}

Rectangle::~Rectangle()
{
    //dtor
}

void Rectangle::draw()
{
    this->superior.draw();
    this->inferior.draw();
    this->left.draw();
    this->right.draw();
}

void Rectangle::rotate(int angleRotation, Point anchor)
{
    //SALVA A POSICAO DAS LINHAS
    Line supLine = this->superior;
    Line infLine = this->inferior;
    Line leftLine = this->left;
    Line rightLine = this->right;

    printf("%d-%d\n", (infLine.start.getX() - infLine.start.getX()), (infLine.start.getY() - supLine.start.getY()));

    //MOVE PARA A ORIGEM
    this->superior.rotate(Point(supLine.start.getX() - supLine.start.getX(),
                                supLine.start.getY() - supLine.start.getY()),
                          Point(supLine.end.getX() - supLine.start.getX(),
                                supLine.end.getY() - supLine.end.getY()),
                          angleRotation);

    this->inferior.rotate(Point(infLine.start.getX() - infLine.start.getX(),
                                supLine.start.getY() - infLine.start.getY()),
                          Point(infLine.end.getX() - infLine.start.getX(),
                                supLine.end.getY() - infLine.end.getY()),
                          angleRotation);

    this->left.rotate(Point(leftLine.start.getX() - leftLine.start.getX(),
                            leftLine.start.getY() - leftLine.start.getY()),
                      Point(leftLine.end.getX() - leftLine.end.getX(),
                            supLine.start.getY() - leftLine.end.getY()),
                      angleRotation);

    this->right.rotate(Point(rightLine.start.getX() - supLine.start.getX(),
                             rightLine.start.getY() - rightLine.start.getY()),
                       Point(infLine.end.getX() - leftLine.end.getX(),
                             supLine.start.getY() - leftLine.end.getY()),
                       angleRotation);

    //MOVE NOVAMNTE PARA A ORIGEM

}

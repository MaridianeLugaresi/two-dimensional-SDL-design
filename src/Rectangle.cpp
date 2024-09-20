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
/*
    //MOVE NOVAMNTE PARA A ORIGEM
    this->superior.translation(Point(this->superior.start.getX() + supLine.start.getX(),
                                     this->superior.start.getY() + supLine.start.getY()),
                               Point(this->superior.end.getX() + supLine.end.getX(),
                                     this->superior.end.getY() + supLine.end.getY()));

    this->inferior.translation(Point(this->inferior.start.getX() + infLine.start.getX(),
                                     this->inferior.start.getY() + infLine.start.getY()),
                               Point(this->inferior.end.getX() + infLine.end.getX(),
                                     this->inferior.end.getY() + infLine.end.getY()));

    this->left.translation(Point(this->left.start.getX() + leftLine.start.getX(),
                                 this->left.start.getY() + leftLine.start.getY()),
                           Point(this->left.end.getX() + leftLine.end.getX(),
                                 this->left.end.getY() + leftLine.end.getY()));

    this->right.translation(Point(this->right.start.getX() + rightLine.start.getX(),
                                  this->right.start.getY() + rightLine.start.getY()),
                            Point(this->right.end.getX() + rightLine.end.getX(),
                                  this->right.end.getY() + rightLine.end.getY()));
*/
}

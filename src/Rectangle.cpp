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



    //MOVE NOVAMENTE PARA A POSICAO INICIAL
    this->superior.translation(Point(this->superior.start.getX() + anchor.getX(),
                                     this->superior.start.getY() + anchor.getY()),
                               Point(this->superior.end.getX() + anchor.getX(),
                                     this->superior.end.getY() + anchor.getY()));

    this->inferior.translation(Point(this->inferior.start.getX() + anchor.getX(),
                                     this->inferior.start.getY() + anchor.getY()),
                               Point(this->inferior.end.getX() + anchor.getX(),
                                     this->inferior.end.getY() + anchor.getY()));

    this->left.translation(Point(this->left.start.getX() + anchor.getX(),
                                 this->left.start.getY() + anchor.getY()),
                           Point(this->left.end.getX() + anchor.getX(),
                                 this->left.end.getY() + anchor.getY()));

    this->right.translation(Point(this->right.start.getX() + anchor.getX(),
                                  this->right.start.getY() + anchor.getY()),
                            Point(this->right.end.getX() + anchor.getX(),
                                  this->right.end.getY() + anchor.getY()));

}

#include "Rectangle.h"
#include<Line.h>

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

    Line supLine = this->superior;
    Line infLine = this->inferior;
    Line leftLine = this->left;
    Line rightLine = this->right;

}

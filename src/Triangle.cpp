#include "Triangle.h"
#include <Line.h>

Triangle::Triangle(Line diagonal, Line left, Line inferior)
{
    this->diagonal = diagonal;
    this->left = left;
    this->inferior = inferior;
}

Triangle::~Triangle()
{
    //dtor
}

void Triangle::draw()
{
    this->diagonal.draw();
    this->left.draw();
    this->inferior.draw();
}

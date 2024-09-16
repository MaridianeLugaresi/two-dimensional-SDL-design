#include "Ramp.h"
#include<Point.h>
#include<Line.h>
#include<Color.h>

Ramp::Ramp()
{
    Color color = Color(0,0,0);

    Point pointInitial = Point(50,479);
    Point pointEnd = Point(639,300);

    this->line = Line(pointInitial, pointEnd, color);


}

void Ramp::draw() {

    this->line.draw();

}

Ramp::~Ramp()
{
    //dtor
}

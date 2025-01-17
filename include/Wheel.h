#ifndef WHEEL_H
#define WHEEL_H
#include<Point.h>
#include<Circle.h>
#include<Line.h>
#include<Color.h>

class Wheel
{
    public:
        Wheel(Point anchor, int radius, int offset, Color wheelColor, Color radiusColor);
        virtual ~Wheel();
        void draw();
        void rotate();

    protected:

    private:
        int posX;
        int posY;
        Point anchor;
        Circle inCircle;
        Circle outCircle;
        Line firstRadius;
        Line secondRadius;
        int offset;

};

#endif // WHEEL_H

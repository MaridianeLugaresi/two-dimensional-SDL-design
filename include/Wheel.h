#ifndef WHEEL_H
#define WHEEL_H
#include<Point.h>
#include<Circle.h>
#include<Line.h>

class Wheel
{
    public:
        Wheel(Point anchor, int radius, int offset);
        virtual ~Wheel();
        void draw();

    protected:

    private:
        int posX;
        int posY;
        Point anchor;
        Circle circle;
        Line firstRadius;
        Line secondRadius;
        int offset;
        void rotate();

};

#endif // WHEEL_H

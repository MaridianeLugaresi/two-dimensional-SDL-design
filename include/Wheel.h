#ifndef WHEEL_H
#define WHEEL_H
#include<Point.h>
#include<Circle.h>
#include<Line.h>

class Wheel
{
    public:
        Wheel(Point anchor, int radius);
        virtual ~Wheel();
        void rotate();
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

};

#endif // WHEEL_H

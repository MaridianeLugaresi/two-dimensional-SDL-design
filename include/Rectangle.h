#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<Line.h>

class Rectangle
{
    public:
        Rectangle(Line superior, Line inferior, Line left, Line right);
        virtual ~Rectangle();
        void draw();
        void rotate(int angleRotation, Point anchor);

    protected:

    private:
        Line superior;
        Line inferior;
        Line left;
        Line right;

};

#endif // RECTANGLE_H

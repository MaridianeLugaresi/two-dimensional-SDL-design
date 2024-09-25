#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<Line.h>

class Triangle
{
    public:
        Triangle(Line diagonal, Line left, Line inferior);
        virtual ~Triangle();
        void draw();

    protected:

    private:
        Line diagonal;
        Line left;
        Line inferior;
};

#endif // TRIANGLE_H

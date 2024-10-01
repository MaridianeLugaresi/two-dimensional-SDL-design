#ifndef CIRCLE_H
#define CIRCLE_H
#include<Point.h>

class Circle
{
    public:
        Circle();
        Circle(Point anchor, int radius);
        virtual ~Circle();
        void drawBresenhamCircle();
        void updatePosition(int x, int y);
        void draw();
        Point anchor;

    protected:

    private:
        int radius;
        void displayBresenhamCircle(int x, int y);
        void floodFill();
        Point getPoint(int posX, int posY);
};

#endif // CIRCLE_H

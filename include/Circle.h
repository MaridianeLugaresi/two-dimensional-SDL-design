#ifndef CIRCLE_H
#define CIRCLE_H
#include<Point.h>
#include <Color.h>

class Circle
{
    public:
        Circle();
        Circle(Point anchor, int radius, Color color);
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
        Uint32 getPixel(int posX, int posY);
        Color color;
};

#endif // CIRCLE_H

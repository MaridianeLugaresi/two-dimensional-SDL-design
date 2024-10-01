#ifndef LINE_H
#define LINE_H
#include <Point.h>
#include <Color.h>
#include<SDL2/SDL.h>

class Line
{
    public:
        Line();
        Line(Point start, Point end, Color color);
        Line(Point start, Point end, Color color, int antialias);
        void setPixel(int x, int y, int r, int g, int b);
        void draw();
        virtual ~Line();
        Point start;
        Point end;
        void rotate(Point newStart, Point newEnd, int angleRotation);
        void translation(Point newStart, Point newEnd);
        void bezierCurve(int x[] , int y[], bool points, Uint32 color);
        void drawWuLine(int x0, int y0, int x1, int y1, Color color);
        void setPixel(int x, int y, Color color);
        Uint32 getPixel(int x, int y);
        void setPixel(int x, int y, Uint32 cor);

    protected:

    private:
        Color color;
        int antialias = 0;
        void setPixel(int x, int y, int r, int g, int b, int a);
        void bresenham(int x1, int y1, int x2, int y2, int r, int g, int b);
        void bezierTarget(int x, int y, Uint32 color);

};

#endif // LINE_H

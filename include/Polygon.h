#ifndef POLYGON_H
#define POLYGON_H
#include<Point.h>
#include <list>

using namespace std;

class Polygon
{
    public:
        Polygon(list<Point> points, int degrees);
        virtual ~Polygon();
        void draw();
        void rotate();

    protected:

    private:
        list<Point> points;
        int degrees;
        void setPoints(list<Point> points);
};

#endif // POLYGON_H

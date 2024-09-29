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
        void setPoints(list<Point> points);

    protected:

    private:
        list<Point> points;
        int degrees;
};

#endif // POLYGON_H

#ifndef POLYGON_H
#define POLYGON_H
#include<Point.h>
#include <list>

using namespace std;

class Polygon
{
    public:
        Polygon(list<Point> points);
        virtual ~Polygon();
        void draw();

    protected:

    private:
        list<Point> points;
};

#endif // POLYGON_H

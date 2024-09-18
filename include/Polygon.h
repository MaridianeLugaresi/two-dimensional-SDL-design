#ifndef POLYGON_H
#define POLYGON_H
#include<Point.h>
#include<Color.h>
#include<list>

class Polygon
{
    public:
        Polygon(Color color);
        virtual ~Polygon();
        std::list<Point> points;
        void draw();
        Color color;

    protected:

    private:

};

#endif // POLYGON_H

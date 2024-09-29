#ifndef POLYGON_H
#define POLYGON_H
#include<Point.h>
#include <list>
#include<Color.h>

using namespace std;

class Polygon
{
    public:
        Polygon(list<Point> points, int degrees, Color color);
        virtual ~Polygon();
        void draw();
        void rotate();
        void setPoints(list<Point> points);

    protected:

    private:
        list<Point> points;
        int degrees;
<<<<<<< HEAD
=======
        Color color;
        void setPoints(list<Point> points);
        void scanFill();
        void edgeDetected(float x1, float y1, float x2, float y2, int *le, int *re);
>>>>>>> 10ac7d7109ec5ff1ad333fd28b98dd911cde1d44
};

#endif // POLYGON_H

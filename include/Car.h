#ifndef CAR_H
#define CAR_H
#include<Point.h>

class Car
{
    public:
        Car();
        virtual ~Car();
        void draw();

    protected:
        Point topLeftPoint;
        Point topRightPoint;
        Point bottomLeftPoint;
        Point bottomRightPoint;

    private:

};

#endif // CAR_H

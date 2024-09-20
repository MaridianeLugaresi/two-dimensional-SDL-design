#ifndef CAR_H
#define CAR_H
#include<Point.h>

class Car
{
    public:
        Car();
        virtual ~Car();
        void draw();
        void updatePosition();

    private:
        Point anchor;
        int angleRotation;

};

#endif // CAR_H

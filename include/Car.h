#ifndef CAR_H
#define CAR_H
#include<Point.h>
#include<Wheel.h>

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
        int posX;
        int posY;
        int offsetWheel;

};

#endif // CAR_H

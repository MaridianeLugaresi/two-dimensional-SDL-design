#ifndef CAR_H
#define CAR_H
#include<Point.h>
#include<Wheel.h>
#include<list>

class Car
{
    public:
        Car();
        virtual ~Car();
        void draw();

    private:
        Point anchor;
        int angleRotation;
        int offsetWheel;

        void updatePosition();

        void drawBodyCar();
        void drawWheelsCar();

        void drawWindowsCar();

};

#endif // CAR_H

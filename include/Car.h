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

    private:
        Point anchor;
        int angleRotation;
        int offsetWheel;

        void updatePosition();

        void drawBodyCar();
        void drawWheelsCar();

        void drawWindowsCar();
        void drawWindshieldCar();
        void drawRearWindshieldCar();

};

#endif // CAR_H

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
        int posX;
        int posY;
        int offsetWheel;

        void updatePosition();

        void drawBodyCar();
        void drawWheelsCar();

};

#endif // CAR_H

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

        static const int topLeftPointX = 200;
        static const int topLeftPointY = 300;
        static const int topRightPointX = 400;
        static const int topRightPointY = 300;
        static const int bottomLeftPointX = 200;
        static const int bottomLeftPointY = 400;
        static const int bottomRightPointX = 400;
        static const int bottomRightPointY = 400;

    private:
        Point topLeftPoint;
        Point topRightPoint;
        Point bottomLeftPoint;
        Point bottomRightPoint;
        int angleRotation;
};

#endif // CAR_H

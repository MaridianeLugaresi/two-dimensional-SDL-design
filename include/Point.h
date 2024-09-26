#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(int x, int y);
        int getX();
        int getY();
        virtual ~Point();
        void Translation(int X, int Y);
        void rotate(double degrees);
        void moveToOrigin(int x, int y);
        void setX(int x);
        void setY(int y);

    protected:

    private:
        int x, y;
        int degrees;
};

#endif // POINT_H

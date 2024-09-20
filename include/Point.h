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
        void Rotate(double degrees);

    protected:

    private:
        int x, y;
        void setX(int x);
        void setY(int y);
};

#endif // POINT_H

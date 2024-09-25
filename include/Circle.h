#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
    public:
        Circle();
        Circle(int x, int y, int radius);
        virtual ~Circle();
        void drawBresenhamCircle();
        void updatePosition(int x, int y);

    protected:

    private:
        int posX;
        int posY;
        int radius;
        void displayBresenhamCircle(int x, int y);
};

#endif // CIRCLE_H

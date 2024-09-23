#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
    public:
        Circle();
        virtual ~Circle();
        void drawBresenhamCircle(int xc, int yc, int radius);
        void drawdetailsWheel(int posX, int posY);

    protected:

    private:
        void displayBresenhamCircle(int xc, int yc, int x, int y);
};

#endif // CIRCLE_H

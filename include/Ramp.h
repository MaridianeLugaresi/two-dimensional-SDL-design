#ifndef RAMP_H
#define RAMP_H
#include<Line.h>

class Ramp
{
    public:
        Ramp();
        virtual ~Ramp();
        void draw();

    protected:

    private:
        Point anchor;
        int angleRotation;
};

#endif // RAMP_H

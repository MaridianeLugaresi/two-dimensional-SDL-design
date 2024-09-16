#ifndef RADIANS_H
#define RADIANS_H


class Radians
{
    public:
        Radians(double degrees);
        virtual ~Radians();
        double toRadians();
        double degrees;

    protected:

    private:
};

#endif // RADIANS_H

#include "Radians.h"

Radians::Radians(double degrees)
{
    this->degrees = degrees;
}

Radians::~Radians()
{
    //dtor
}

double Radians::toRadians()
{
    return this->degrees * 0.017453293;
}

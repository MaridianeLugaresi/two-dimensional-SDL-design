#include "Circle.h"
#include<Line.h>
#include<Point.h>
#include<Polygon.h>
#include<stdio.h>
#include<Circle.h>
#include <Color.h>
#include <unistd.h>
#include <Wheel.h>
#include<Polygon.h>
#include<stack>
#include "Context.h"

Circle::Circle()
{

}

Circle::Circle(Point anchor, int radius)
{
    this->anchor = anchor;
    this->radius = radius;
}

Circle::~Circle()
{
    //dtor
}

void Circle::draw()
{
    drawBresenhamCircle();
    floodFill();
}

void Circle::floodFill()
{
    Line line = Line();
    Color color = Color();
    SDL_Surface * window_surface = Context::getInstance()->getWindowSurface();

    if (this->anchor.getY() < 0 || this->anchor.getY() > window_surface->h - 1 || this->anchor.getX() < 0 || this->anchor.getX() > window_surface->w - 1)
        return;

    stack<Point> st;
    st.push(getPoint(this->anchor.getX(), this->anchor.getY()));

    while (st.size() > 0) {
        Point p = st.top();
        st.pop();
        int x = p.getX();
        int y = p.getY();
        if (y < 0 || y > window_surface->h - 1 || x < 0 || x > window_surface->w - 1)
            continue;

        if (line.getPixel(x, y) == line.getPixel(this->anchor.getX(), this->anchor.getY())) {
            line.setPixel(x, y, color.RGB(255, 0, 0));
            st.push(getPoint(x + 1, y));
            st.push(getPoint(x - 1, y));
            st.push(getPoint(x, y + 1));
            st.push(getPoint(x, y - 1));
        }
    }
}

Point Circle::getPoint(int x, int y)
{
    Point p;
    p.setX(x);
    p.setY(y);
    return p;
}

void Circle::displayBresenhamCircle(int x, int y)
{
    Line line1;
    Line line2;
    Line line3;
    Line line4;
    Line line5;
    Line line6;
    Line line7;
    Line line8;

    line1.setPixel(this->anchor.getX()+x, this->anchor.getY()+y, 0, 0, 0);
    line2.setPixel(this->anchor.getX()-x, this->anchor.getY()+y, 0, 0, 0);
    line3.setPixel(this->anchor.getX()+x, this->anchor.getY()-y, 0, 0, 0);
    line4.setPixel(this->anchor.getX()-x, this->anchor.getY()-y, 0, 0, 0);
    line5.setPixel(this->anchor.getX()+y, this->anchor.getY()+x, 0, 0, 0);
    line6.setPixel(this->anchor.getX()-y, this->anchor.getY()+x, 0, 0, 0);
    line7.setPixel(this->anchor.getX()+y, this->anchor.getY()-x, 0, 0, 0);
    line8.setPixel(this->anchor.getX()-y, this->anchor.getY()-x, 0, 0, 0);
}

void Circle::drawBresenhamCircle()
{
    int x = 0, y = this->radius;
    int decesionParameter = 3 - 2 * this->radius;
    displayBresenhamCircle(x, y);

    while(y >= x)
    {
        x++;
        if(decesionParameter > 0)
        {
            y--;
            decesionParameter = decesionParameter + 4 * (x-y) + 10;
        }
        else
        {
            decesionParameter = decesionParameter + 4 * x + 6;
        }
        displayBresenhamCircle(x, y);
    }
}

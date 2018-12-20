#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class shape
{
    protected:

    public:
    shape();
    shape(float*, int);
    virtual std::string getType() = 0;
    virtual float getArea() = 0;
    virtual float circumference() = 0;
    virtual float* position() = 0;
    virtual bool convex() = 0;
    virtual float distance(std::string) = 0;
    ~shape();
};

#endif
#ifndef polygon_h
#define polygon_h
#include "shape.h"

class polygon : public shape
{
    protected:
        int halfCoordinates;
        float* xCoord;
        float* yCoord;
        float area = 0;
        float centerPosition[2];
        float *kValue;
        float positionX = 0;
        float positionY = 0;
        float total = 0;
        float xValue = 0;
        float yValue = 0;
        int lastCounter = 0;
        float lastValueX = 0;
        float lastValueY = 0;
        std::string type;
        float distanceToShape = 0;
        

    public:
        polygon();
        polygon(float*, int);
        std::string getType();
        float getArea();
        float circumference();
        float* position();
        bool convex();
        float distance(std::string);
        
        ~polygon();
};

#endif
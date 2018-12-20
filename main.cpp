#include <iostream>
#include <string>
#include <fstream>
#include "shape.h"
#include "polygon.h"

int main()
{
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);
    int coordinates;
    int halfCoordinates;
    float a = 0;

    std::ifstream testFile;
    testFile.open("test.txt");

    if(testFile.is_open())
    {
        while(testFile >> a)
        {
            coordinates += 1;
        }
    }
    halfCoordinates = coordinates/2;
    float *firstArray = new float[coordinates];
    float *xCoord = new float[halfCoordinates];
    float *yCoord = new float[halfCoordinates];

    testFile.close();
    testFile.open("test.txt");
        
    for(int i = 0; i < coordinates; i++)
    {  
        testFile >> firstArray[i];
    }
    testFile.close();
    
    polygon polygon(firstArray, halfCoordinates);
    polygon.getType();

    if(polygon.getType() == "Point")
    {
        std::cout << "The form of all vertices is a Point" << "\n";
    }
    if(polygon.getType() == "Line")
    {
        std::cout << "The form of all vertices are a Line" << "\n";
    }
    else if(polygon.getType() == "Triangle")
    {
        std::cout << "The form of all vertices are a Triangle" << "\n";
        std::cout << "The circumreferemce is: " << polygon.circumference() << "\n";
        std::cout << "The area is: " << polygon.getArea() << "\n";
        std::cout << "The center position is: " << polygon.position()[0] << ", " << polygon.position()[1] << "\n";
    }
    else if(polygon.getType() == "Polygon")
    {
        std::cout << "The form of all vertices are a Polygon" << "\n";
        polygon.convex();
        if(polygon.convex() == false)
        {
            std::cout << "The polygon is concave." << "\n";
            std::cout << "Center coordinates are: " << polygon.position()[0] << ", " << polygon.position()[1] << "\n";
            std::cout << "The circumreference is: " << polygon.circumference() << "\n";
            std::cout << "The area is: " << polygon.getArea() << "\n";
        }
        else
        {
            std::cout << "The polygon is convex." << "\n";
            std::cout <<"The area is: " << polygon.getArea() << "\n";
            std::cout << "The center of the bounding box are: " << polygon.position()[0] << ", " << polygon.position()[1] << "\n";
            std::cout << "The circumreference is: " << polygon.circumference() << "\n";
        }
    }

    system("Pause");
    return 0;
}
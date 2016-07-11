#include "Point.h"
#include <iostream>
using namespace std;


Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(float newX, float newY)
{
	x = newX;
	y = newY;
}

void Point::setPoint(float newX, float newY)
{
	x = newX;
	y = newY;
}
Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return *this;
}

Point::~Point()
{

}

void Point::print()const
{
	cout << "( " << x << " " << y << " )";
}
float Point::getX()const
{
	return x;
}

float Point::getY()const
{
	return y;
}

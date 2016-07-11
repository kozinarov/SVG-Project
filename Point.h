#pragma once
#ifndef __HEADER_Point__
#define __HEADER_Point__
#include <iostream>
using namespace std;

class Point
{
public:
public:
	Point();
	Point(float, float);
	Point& operator=(const Point&);
	void setPoint(float, float);
	void print()const;
	float getX()const;
	float getY()const;
	~Point();

private:
	float x;
	float y;
};

#endif //__HEADER_Point__
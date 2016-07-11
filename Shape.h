#pragma once
#ifndef __HEADER_Shape__
#define __HEADER_Shape__
#include "Point.h"
class Shape
{
public:
	virtual void printShape()const = 0;
	virtual bool isPointIn(Point)const = 0;
	virtual char* saveShape()const = 0;
	virtual void translate(Point) = 0;
	virtual char* isInstanceOf()const = 0;
	virtual bool InRectangle(float, float, float, float)const = 0;
	virtual bool InCircle(float, float, float)const = 0;
	Shape();
	virtual ~Shape();
};

#endif //__HEADER_Shape__
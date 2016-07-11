#pragma once
#ifndef __HEADER_Circle__
#define __HEADER_Circle__


#include "Shape.h"

using namespace std;
#include "Rectangle.h"

class Circle :
	public Shape
{
public:
	Circle();
	~Circle();
	Circle(float, float, float, char*);
	Circle(const Circle&);
	Circle& operator=(const Circle&);
	void create(float, float, float, char*);

public:
	void printShape()const;
	char* saveShape()const;
	bool isPointIn(Point)const;
	void translate(Point);
	char* isInstanceOf()const;

public:
	bool InRectangle(float, float, float, float)const;
	bool InCircle(float, float, float)const;

public:
	Point getCentre()const;
	float getRadius()const;

private:
	void copy(const Circle&);

private:
	Point centre;
	float radius;

	char* fill;
};

#endif //__HEADER_Circle__
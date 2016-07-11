#pragma once
#ifndef __HEADER_Line__
#define __HEADER_Line__

#include "Shape.h"

#include "Circle.h"
#include "Rectangle.h"

class Line :
	public Shape
{
public:
	Line();
	~Line();
	Line(float, float, float, float, char*);
	Line(const Line&);
	Line& operator=(const Line&);
	void create(float, float, float, float, char*);

public:
	void printShape()const;
	char* saveShape()const;
	bool isPointIn(Point)const;
	void translate(Point);
	char* isInstanceOf()const;

	Point getPoint1()const;
	Point getPoint2()const;

private:
	void copy(const Line&);

public:
	bool InRectangle(float, float, float, float)const;
	bool InCircle(float, float, float)const;

private:
	Point point1;
	Point point2;
	char* style;
};

#endif //__HEADER_Line__


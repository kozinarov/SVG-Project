#pragma once
#ifndef __HEADER_Rectangle__
#define __HEADER_Rectangle__

#include "Shape.h"
#include "Point.h"

using namespace std;

#include "Circle.h"

class Rectangle :
	public Shape
{
public:
	Rectangle();
	Rectangle(float, float, float, float, char*);
	Rectangle(const Rectangle&);
	Rectangle& operator=(const Rectangle&);
	~Rectangle();
	void create(float, float, float, float, char*);

public:
	void printShape()const;
	char* saveShape()const;
	bool isPointIn(Point)const;
	void translate(Point);
	char* isInstanceOf()const;

public:
	Point getDownLeft()const;
	Point getDownRight()const;
	Point getUpLeft()const;
	Point getUpRight()const;
	float getWidth()const;
	float getHeight()const;

public:
	bool InRectangle(float, float, float, float)const;
	bool InCircle(float, float, float)const;

private:
	void copy(const Rectangle&);

private:
	Point downLeft;
	Point downRight;
	Point upLeft;
	Point upRight;
	float width;
	float height;
	char* fill;

};

#endif //__HEADER_Reactangle__

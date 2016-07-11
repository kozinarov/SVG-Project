#pragma once
#ifndef __DynamicArray_HEADER__
#define __DynamicArray_HEADER__
#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(const DynamicArray&);
	DynamicArray& operator=(const DynamicArray&);
	~DynamicArray();
	Shape& operator[](const size_t)const;

	void addCircle(float, float, float, char*);
	void addLine(float, float, float, float, char*);
	void addRectangle(float, float, float, float, char*);
	void take(size_t);

	void translate(float, float, size_t);
	void translate(float, float);

	size_t getSize()const;
	size_t getCap()const;
	void printShapes()const;
private:
	void free();
	void copy(const DynamicArray&);
	void resize();


private:
	Shape ** array;
	size_t size;
	size_t cap;

};

#endif //__DynamicArray_HEADER__
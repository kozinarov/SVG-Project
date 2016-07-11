#include "Line.h"



Line::Line() : point1(0, 0), point2(0, 0), style(NULL)
{
}

Line::Line(float x1, float y1, float x2, float y2, char* newStyle)
{
	create(x1, y1, x2, y2, newStyle);
}

Line::Line(const Line& other)
{
	copy(other);
}

Line& Line::operator=(const Line& other)
{
	if (this != &other)
	{	
		delete[] style;
		copy(other);
	}
	return *this;
}

void Line::copy(const Line& other)
{
	point1 = other.point1;
	point2 = other.point2;
	style = new char[strlen(other.style) + 1];
	strcpy_s(style, strlen(other.style) + 1, other.style);

}
void Line::create(float x1, float y1, float x2, float y2, char* newStyle)
{
	point1.setPoint(x1, y1);
	point2.setPoint(x2, y2);
	delete[] style;
	style = new char[strlen(newStyle) + 1];
	strcpy_s(style, strlen(newStyle) + 1, newStyle);
}

void Line::printShape()const
{
	cout << "line " << point1.getX() << " " << point1.getY() << " " << point2.getX() << " " << point2.getY() << " " << style << " " << endl;

}

char* Line::saveShape()const
{
	char* s = new char[256];
	sprintf_s(s, 256, "  <line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"%s\" />\n", point1.getX(), point1.getY(), point2.getX(), point2.getY(), style);
	return s;
}

void Line::translate(Point translator)
{
	point1.setPoint(point1.getX() + translator.getX(), point1.getY() + translator.getY());
	point2.setPoint(point2.getX() + translator.getX(), point2.getY() + translator.getY());

}
bool Line::isPointIn(Point peak)const
{
	//This function isn't needed for line
	return true;
}

char* Line::isInstanceOf()const
{
	char* r = "Line";
	return r;
}

Point Line::getPoint1()const
{
	return point1;
}
Point Line::getPoint2()const
{
	return point2;
}

bool Line::InRectangle(float rx, float ry, float rWidth, float rHeight)const
{
	//the colour is not needed
	Rectangle r(rx, ry, rWidth, rHeight, "red");
	bool p1In = r.isPointIn(point1);
	bool p2In = r.isPointIn(point2);
	if (p1In == true && p2In == true)
	{
		return true;
	}
	return false;
}
bool Line::InCircle(float cx, float cy, float cRadius)const
{
	//the colour is not needed
	Circle c(cx, cy, cRadius, "red");
	bool p1In = c.isPointIn(point1);
	bool p2In = c.isPointIn(point2);
	if (p1In == true && p2In == true)
	{
		return true;
	}
	return false;
}

Line::~Line()
{
}

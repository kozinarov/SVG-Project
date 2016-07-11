#include "Circle.h"


Circle::Circle() : centre(0, 0), radius(0), fill(NULL)
{
}

Circle::Circle(float x, float y, float newRadius, char* newFill)
{
	create(x, y, newRadius, newFill);
}

Circle::Circle(const Circle& other)
{
	copy(other);
}

Circle& Circle::operator=(const Circle& other)
{
	if (this != &other)
	{	
		delete[] fill;
		copy(other);
	}
	return *this;
}

void Circle::copy(const Circle& other)
{
	centre = other.centre;
	radius = other.radius;
	fill = other.fill;
	fill = new char[strlen(other.fill) + 1];
	strcpy_s(fill, strlen(other.fill) + 1, other.fill);

}

void Circle::create(float x, float y, float newRadius, char* newFill)
{
	centre.setPoint(x, y);
	radius = newRadius;
	delete[] fill;
	fill = new char[strlen(newFill) + 1];
	strcpy_s(fill, strlen(newFill) + 1, newFill);
}

void Circle::printShape()const
{
	cout << "circle " << centre.getX() << " " << centre.getY() << " " << radius << " " << fill << " " << endl;

}

char* Circle::saveShape()const
{
	char* s = new char[256];
	sprintf_s(s, 256, "  <circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" />\n", centre.getX(), centre.getY(), radius, fill);
	return s;
}

void Circle::translate(Point translator)
{
	centre.setPoint(centre.getX() + translator.getX(), centre.getY() + translator.getY());
}

bool Circle::isPointIn(Point p)const
{
	float l = sqrt(pow((centre.getX() - p.getX()), 2) + pow((centre.getY() - p.getY()), 2));
	if (l < radius)
		return true;
	return false;
}

char* Circle::isInstanceOf()const
{
	char* r = "Circle";
	return r;
}

Point Circle::getCentre()const
{
	return centre;
}

float Circle::getRadius()const
{
	return radius;
}



bool Circle::InRectangle(float rx, float ry, float fwidth, float fhight)const
{	//the colour is not needed
	Rectangle r(rx, ry, fwidth, fhight, "red");
	Point upCentre(centre.getX(), centre.getY() + radius);
	Point downCentre(centre.getX(), centre.getY() - radius);
	Point leftCentre(centre.getX() - radius, centre.getY());
	Point rightCentre(centre.getX() + radius, centre.getY());

	bool upCentreIn = r.isPointIn(upCentre);
	bool downCentreIn = r.isPointIn(downCentre);
	bool leftCentreIn = r.isPointIn(leftCentre);
	bool rightCentreIn = r.isPointIn(rightCentre);

	bool centreIn = r.isPointIn(centre);

	if (upCentreIn == true && downCentreIn == true && leftCentreIn == true && rightCentreIn == true && centreIn == true)
	{
		return true;
	}
	return false;
}

bool Circle::InCircle(float cx, float cy, float cRadius)const
{
	//the colour is not needed
	Circle c(cx, cy, cRadius, "red");
	Point upCentre(centre.getX(), centre.getY() + radius);
	Point downCentre(centre.getX(), centre.getY() - radius);
	Point leftCentre(centre.getX() - radius, centre.getY());
	Point rightCentre(centre.getX() + radius, centre.getY());

	bool upCentreIn = c.isPointIn(upCentre);
	bool downCentreIn = c.isPointIn(downCentre);
	bool leftCentreIn = c.isPointIn(leftCentre);
	bool rightCentreIn = c.isPointIn(rightCentre);

	bool centreIn = c.isPointIn(centre);

	if (upCentreIn == true && downCentreIn == true && leftCentreIn == true && rightCentreIn == true && centreIn == true)
	{
		return true;
	}
	return false;
}

Circle::~Circle()
{
}

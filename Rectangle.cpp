#include "Rectangle.h"



Rectangle::Rectangle() : downLeft(0, 0), downRight(0, 0), upLeft(0, 0), upRight(0, 0), width(0), height(0), fill(NULL)
{

}
Rectangle::Rectangle(float x, float y, float newWidth, float newHeight, char* newFill)
{
	create(x, y, newWidth, newHeight, newFill);
}

Rectangle::Rectangle(const Rectangle& other)
{
	copy(other);
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this != &other)
	{	
		delete[] fill;
		copy(other);
	}
	return *this;
}

void Rectangle::copy(const Rectangle& other)
{
	downLeft = other.downLeft;
	downRight = other.downRight;
	upLeft = other.upLeft;
	upRight = other.upRight;
	width = other.width;
	height = other.height;
	fill = new char[strlen(other.fill) + 1];
	strcpy_s(fill, strlen(other.fill) + 1, other.fill);

}

void Rectangle::create(float x, float y, float newWidth, float newHeight, char* newFill)
{
	downLeft.setPoint(x, y);
	width = newWidth;
	height = newHeight;

	delete[] fill;
	fill = new char[strlen(newFill) + 1];
	strcpy_s(fill, strlen(newFill) + 1, newFill);

	downRight.setPoint(x + width, y);
	upLeft.setPoint(x, y + height);
	upRight.setPoint(x + width, y + height);
}

void Rectangle::printShape()const
{
	cout << "rect " << downLeft.getX() << " " << downLeft.getY() << " " << width << " " << height << " " << fill << endl;

}

char* Rectangle::saveShape()const
{
	char* s = new char[256]; 
	sprintf_s(s, 256, "  <rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" />\n", downLeft.getX(), downLeft.getY(), width, height, fill);
	return s;
	
	
}

void Rectangle::translate(Point translator)
{
	downLeft.setPoint(downLeft.getX() + translator.getX(), downLeft.getY() + translator.getY());
	downRight.setPoint(downRight.getX() + translator.getX(), downRight.getY() + translator.getY());
	upLeft.setPoint(upLeft.getX() + translator.getX(), upLeft.getY() + translator.getY());
	upRight.setPoint(upRight.getX() + translator.getX(), upRight.getY() + translator.getY());


}
bool Rectangle::isPointIn(Point p)const
{
	//find length of the edge with points upLeft and upRight
	float a1 = sqrt(pow((upLeft.getX() - upRight.getX()), 2) + pow((upLeft.getY() - upRight.getY()), 2));
	//find length of the edge with points downRight and UpRight
	float a2 = sqrt(pow((upRight.getX() - downRight.getX()), 2) + pow((upRight.getY() - downRight.getY()), 2));
	//find length of the edge with points downleft and downRight
	float a3 = sqrt(pow((downRight.getX() - downLeft.getX()), 2) + pow((downRight.getY() - downLeft.getY()), 2));
	//find length of the edge with points downleft and upLeft
	float a4 = sqrt(pow((downLeft.getX() - upLeft.getX()), 2) + pow((downLeft.getY() - upLeft.getY()), 2));

	//find length of the line with points upLeft and p
	float b1 = sqrt(pow((upLeft.getX() - p.getX()), 2) + pow((upLeft.getY() - p.getY()), 2));
	//find length of the line with points upRight and p
	float b2 = sqrt(pow((upRight.getX() - p.getX()), 2) + pow((upRight.getY() - p.getY()), 2));
	//find length of the line with points downRight and p
	float b3 = sqrt(pow((downRight.getX() - p.getX()), 2) + pow((downRight.getY() - p.getY()), 2));
	//find length of the line with points downLeft and p
	float b4 = sqrt(pow((downLeft.getX() - p.getX()), 2) + pow((downLeft.getY() - p.getY()), 2));

	//find the area of the rectangle
	float A = a1 * a2; // a2*a3 or a3*a4 or a4*a1

	//find semi perimeter of triangle with points upLeft, upRigth and p
	float p1 = (a1 + b1 + b2) / 2;
	//find the area of triangle with points upLeft, upRight and p with Heron's formula
	float A1 = sqrt(p1*(p1 - a1)*(p1 - b1)*(p1 - b2));

	//find semi perimeter of triangle with points  upRigth, downRight and p
	float p2 = (a2 + b2 + b3) / 2;
	//find the area of triangle with points upRight, downRight and p with Heron's formula
	float A2 = sqrt(p2*(p2 - a2)*(p2 - b2)*(p2 - b3));

	//find semi perimeter of triangle with points  downLeft, downRight and p
	float p3 = (a3 + b3 + b4) / 2;
	//find the area of triangle with points downLeft, downRight and p with Heron's formula
	float A3 = sqrt(p3*(p3 - a3)*(p3 - b3)*(p3 - b4));

	//find semi perimeter of triangle with points  downLeft, upLeft and p
	float p4 = (a4 + b4 + b1) / 2;
	//find the area of triangle with points  downLeft, upLeft and p with Heron's formula
	float A4 = sqrt(p4*(p4 - a4)*(p4 - b4)*(p4 - b1));


	if (A >= A1 + A2 + A3 + A4)
	{
		return true;
	}
	return false;


}

char* Rectangle::isInstanceOf()const
{
	char* r = "Rectangle";
	return r;
}

Point Rectangle::getDownLeft()const
{
	return downLeft;
}
Point Rectangle::getDownRight()const
{
	return downRight;
}
Point Rectangle::getUpLeft()const
{
	return upLeft;
}
Point Rectangle::getUpRight()const
{
	return upRight;
}
float Rectangle::getWidth()const
{
	return width;
}
float Rectangle::getHeight()const
{
	return height;
}

bool Rectangle::InRectangle(float rx, float ry, float rWidth, float rHeight)const
{
	//the colour is not needed
	Rectangle r(rx, ry, rWidth, rHeight, "red");
	bool downLeftIn = r.isPointIn(downLeft);
	bool downRightIn = r.isPointIn(downRight);
	bool upLeftIn = r.isPointIn(upLeft);
	bool upRightIn = r.isPointIn(upRight);
	if (downLeftIn == true && downRightIn == true && upLeftIn == true && upRightIn == true)
	{
		return true;
	}
	return false;
}
bool Rectangle::InCircle(float cx, float cy, float cRadius)const
{
	//the colour is not needed
	Circle c(cx, cy, cRadius, "red");
	bool downLeftIn = c.isPointIn(downLeft);
	bool downRightIn = c.isPointIn(downRight);
	bool upLeftIn = c.isPointIn(upLeft);
	bool upRightIn = c.isPointIn(upRight);
	if (downLeftIn == true && downRightIn == true && upLeftIn == true && upRightIn == true)
	{
		return true;
	}
	return false;
}

Rectangle::~Rectangle()
{
}

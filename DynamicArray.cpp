#include "DynamicArray.h"


DynamicArray::DynamicArray() : array(nullptr), size(0), cap(1)
{
	array = new Shape*[1];
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
	copy(other);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

void DynamicArray::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	size = 0;
	cap = 1;

}

void DynamicArray::copy(const DynamicArray& other)
{

	array = new Shape*[other.cap];
	for (size_t i = 0; i < other.size; i++)
	{
		array[i] = other.array[i];
	}
	size = other.size;
	cap = other.cap;

}

DynamicArray::~DynamicArray()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}

void DynamicArray::resize()
{
	size_t newCap;

	if (size >= cap)
	{
		newCap = size * 2;
	}
	else if (size * 2 < cap)
	{
		newCap = size * 2;
	}
	else
		return;

	Shape ** newArrey = new Shape*[newCap];
	for (size_t i = 0; i < size; i++)
	{
		newArrey[i] = array[i];
	}
	cap = newCap;
	array = newArrey;
}

void DynamicArray::addCircle(float x, float y, float radius, char* fill)
{
	array[size] = new Circle(x, y, radius, fill);
	size++;
	resize();
}


void DynamicArray::addLine(float x1, float y1, float x2, float y2, char* style)
{
	array[size] = new Line(x1, y1, x2, y2, style);
	size++;
	resize();
}



void DynamicArray::addRectangle(float x, float y, float width, float height, char* fill)
{
	array[size] = new Rectangle(x, y, width, height, fill);
	size++;
	resize();
}

void DynamicArray::take(size_t idx)
{
	if (idx < 0 || idx > size)
	{
		cout << "There is no figure number " << idx << endl;
		throw std::out_of_range("Invalid position");
	}
	cout << "Erased:";
	array[idx]->printShape();
	for (size_t i = idx; i < size - 1; i++)
	{
		array[i] = array[i + 1];
	}
	size--;
	resize();
}

void DynamicArray::translate(float vertical, float horizontal, size_t idx)
{
	if (idx < 0 || idx > size)
	{
		throw std::out_of_range("Invalid position");
	}
	//horizontal is x and vertical is y
	Point p(horizontal, vertical);
	array[idx]->translate(p);
}

void  DynamicArray::translate(float vertical, float horizontal)
{
	//horizontal is x and vertical is y
	Point p(horizontal, vertical);
	for (size_t i = 0; i < size; i++)
	{
		array[i]->translate(p);
	}
}

size_t DynamicArray::getSize()const
{
	return size;
}

size_t DynamicArray::getCap()const
{
	return cap;
}
void DynamicArray::printShapes()const
{

	for (size_t i = 0; i < size; i++)
	{
		cout << i + 1 << ". ";
		array[i]->printShape();
	}
	cout << endl;
}

Shape& DynamicArray::operator[](const size_t idx)const
{
	if (idx < 0 || idx > size)
	{
		throw std::out_of_range("Invalid position");
	}
	return *(array[idx]);
}




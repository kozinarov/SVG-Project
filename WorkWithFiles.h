#pragma once
#ifndef __WorkWithFiles_HEADER__
#define __WorkWithFiles_HEADER__
#include <fstream>
#include "DynamicArray.h"


void open(char* fname, DynamicArray& array)
{
	char* tmppart;

	ifstream file;
	file.open(fname);
	char sword[256];
	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> sword;
			if (strcmp(sword,"<svg>") == 0)
			{
				file >> sword;

				while (strcmp(sword,"</svg>") != 0)
				{

					char* spart;
					char* next_token = NULL;
					char* t;
					t = strtok_s(sword, "<", &next_token);
					tmppart = new char[strlen(t) + 1];
					strcpy_s(tmppart, strlen(t) + 1, t);
					
					file >> sword;
					float x, y, width, height;
					float cx, cy, r;
					float x1, y1, x2, y2;
					char* fill;
					char* style;
					while (strcmp(sword,"/>") != 0)
					{
						char* tmpFront;
						next_token = NULL;
						tmpFront = strtok_s(sword, "=", &next_token);
						spart = strtok_s(NULL, "\"", &next_token);

						if (strcmp(tmppart,"rect") == 0)
						{

							if (strcmp(tmpFront, "x") == 0)
							{
								x = atof(spart);
							}
							if (strcmp(tmpFront, "y") == 0)
							{
								y = atof(spart);
							}
							if (strcmp(tmpFront, "width") == 0)
							{
								width = atof(spart);
							}
							if (strcmp(tmpFront, "height") == 0)
							{
								height = atof(spart);
							}
							if (strcmp(tmpFront, "fill") == 0)
							{
								
								fill = new char[strlen(spart) + 1];
								strcpy_s(fill, strlen(spart) + 1, spart);
							}
						}
						else if (strcmp(tmppart, "circle") == 0)
						{
							if (strcmp(tmpFront, "cx") == 0)
								cx = atof(spart);
							if (strcmp(tmpFront, "cy") == 0)
								cy = atof(spart);
							if (strcmp(tmpFront, "r") == 0)
								r = atof(spart);
							if (strcmp(tmpFront, "fill") == 0)
							{
								fill = new char[strlen(spart) + 1];
								strcpy_s(fill, strlen(spart) + 1, spart);
							}
						}
						else if (strcmp(tmppart, "line") == 0)
						{
							if (strcmp(tmpFront, "x1") == 0)
								x1 = atof(spart);
							if (strcmp(tmpFront, "y1") == 0)
								y1 = atof(spart);
							if (strcmp(tmpFront, "x2") == 0)
								x2 = atof(spart);
							if (strcmp(tmpFront, "y2") == 0)
								y2 = atof(spart);
							if (strcmp(tmpFront, "stile") == 0)
							{
								style = new char[strlen(spart) + 1];
								strcpy_s(style, strlen(spart) + 1, spart);
							}
						}
						
						file >> sword;

					}
					if (strcmp(tmppart, "rect") == 0)
						array.addRectangle(x, y, width, height, fill);
					if (strcmp(tmppart, "circle") == 0)
						array.addCircle(cx, cy, r, fill);
					if (strcmp(tmppart, "line") == 0)
						array.addLine(x1, y1, x2, y2, style);


					file >> sword;
					
				}
				
			}
			
		}
	}

	file.close();

}

void save(char* originalName, DynamicArray& array)
{
	ofstream file;
	file.open(originalName);
	if (file.is_open())
	{
		char s[512] = "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg>\n";
		file << s;
	
		for (size_t i = 0; i < array.getSize(); i++)
		{
			file << array[i].saveShape();
		}
		file << "</svg>\n";
	}
	file.close();
}


void save_As(char* fname, DynamicArray& array)
{
	ofstream file;
	file.open(fname);
	if (file.is_open())
	{
		char s[512] = "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg>\n";
		file << s;

		for (size_t i = 0; i < array.getSize(); i++)
		{
			file << array[i].saveShape();
		}
		file << "</svg>\n";
	}
	file.close();
}






#endif //__WorkWithFiles_HEADER__
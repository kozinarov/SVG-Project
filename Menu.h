#pragma once
#ifndef __HEADER_Menu__
#define __HEADER_Menu__

#include "WorkWithFiles.h"
#include <cstring>

void menu()
{	
	DynamicArray array;
	char* fname;
	char line[256];
	char* tmpLine;
	char* part;
	cin.getline(line, 256);

	const char *delim = " ";
	char* next_token = NULL;

	part = strtok_s(line, delim, &next_token);
	part = strtok_s(NULL, delim, &next_token);
	while (part != NULL && strcmp(part,"exit") != 0)
	{
		if (strcmp(part, "open") == 0)
		{
			part = strtok_s(NULL, delim, &next_token);

			open(part, array);
			
			fname = new char[strlen(part) + 1];
			strcpy_s(fname, strlen(part) + 1, part);
			cout << "Successsfully opened figures.svg" << endl;
		}
		if (strcmp(part, "close") == 0)
		{
			cout << "file closed" << endl;
		}

		if (strcmp(part, "save") == 0)
		{
			save(fname, array);
			cout << "Successsfully saved " << fname << endl;
		}

		if (strcmp(part, "saveas") == 0)
		{
			part = strtok_s(NULL, delim, &next_token);

			save(part, array);
			fname = part;
			cout << "Successsfully saved " << part << endl;
		}

		if (strcmp(part, "print") == 0)
		{
			array.printShapes();
		}

		if (strcmp(part, "create") == 0)
		{
			part = strtok_s(NULL, delim, &next_token);
			if (strcmp(part, "rectangle") == 0)
			{
				float x, y, width, height;
				char* fill;

				part = strtok_s(NULL, delim, &next_token);
				x = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				y = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				width = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				height = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				fill = part;

				array.addRectangle(x, y, width, height, fill);
				cout << "Successfully created rectangle" << endl;

			}

			if (strcmp(part, "line") == 0)
			{
				float x1, y1, x2, y2;
				char* style;


				part = strtok_s(NULL, delim, &next_token);
				x1 = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				y1 = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				x2 = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				y2 = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				style = part;
				array.addLine(x1, y1, x2, y2, style);
				cout << "Successfully created line" << endl;

			}

			if (strcmp(part, "circle") == 0)
			{
				float x, y, radius;
				char* fill;
				part = strtok_s(NULL, delim, &next_token);
				x = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				y = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				radius = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				fill = part;

				array.addCircle(x, y, radius, fill);
				cout << "Successfully created Circle" << endl;

			}

		}

		if (strcmp(part, "erase") == 0)
		{
			part = strtok_s(NULL, delim, &next_token);
			size_t idx = atoi(part);
			array.take(idx);
		}

		if (strcmp(part, "translate") == 0)
		{
			size_t begWordPart;

			part = strtok_s(NULL, delim, &next_token);
			char* right;
			part = strtok_s(part, "=", &right);
			float vertical = atof(right);

			part = strtok_s(NULL, delim, &next_token);
			part = strtok_s(part, "=", &right);
			float horizontal = atof(right);

			part = strtok_s(NULL, delim, &next_token);

			if (part == NULL)
			{
				array.translate(vertical, horizontal);
				cout << "Translated all figures" << endl;
			}
			else
			{
				size_t idx = atoi(part);
				array.translate(vertical, horizontal, idx);
				cout << "Translated shape on index " << idx << endl;
			}

		}

		if (strcmp(part,"within") == 0)
		{
			part = strtok_s(NULL, delim, &next_token);
			
			if (strcmp(part,"rectangle") == 0)
			{
				float x, y, width, height;

				part = strtok_s(NULL, delim, &next_token);
				x = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				y = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				width = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				height = atof(part);

				

				bool in = false;

				for (size_t i = 0; i < array.getSize(); i++)
				{
					if (array[i].InRectangle(x, y, width, height) == true)
					{
						cout << i << ".";
						array[i].printShape();
						in = true;
					}
				}
				if (in == false)
					cout << "No figures are located within the shape" << endl;


			}
			if (strcmp(part, "circle") == 0)
			{
				float x, y, radius;
				part = strtok_s(NULL, delim, &next_token);
				x = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				y = atof(part);

				part = strtok_s(NULL, delim, &next_token);
				radius = atof(part);

				

				bool in = false;
				for (size_t i = 0; i < array.getSize(); i++)
				{
					if (array[i].InCircle(x, y, radius) == true)
					{
						cout << i << ".";
						array[i].printShape();
						in = true;
					}
				}
				if (in == false)
					cout << "No figures are located within the shape" << endl;

			}
		}


		cin.getline(line, 256);
		part = strtok_s(line, delim, &next_token);
		part = strtok_s(NULL, delim, &next_token);
	}
}

#endif //__HEADER_Menu__
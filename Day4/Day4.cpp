#include "Day4.h"
#include <fstream>
#include <iostream>

using namespace std;

void Day4(bool testing)
{
	string filePath = testing ? "Day4/testValues.txt" : "Day4/Values.txt";

	cout << "Day 4: Part 1 -> " << Day4_Part1(filePath) << "  |  Part 2 -> " << Day4_Part2(filePath) << endl;
}

int Day4_Part1(std::string path)
{
	int value = 0;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		int x1, x2, y1, y2;
		while (!file.eof())
		{
			file >> x1;
			file.ignore(1);
			file >> x2;
			file.ignore(1);
			file >> y1;
			file.ignore(1);
			file >> y2;

			bool intersct = (x1 >= y1 && x2 <= y2) || (y1 >= x1 && y2 <= x2);
			if (intersct)
				value++;
		}
		file.close();
	}

	return value;
}

int Day4_Part2(std::string path)
{
	int value = 0;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		int x1, x2, y1, y2;
		while (!file.eof())
		{
			file >> x1;
			file.ignore(1);
			file >> x2;
			file.ignore(1);
			file >> y1;
			file.ignore(1);
			file >> y2;

			bool intersct = (x1 <= y1 && y1 <= x2) || (y1 <= x1 && x1 <= y2);
			if (intersct)
				value++;
		}
		file.close();
	}

	return value;
}

#include "Day4.h"
#include <fstream>
#include <iostream>

using namespace std;

void DayXXX(bool testing)
{
	string filePath = testing ? "DayXXX/testValues.txt" : "DayXXX/Values.txt";

	cout << "Day XXX: Part 1 -> " << DayXXX_Part1(filePath) << "  |  Part 2 -> " << DayXXX_Part2(filePath) << endl;
}

int DayXXX_Part1(std::string path)
{
	int value = 0;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		while (!file.eof())
		{
			
		}
		file.close();
	}

	return value;
}

int DayXXX_Part2(std::string path)
{
	int value = 0;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		while (!file.eof())
		{
			
		}
		file.close();
	}

	return value;
}

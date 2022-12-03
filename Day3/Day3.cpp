#include "Day3.h"
#include <fstream>
#include <iostream>

using namespace std;

void Day3(bool testing)
{
	string filePath = testing ? "Day3/testValues.txt" : "Day3/Values.txt";

	cout << "Day 3: Part 1 -> " << Day3_Part1(filePath) << "  |  Part 2 -> " << Day3_Part2(filePath) << endl;
}

int Day3_Part1(std::string path)
{
	int sum = 0;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		string line, second;
		while (!file.eof())
		{
			file >> line;
			second = line.substr(line.size() / 2, line.size()/2);
			line = line.substr(0, line.size()/2);
			bool found = false;
			for (int i=0; i < line.size() && !found; i++)
			{
				char ch = line[i];
				for (auto sec : second)
				{
					if (sec == ch)
					{
						found = true;
						if (ch - 'a' < 0) // Upper Case
						{
							sum += ch - 'A' + 27;
						}
						else
						{
							sum += ch - 'a' + 1;
						}
						break;
					}
				}
			}
		}
		
		file.close();
	}

	return sum;
}

int Day3_Part2(std::string path)
{
	int sum = 0;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		string first, second, third;
		while (!file.eof())
		{
			file >> first;
			file >> second;
			file >> third;
			bool found = false;

			//Unoptimized approach?
			for (int i = 0; i < first.size() && !found; i++)
			{
				char st = first[i];
				for (int j = 0; j < second.size() && !found; j++)
				{
					char nd = second[j];
					for (char rd : third)
					{
						if (st == nd && nd == rd)
						{
							found = true;
							if (rd - 'a' < 0) // Upper Case
								sum += rd - 'A' + 27;
							else
								sum += rd - 'a' + 1;
							break;
						}
					}
				}
			}
			
		}

		file.close();
	}
	return sum;
}

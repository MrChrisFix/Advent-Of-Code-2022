#include "Day6.h"
#include <fstream>
#include <iostream>
#include <deque>

using namespace std;

void Day6(bool testing)
{
	string filePath = testing ? "Day6/testValues.txt" : "Day6/Values.txt";

	cout << "Day 6: Part 1 -> " << Day6_Part1(filePath) << "  |  Part 2 -> " << Day6_Part2(filePath) << endl;
}

int Day6_Part1(std::string path)
{
	int value = 0;

	deque<char> FIFO;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		char in;
		while (!file.eof())
		{
			file >> in;
			value++;
			FIFO.push_back(in);
			if (FIFO.size() == 4)
			{
				bool original = true;
				for(int i=0; i< 4 && original; i++)
					for (int j = 0; j < 4 && original; j++)
					{
						if (i == j) continue;
						if (FIFO[i] == FIFO[j])
							original = false;

					}
				if (original)
					break;

				FIFO.pop_front();
			}
		}
		file.close();
	}

	return value;
}

int Day6_Part2(std::string path)
{
	int value = 0;

	deque<char> FIFO;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		char in;
		while (!file.eof())
		{
			file >> in;
			value++;
			FIFO.push_back(in);
			if (FIFO.size() == 14)
			{
				bool original = true;
				for (int i = 0; i < 14 && original; i++)
					for (int j = 0; j < 14 && original; j++)
					{
						if (i == j) continue;
						if (FIFO[i] == FIFO[j])
							original = false;

					}
				if (original)
					break;

				FIFO.pop_front();
			}
		}
		file.close();
	}

	return value;
}

#include "Day10.h"
#include <fstream>
#include <iostream>

using namespace std;

void Day10(bool testing)
{
	string filePath = testing ? "Day10/testValues.txt" : "Day10/Values.txt";

	cout << "Day 10: Part 1 -> " << Day10_Part1(filePath) << "  |  Part 2 -> " << Day10_Part2(filePath) << endl;
}

int Day10_Part1(std::string path)
{
	int value = 0;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		string com;
		int num;
		int tick = 1, X = 1;
		int nextBig = 20;
		while (!file.eof())
		{
			file >> com;
			if (com == "addx")
			{
				file >> num;
				if (tick == nextBig || tick + 1 == nextBig)
				{
					value += X * nextBig;
					nextBig += 40;
					if (nextBig > 220)
						break;
				}
				X += num;
				tick += 2;
			}
			else
			{
				if (tick == nextBig)
				{
					value += X * nextBig;
					nextBig += 40;
					if (nextBig > 220)
						break;
				}
				tick++;
			}
		}
		file.close();
	}

	return value;
}

int Day10_Part2(std::string path)
{
	int value = -1;
	char crt[6][40]{};

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		string com;
		int num;
		int tick = 1, X = 1;
		int row = 0, col = 0;
		while (!file.eof())
		{
			file >> com;
			if (com == "addx")
			{
				file >> num;
				if (X - 1 == col || X == col || X + 1 == col)
				{
					crt[row][col++] = '#';
				}
				else
				{
					crt[row][col++] = '.';
				}
				tick++;
				if (tick == 41)
				{
					tick = 1;
					row++;
					col = 0;
				}

				if (X - 1 == col || X == col || X + 1 == col)
				{
					crt[row][col++] = '#';
				}
				else
				{
					crt[row][col++] = '.';
				}
				tick ++;

				if (tick == 41)
				{
					tick = 1;
					row++;
					col = 0;
				}

				X += num;
			}
			else
			{
				if (X - 1 == col || X == col || X + 1 == col)
				{
					crt[row][col++] = '#';
				}
				else
				{
					crt[row][col++] = '.';
				}
				tick++;
				if (tick == 41)
				{
					tick = 1;
					row++;
					col = 0;
				}
			}
		}
		file.close();
	}

	for(int i=0; i<6; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			cout << crt[i][j];
		}
		cout << endl;
	}

	return value;
}

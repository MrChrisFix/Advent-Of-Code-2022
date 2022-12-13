#include "Day8.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void Day8(bool testing)
{
	string filePath = testing ? "Day8/testValues.txt" : "Day8/Values.txt";

	cout << "Day 8: Part 1 -> " << Day8_Part1(filePath) << "  |  Part 2 -> " << Day8_Part2(filePath) << endl;
}

int Day8_Part1(std::string path)
{
	int value = 0;

	vector<vector<short>> arr;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		string line;

		while (!file.eof())
		{
			file >> line;
			vector<short> numLine;
			for (auto ch : line)
			{
				numLine.push_back(ch - '0');
			}
			arr.push_back(numLine);
		}
		file.close();
	}
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			if ((i == 0) || (j == 0) || (i == arr.size() - 1) || (j == arr[i].size() - 1)) //sides
			{
				value++;
				continue;
			}
			if (arr[i][j] == 0)
				continue; //Never will be seen

			bool right = true, top= true, bottom = true, left = true;
			for (int k = j+1; k < arr[i].size(); k++)
			{
				if (arr[i][k] >= arr[i][j])
				{
					right = false;
					break;
				}
			}
			for (int k = j - 1; k >=0; k--)
			{
				if (arr[i][k] >= arr[i][j])
				{
					left = false;
					break;
				}
			}
			for (int k = i + 1; k < arr.size(); k++)
			{
				if (arr[k][j] >= arr[i][j])
				{
					bottom = false;
					break;
				}
			}
			for (int k = i - 1; k >=0; k--)
			{
				if (arr[k][j] >= arr[i][j])
				{
					top = false;
					break;
				}
			}

			if (right || left || bottom || top)
			{
				value++;
			}

		}
	}

	return value;
}

int Day8_Part2(std::string path)
{
	int value = 0;

	vector<vector<short>> arr;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		string line;

		while (!file.eof())
		{
			file >> line;
			vector<short> numLine;
			for (auto ch : line)
			{
				numLine.push_back(ch - '0');
			}
			arr.push_back(numLine);
		}
		file.close();
	}
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			if ((i == 0) || (j == 0) || (i == arr.size() - 1) || (j == arr[i].size() - 1)) //sides will be zero anyway
			{
				continue;
			}

			short right = 0, top = 0, bottom = 0, left = 0;
			for (int k = j + 1; k < arr[i].size(); k++)
			{
				right++;
				if (arr[i][k] >= arr[i][j])
				{
					break;
				}
			}
			for (int k = j - 1; k >= 0; k--)
			{
				left++;
				if (arr[i][k] >= arr[i][j])
				{
					break;
				}
			}
			for (int k = i + 1; k < arr.size(); k++)
			{
				bottom++;
				if (arr[k][j] >= arr[i][j])
				{
					break;
				}
			}
			for (int k = i - 1; k >= 0; k--)
			{
				top++;
				if (arr[k][j] >= arr[i][j])
				{
					break;
				}
			}
			int score = right * left * top * bottom;
			if (score > value)
				value = score;
		}
	}

	return value;
}

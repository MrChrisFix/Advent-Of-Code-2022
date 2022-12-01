#include "Day1.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int Day1_Part1()
{
	ifstream file;

	file.open("Day1/Values.txt");
	if (file.is_open())
	{
		string num;
		int max = 0;
		int current = 0;
		while (!file.eof())
		{
			getline(file, num);
			if (!num.empty())
			{
				current += stoi(num);
			}
			else
			{
				if (current > max)
					max = current;
				current = 0;
			}
		}

		file.close();
		return max;
	}

	return 0;
}

int Day1_Part2()
{
	ifstream file;

	file.open("Day1/Values.txt");
	if (file.is_open())
	{
		string num;
		vector<int> best(4);
		int current = 0;
		while (!file.eof())
		{
			getline(file, num);
			if (!num.empty() )
			{
				current += stoi(num);
			}
			else
			{
				if (current > best[2])
				{
					best[3] = current;
					sort(best.begin(), best.end(), std::greater<int>());
				}
				current = 0;
			}
		}
		//Last line
		if (current > best[2])
		{
			best[3] = current;
			sort(best.begin(), best.end(), std::greater<int>());
		}

		file.close();
		return best[0] + best[1] + best[2];
	}

	return 0;
}

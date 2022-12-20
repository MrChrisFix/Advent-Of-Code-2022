#include "Day9.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void Day9(bool testing)
{
	string filePath = testing ? "Day9/testValues.txt" : "Day9/Values.txt";

	cout << "Day 9: Part 1 -> " << Day9_Part1(filePath) << "  |  Part 2 -> " << Day9_Part2(filePath) << endl;
}

int Day9_Part1(std::string path)
{
	int value = 0;

	vector<vector<bool>> bmap(600, vector<bool>(600, false));
	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		int Hx = 300, Hy = 300, Tx = 300, Ty = 300; //start positions
		bmap[Tx][Ty] = true;

		char dir;
		int steps;
		int prevX = Hx, prevY = Hy;
		while (!file.eof())
		{
			file >> dir >> steps;

			for (int i = 0; i < steps; i++)
			{
				prevY = Hy;
				prevX = Hx;
				if (dir == 'U')			Hy++;
				else if (dir == 'D')	Hy--;
				else if (dir == 'R')	Hx++;
				else if (dir == 'L')	Hx--;

				double distance = sqrt(pow(Hx - Tx, 2) + pow(Hy - Ty, 2));

				if (distance > 1.5)
				{
					Ty = prevY;
					Tx = prevX;
					bmap[Tx][Ty] = true;
				}
			}
		}
		file.close();
	}

	for (auto& vec : bmap)
	{
		for (bool b : vec)
		{
			if (b) value++;
		}
	}

	return value;
}

int Day9_Part2(std::string path)
{
	int value = 0;

	const int size = 60;
	const int half = 30;

	vector<vector<bool>> bmap(size, vector<bool>(size, false));
	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		int X[10]{ half,half,half,half,half,half,half,half,half,half }, Y[10]{ half,half,half,half,half,half,half,half,half,half }; //Head and rope. head is [0]
		bmap[X[9]][Y[9]] = true;
		char dir;
		int steps;
		int prevX[10], prevY[10];
		char prevDir = '.';
		while (!file.eof())
		{
			file >> dir >> steps;

			for (int i = 0; i < steps; i++)
			{
				prevX[0] = X[0];
				prevY[0] = Y[0];

				if (dir == 'U')			
					Y[0]++;
				else if (dir == 'D')	Y[0]--;
				else if (dir == 'R')	X[0]++;
				else if (dir == 'L')	X[0]--;

				bool corner = (dir == 'U' || dir == 'D') && (prevDir == 'R' || prevDir == 'L') || (dir == 'R' || dir == 'L') && (prevDir == 'U' || prevDir == 'D');

				for (int j = 1; j < 10; j++)
				{
					double distance = sqrt(pow(X[j-1] - X[j], 2) + pow(Y[j-1] - Y[j], 2));

					if (distance > 1.5)
					{
						if (Y[j - 1] - Y[j] >= 2) 
						{
							Y[j] = Y[j - 1] - 1;
							X[j] = X[j - 1];
						}
						else if (Y[j - 1] - Y[j] <= -2) 
						{
							Y[j] = Y[j - 1] + 1;
							X[j] = X[j - 1];
						}
						else if (X[j - 1] - X[j] >= 2) 
						{
							X[j] = X[j - 1] - 1;
							Y[j] = Y[j - 1];
						}
						else if (X[j - 1] - X[j] <= -2) 
						{
							X[j] = X[j - 1] + 1;
							Y[j] = Y[j - 1];
						}


						/*prevX[j] = X[j];
						prevY[j] = Y[j];*/

						/*if (corner)
						{
							if (Y[j - 1] - Y[j] >= 2) prevY[j]++;
							else if (Y[j - 1] - Y[j] <= -2) prevY[j]--;
							else if (X[j - 1] - X[j] >= 2) prevX[j]++;
							else if (X[j - 1] - X[j] <= -2) prevX[j]++;
						}*/

						/*X[j] = prevX[j - 1];
						Y[j] = prevY[j - 1];*/

						if(j == 9)
							bmap[X[j]][Y[j]] = true;
					}
				}	
			}
			prevDir = dir;
		}
		file.close();
	}
	int i=0, j=0;
	for (auto& vec : bmap)
	{
		i++;
		j = 0;
		for (bool b : vec)
		{
			j++;
			if (b) value++;
			if (i == half && j == half) cout << 's';
			else
			{
				if (b) cout << '#';
				else cout << '.';
			}
		}
		cout << endl;
	}

	return value;
	//2705 too low
}

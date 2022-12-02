#include "Day2.h"
#include <fstream>
#include <iostream>

using namespace std;

void Day2(bool testing)
{
	string filePath = testing ? "Day2/testValues.txt" : "Day2/Values.txt";

	cout << "Day 2: Part 2 -> " << Day2_Part1(filePath) << "  |  Part 2 -> " << Day2_Part2(filePath) << endl;
}

int Day2_Part1(std::string path)
{
	int points = 0;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		char opponent, player;
		while (!file.eof())
		{
			file >> opponent;
			file >> player;
			opponent += -'A' + 1; // 1 - Rock, 2 - Paper, 3 - Scissors
			player += -'X' + 1;
			if (player < 0 || opponent < 0) break;

			if (opponent == player) //Draw
			{
				points += 3 + player;
			}
			else if (player + 1 == opponent || opponent ==  player -2)
			{
				//Lost
				points += player;
			}
			else //Won
				points += player + 6;
		}
		file.close();
	}

	return points;
}

int Day2_Part2(std::string path)
{
	int points = 0;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		char opponent, result;
		while (!file.eof())
		{
			file >> opponent;
			file >> result;
			opponent += -'A' + 1; // 1 - Rock, 2 - Paper, 3 - Scissors
			result += -'X' + 1; // 1 - Lost, 2- Draw, 3 - Win
			if (result < 0 || opponent < 0) break;

			if (result == 2) //Draw
				points += opponent + 3;
			else if (result == 1) //Loose
			{
				points += opponent - 1 == 0 ? 3 : opponent - 1;
			}
			else //Win
			{
				points += 6 + (opponent + 1 == 4 ? 1 : opponent + 1);
			}
		}
		file.close();
	}

	return points;
}

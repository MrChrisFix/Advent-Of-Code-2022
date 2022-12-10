#include "Day5.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<char> decodeDockers(string row)
{
	vector<char> charRow;

	for (int i = 1; i < row.size(); i += 4)
	{
		if (row[i] <= 'Z' && row[i] >= 'A')
		{
			charRow.push_back(row[i]);
		}
		else charRow.push_back(' ');
	}

	return charRow;
}

vector<vector<char>> Transform(vector<vector<char>> Containers)
{
	vector<vector<char>> vec;
	for (int j = 0; j < Containers[0].size(); j++)
	{
		vector<char> signleStack;
		for (int i = Containers.size() - 1; i >= 0; i--)
		{
			char asdf = Containers[i][j];
			if(asdf != ' ')
				signleStack.push_back(asdf);
		}
		vec.push_back(signleStack);
	}

	return vec;
}

void moveContainersSlow(int amount, int from, int to, vector<vector<char>> &stack)
{
	for (int i = 0; i < amount; i++)
	{
		auto crate = stack[from].back();
		stack[from].pop_back();
		stack[to].push_back(crate);
	}
}

void moveContainersFast(int amount, int from, int to, vector<vector<char>>& stack)
{
	for (int i = amount-1; i >=0; i--)
	{
		auto crate = stack[from][stack[from].size() - i - 1];
		stack[to].push_back(crate);
	}

	for (int i = 0; i < amount; i++)
	{
		stack[from].pop_back();
	}
}


void Day5(bool testing)
{
	string filePath = testing ? "Day5/testValues.txt" : "Day5/Values.txt";

	cout << "Day 5: Part 1 -> " << Day5_Part1(filePath) << "  |  Part 2 -> " << Day5_Part2(filePath) << endl;
}

string Day5_Part1(std::string path)
{
	vector<vector<char>> stacks;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		string line;

		//Containers
		getline(file, line);
		while (!file.eof() && line[1] != '1')
		{
			stacks.push_back(decodeDockers(line));
			getline(file, line);
		}

		getline(file, line); //empty line

		stacks = Transform(stacks);

		int amount, from, to;
		//Moves
		while (!file.eof())
		{
			file >> line >> amount >> line >> from >> line >> to; //move X from Y to Z
			moveContainersSlow(amount, --from, --to, stacks);
		}
		file.close();
	}

	string result;
	for (auto& stack : stacks)
		result.push_back(stack.back());

	return result;
}

string Day5_Part2(std::string path)
{
	vector<vector<char>> stacks;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		string line;

		//Containers
		getline(file, line);
		while (!file.eof() && line[1] != '1')
		{
			stacks.push_back(decodeDockers(line));
			getline(file, line);
		}

		getline(file, line); //empty line

		stacks = Transform(stacks);

		int amount, from, to;
		//Moves
		while (!file.eof())
		{
			file >> line >> amount >> line >> from >> line >> to; //move X from Y to Z
			moveContainersFast(amount, --from, --to, stacks);
		}
		file.close();
	}

	string result;
	for (auto& stack : stacks)
		result.push_back(stack.back());

	return result;
}

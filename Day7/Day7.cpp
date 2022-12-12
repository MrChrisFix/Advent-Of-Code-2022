#include "Day7.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Dir
{
	long size = 0;
	Dir* parent;
	map<string, Dir*> dirs;
	vector<pair<long, string>> files;

	~Dir() {
		for (auto& dir : dirs)
			delete dir.second;
	}

	long RecalculateDirSize()
	{
		if (this->dirs.size() != 0)
		{
			long newSize = 0;
			for (auto& dir : this->dirs)
			{
				newSize += dir.second->RecalculateDirSize();
			}
			this->size += newSize;
		}
		return this->size;
	}

	string print(int tabs)
	{
		string val = "";
		for (auto& dir : dirs)
		{
			for (int i = 0; i < tabs; i++) val += "\t";
			val += "-" + dir.first + "(dir)\n";
			val += dir.second->print(tabs+1);
		}
		for (auto& file : files)
		{
			for (int i = 0; i < tabs; i++) val += "\t";
			val += "-" + file.second + "(file, size=" + to_string(file.first) + ")\n";
		}
		return val;
	}

	void isSmall(long& totalSize)
	{
		if (this->size < 100000)
			totalSize += this->size;
		for (auto& dir : dirs)
		{
			dir.second->isSmall(totalSize);
		}
	}

	void passingSizes(vector<Dir*>& vec, long maxSize)
	{
		if (this->size >= maxSize) vec.push_back(this);
		for (auto& dir : dirs)
		{
			dir.second->passingSizes(vec, maxSize);
		}
	}
};


void Day7(bool testing)
{
	string filePath = testing ? "Day7/testValues.txt" : "Day7/Values.txt";

	cout << "Day 7: Part 1 -> " << Day7_Part1(filePath) << "  |  Part 2 -> " << Day7_Part2(filePath) << endl;
}

int Day7_Part1(std::string path)
{
	Dir* root = new Dir;
	root->parent = nullptr;
	Dir* current = root;

	map<string, Dir*> allDirs;
	allDirs["/"] = root;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		char sign;
		string str;
		while (!file.eof())
		{
			sign = file.peek();
			if (sign == '$')
			{
				file >> str >> str;
				if (str == "cd")
				{
					file >> str;
					if (str == "/")
					{
						current = root;
					}
					else if (str == "..")
					{
						current = current->parent;
					}
					else
					{
						current = current->dirs[str];
					}
				}
				else //ls
				{
					//ignore?
				}
			}
			else if (sign == 'd') //dir
			{
				file >> str >> str;
				Dir* newDir = new Dir;
				newDir->parent = current;
				current->dirs[str] = newDir;

				allDirs[str] = newDir;
			}
			else //file
			{
				long size;
				file >> size >> str;
				pair<long, string> newFile(size, str);
				current->files.push_back(newFile);
				current->size += size;
			}

			file.ignore(1); //newline
		}
		file.close();
	}

	root->RecalculateDirSize();

	long totalSize = 0;
	root->isSmall(totalSize);

	cout << root->print(0) << endl;

	delete root;

	return totalSize;
}

int Day7_Part2(std::string path)
{
	Dir* root = new Dir;
	root->parent = nullptr;
	Dir* current = root;

	map<string, Dir*> allDirs;
	allDirs["/"] = root;

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		char sign;
		string str;
		while (!file.eof())
		{
			sign = file.peek();
			if (sign == '$')
			{
				file >> str >> str;
				if (str == "cd")
				{
					file >> str;
					if (str == "/")
					{
						current = root;
					}
					else if (str == "..")
					{
						current = current->parent;
					}
					else
					{
						current = current->dirs[str];
					}
				}
				else //ls
				{
					//ignore?
				}
			}
			else if (sign == 'd') //dir
			{
				file >> str >> str;
				Dir* newDir = new Dir;
				newDir->parent = current;
				current->dirs[str] = newDir;

				allDirs[str] = newDir;
			}
			else //file
			{
				long size;
				file >> size >> str;
				pair<long, string> newFile(size, str);
				current->files.push_back(newFile);
				current->size += size;
			}

			file.ignore(1); //newline
		}
		file.close();
	}

	root->RecalculateDirSize();

	vector<Dir*> goodOnes;

	long missing = 30000000 - (70000000 - root->size);

	root->passingSizes(goodOnes, missing);
	long min = goodOnes[0]->size;
	for (auto dir : goodOnes)
	{
		if (dir->size < min) min = dir->size;
	}

	return min;
}

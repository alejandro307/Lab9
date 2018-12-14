//Alejandro Bermudez

// main.cpp
// 12-10-18

#include "stdafx.h"
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::map;

using namespace std;

vector<string> readFile()
{
	vector<string> wordList;
	string word;
	ifstream inBuf;
	inBuf.open("example.txt");
	if (inBuf.good())
	{
		while (inBuf >> word)
		{
			wordList.push_back(word);
		}
	}
	inBuf.close();
	return wordList;
}

void writeMap(map<string, int> wordMap)
{
	ofstream outBuf;
	std::map<string, int>::const_iterator iter = wordMap.begin();
	outBuf.open("output.txt");
	int count = 0;
	if (outBuf.good())
	{
		while (iter != wordMap.end())
		{
			count++;
			for (int i = 0; i < (*iter).second; i++)
			{
				outBuf << (*iter).first + " ";
			}
			iter++;
			if (count % 10 == 0)
			{
				outBuf << "\n";
			}
		}
	}
	outBuf.close();
}

int main()
{
	vector<string> wordList = readFile();
	map<string, int> storage;
	for (size_t i = 0; i < wordList.size(); i++)
	{
		++storage[wordList[i]];
	}
	writeMap(storage);
	return 0;
}
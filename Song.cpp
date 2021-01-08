#include <iostream>
#include <string>
#include "Song.h"
using namespace std;

Song::Song(string name, string line)
{
	songName = name;
	firstLine = line;
}

string Song::SongName()
{
	return songName;
}

void Song::PrintFirstLine()
{
	cout << firstLine << endl;
}

void Song::AddCount()
{
	count++;
}

string Song::FirstLine()
{
	return firstLine;
}

int Song::SongCount()
{
	return count;
}
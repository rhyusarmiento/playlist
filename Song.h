#ifndef SONG_H
#define SONG_H
using namespace std;

class Song
{
public:
	Song(string name, string line);
	string SongName();
	string FirstLine();
	int SongCount();
	void AddCount();
	void PrintFirstLine();

private:
	string songName;
	string firstLine;
	int count = 0;
};

#endif
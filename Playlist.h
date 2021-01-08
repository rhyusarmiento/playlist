#ifndef PLAYLIST_H
#define PLAYLIST_H
using namespace std;

#include "Song.h"

class Playlist
{
public:
	Playlist(string name);
	string PlaylistName();
	void AddSong(Song *newSong);
	void RemoveSong(int index);
	void RemoveSongString(string song);
	void PrintSongsName();
	void PrintSongsFirstLine();

private:
	string playlistName;
	vector<Song *> songList;
};

#endif
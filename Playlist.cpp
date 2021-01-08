#include <iostream>
#include <string>
#include <vector>
#include "Playlist.h"
#include "Song.h"
using namespace std;

Playlist::Playlist(string name)
{
	playlistName = name;
}

string Playlist::PlaylistName()
{
	return playlistName;
}

void Playlist::AddSong(Song *newSong)
{
	songList.push_back(newSong);
}

void Playlist::PrintSongsFirstLine()
{
	for (int i = 0; i < songList.size(); i++)
	{
		songList.at(i)->PrintFirstLine();
		songList.at(i)->AddCount();
	}
	cout << endl;
}

void Playlist::RemoveSong(int index)
{
	songList.erase(songList.begin() + index);
}

void Playlist::PrintSongsName()
{
	for (int i = 0; i < songList.size(); i++)
	{
		cout << "  " << i << ": " << songList.at(i)->SongName() << endl;
	}
}

void Playlist::RemoveSongString(string song)
{
	for (int i = 0; i < songList.size(); i++)
	{
		if (song == songList.at(i)->SongName())
		{
			songList.erase(songList.begin() + i);
		}
	}
}

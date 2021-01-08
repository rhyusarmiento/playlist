#include <iostream>
#include <string>
#include <vector>

#include "Song.h"
#include "Playlist.h"

using namespace std;

string GetUserString(const string &prompt);

void AddSongsMenuOption(vector<Song *> &listSongs);
void ListSongsMenuOption(vector<Song *> listSongs);
void AddPlaylistMenuOption(vector<Playlist> &playlists);
void AddSongToPlaylistMenuOption(vector<Playlist> &playlists, vector<Song *> listSongs);
void ListPlaylistsMenuOption(vector<Playlist> playlists);
void PlayPlaylistMenuOption(vector<Playlist> playlists);
void RemovePlaylistMenuOption(vector<Playlist> &playlists);
void RemoveSongFromPlaylistMenuOption(vector<Playlist> &playlists, vector<Song *> listSongs);
void RemoveSongFromLibraryMenuOption(vector<Playlist> &playlists, vector<Song *> &listSongs);
void OptionsMenuOption();
void QuitMenuOption();
void DeleteSongs(vector<Song *> &listSongs);

int main()
{
  cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl
       << endl;

  vector<Playlist> playlistList;
  vector<Song *> songs;

  string userMenuChoice = "none";
  bool continueMenuLoop = true;

  while (continueMenuLoop)
  {
    userMenuChoice = GetUserString("Enter your selection now: ");

    if (userMenuChoice == "add")
    {
      AddSongsMenuOption(songs);
    }
    else if (userMenuChoice == "list")
    {
      ListSongsMenuOption(songs);
    }
    else if (userMenuChoice == "addp")
    {
      AddPlaylistMenuOption(playlistList);
    }
    else if (userMenuChoice == "addsp")
    {
      AddSongToPlaylistMenuOption(playlistList, songs);
    }
    else if (userMenuChoice == "listp")
    {
      ListPlaylistsMenuOption(playlistList);
    }
    else if (userMenuChoice == "play")
    {
      PlayPlaylistMenuOption(playlistList);
    }
    else if (userMenuChoice == "remp")
    {
      RemovePlaylistMenuOption(playlistList);
    }
    else if (userMenuChoice == "remsp")
    {
      RemoveSongFromPlaylistMenuOption(playlistList, songs);
    }
    else if (userMenuChoice == "remsl")
    {
      RemoveSongFromLibraryMenuOption(playlistList, songs);
    }
    else if (userMenuChoice == "options")
    {
      OptionsMenuOption();
    }
    else if (userMenuChoice == "quit")
    {
      QuitMenuOption();
      continueMenuLoop = false;
      DeleteSongs(songs);
    }
    else
    {
      OptionsMenuOption();
    }
  }
  return 0;
}

string GetUserString(const string &prompt)
{
  string userAnswer = "none";

  cout << prompt;
  getline(cin, userAnswer);
  cout << endl;
  return userAnswer;
}

int GetUserInt(const string &prompt)
{
  int userAnswer = 0;

  cout << prompt;
  cin >> userAnswer;
  cin.ignore();
  cout << endl;
  return userAnswer;
}

void AddSongsMenuOption(vector<Song *> &listSongs)
{
  const string DONE_KEYWORD = "DONE";
  cout << "Enter songs' names and first lines"
       << " (type \"" << DONE_KEYWORD << "\" when done):" << endl;

  string songName = "none";
  string firstLine = "none";

  songName = GetUserString("Song Name: ");
  while (songName != DONE_KEYWORD)
  {
    firstLine = GetUserString("Song's first line: ");
    Song *song = new Song(songName, firstLine);
    listSongs.push_back(song);
    songName = GetUserString("Song Name: ");
  }
}

void ListSongsMenuOption(vector<Song *> listSongs)
{
  for (int i = 0; i < listSongs.size(); i++)
  {
    cout << listSongs.at(i)->SongName() << ": \"" << listSongs.at(i)->FirstLine() << "\", " << listSongs.at(i)->SongCount() << " play(s)." << endl;
  }
  cout << endl;
}

void AddPlaylistMenuOption(vector<Playlist> &playlists)
{
  string playlistName;
  playlistName = GetUserString("Playlist name: ");

  Playlist newPlaylist(playlistName);
  playlists.push_back(newPlaylist);
}

void AddSongToPlaylistMenuOption(vector<Playlist> &playlists, vector<Song *> listSongs)
{
  int selectPlaylist;
  int selectSong;

  ListPlaylistsMenuOption(playlists);
  selectPlaylist = GetUserInt("Pick a playlist index number: ");

  for (int i = 0; i < listSongs.size(); i++)
  {
    cout << "  " << i << ": " << listSongs.at(i)->SongName() << endl;
  }
  cout << endl;

  selectSong = GetUserInt("Pick a song index number: ");

  playlists.at(selectPlaylist).AddSong(listSongs.at(selectSong));
}

void ListPlaylistsMenuOption(vector<Playlist> playlists)
{
  for (int i = 0; i < playlists.size(); i++)
  {
    cout << "  " << i << ": " << playlists.at(i).PlaylistName() << endl;
  }
  cout << endl;
}

void PlayPlaylistMenuOption(vector<Playlist> playlists)
{
  int selectPlaylist;

  ListPlaylistsMenuOption(playlists);
  selectPlaylist = GetUserInt("Pick a playlist index number: ");

  cout << "Playing songs from playlist: " << playlists.at(selectPlaylist).PlaylistName() << endl;
  playlists.at(selectPlaylist).PrintSongsFirstLine();
}

void RemovePlaylistMenuOption(vector<Playlist> &playlists)
{
  int selectPlaylist;

  ListPlaylistsMenuOption(playlists);
  selectPlaylist = GetUserInt("Pick a playlist index number to remove: ");

  playlists.erase(playlists.begin() + selectPlaylist);
}

void RemoveSongFromPlaylistMenuOption(vector<Playlist> &playlists, vector<Song *> listSongs)
{
  int selectPlaylist;
  int selectSong;

  ListPlaylistsMenuOption(playlists);
  selectPlaylist = GetUserInt("Pick a playlist index number: ");

  playlists.at(selectPlaylist).PrintSongsName();
  cout << endl;
  selectSong = GetUserInt("Pick a song index number to remove: ");

  playlists.at(selectPlaylist).RemoveSong(selectSong);
}

void RemoveSongFromLibraryMenuOption(vector<Playlist> &playlists, vector<Song *> &listSongs)
{
  int selectSong;
  string stringSong;

  for (int i = 0; i < listSongs.size(); i++)
  {
    cout << "  " << i << ": " << listSongs.at(i)->SongName() << endl;
  }
  cout << endl;

  selectSong = GetUserInt("Pick a song index number to remove: ");
  stringSong = listSongs.at(selectSong)->SongName();

  for (int i = 0; i < playlists.size(); i++)
  {
    playlists.at(i).RemoveSongString(stringSong);
  }

  delete listSongs.at(selectSong);
  listSongs.erase(listSongs.begin() + selectSong);
}

void OptionsMenuOption()
{
  cout << "add      Adds a list of songs to the library" << endl;
  cout << "list     Lists all the songs in the library" << endl;
  cout << "addp     Adds a new playlist" << endl;
  cout << "addsp    Adds a song to a playlist" << endl;
  cout << "listp    Lists all the playlists" << endl;
  cout << "play     Plays a playlist" << endl;
  cout << "remp     Removes a playlist" << endl;
  cout << "remsp    Removes a song from a playlist" << endl;
  cout << "remsl    Removes a song from the library (and all playlists)" << endl;
  cout << "options  Prints this options menu" << endl;
  cout << "quit     Quits the program" << endl
       << endl;
}

void QuitMenuOption()
{
  cout << "Goodbye!" << endl;
}

void DeleteSongs(vector<Song *> &listSongs)
{
  for (int i = 0; i < listSongs.size(); i++)
  {
    delete listSongs.at(i);
  }
}
#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Song {
 private:
  int id;

 public:
  Song(int id) : id(id) {}
  int getId() const { return id; }
};

class CD {
 private:
  int id;
  vector<Song*> songs;

 public:
  CD(int id) : id(id), songs() {}
  void addSong(Song* s) { songs.push_back(s); }
  const vector<Song*>& getSongs() const { return songs; }
};

class User {};

class Playlist {
 private:
  queue<Song*> songs;

 public:
  Playlist() : songs() {}
  void add(Song* song) { songs.push(song); }
  Song* play() {
    if (songs.empty()) {
      return nullptr;
    }
    Song* song = songs.front();
    songs.pop();
    cout << "Playing Song ID: " << song->getId() << endl;
    return song;
  }
};

class CDPlayer {
 private:
  Playlist* playlist;

 public:
  CDPlayer(Playlist* p) : playlist(p) {}
  void addToPlaylist(Song* song) { playlist->add(song); }
  Song* play() { return playlist->play(); }
};

class Jukebox {
 private:
  CDPlayer* player;
  User* user;
  set<CD*> cdCollection;

 public:
  Jukebox() : player(nullptr), user(nullptr), cdCollection() {
    player = new CDPlayer(new Playlist());
  }
  ~Jukebox() { delete player; }

  Jukebox(const Jukebox&) = delete;
  Jukebox& operator=(const Jukebox&) = delete;

  void setUser(User* u) { user = u; }
  void addCD(CD* cd) { cdCollection.insert(cd); }
  bool selectSong(int songId) {
    for (auto&& cd : cdCollection) {
      for (auto&& song : cd->getSongs()) {
        if (song->getId() == songId) {
          player->addToPlaylist(song);
          return true;
        }
      }
    }
    return false;
  }
  void play() { player->play(); }
};

int main() {
  // 1. Setup Data
  Song* song1 = new Song(1);
  Song* song2 = new Song(2);

  CD* cd1 = new CD(1);
  cd1->addSong(song1);
  cd1->addSong(song2);

  // 2. Initialize System
  Jukebox jukebox;
  jukebox.addCD(cd1);

  // 3. User Interaction
  User* user = new User();
  jukebox.setUser(user);

  jukebox.selectSong(1);
  jukebox.selectSong(2);
  jukebox.selectSong(9);  // Invalid

  // 4. Playback
  std::cout << "\n--- Starting Playback ---\n";
  jukebox.play();  // Plays Song 1
  jukebox.play();  // Plays Song 2
  jukebox.play();  // Empty

  return 0;
}

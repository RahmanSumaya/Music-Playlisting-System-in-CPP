#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <map>

class song {
    public:
    string title, artist;

    song(string t, string a) {
        title = t;
        artist = a;
    }
};

class Playlist {
public:
vector<Song> songs;
void addSong(string name, string artist){
    songs.push_back(name, artist);
    cout<<"Song added: "<<name<<" "<<by<<artist<<endl;
}
void remove(string title){
    auto it = remove_if(songs.begin(), songs.end(), [&title](const Song& song) {
            return song.title == title;
        });

        if (it != songs.end()) {
            songs.erase(it, songs.end());
            cout << "Song removed: " << title << endl;
        } else {
            cout << "Song not found: " << title << endl;
        }
}
void displaysongs()
{
    if(songs.empty()) cout<<"Playlist is empty"<<endl;
    else {
        cout<<"song list "<<endl;
        for(auto& song:songs){
            cout<<song.title<<" by "<<song.artist<<endl;
        }
    }
}

    void searchSong(string kuja){
        bool found = false;
        for (auto& song : khuja) {
            if (song.title.find(khuja) != string::npos || song.artist.find(khuja) != string::npos) {
                cout << "Found: " << song.title << " by " << song.artist << khuja;
                found = true;
            }
        }

        if (!found) {
cout << "No songs found matching: " << khuja << "\n";
        }
    }
void PlaySong(string kuja){
        bool found = false;
        for (auto& song : khuja) {
            if (song.title.find(khuja) != string::npos || song.artist.find(khuja) != string::npos) {
                cout << "Playing " << song.title << " by " << song.artist << khuja;
                found = true;
            }
        }

        if (!found) {
cout << "No songs found matching: " << khuja << "\n";
        }
    }

void Shuffle(){
    srand(time(0));
    random_shuffle(songs.begin(),songs.end());
    cout<<"Playlist Shufflet"<<endl;
}
void savePlaylist(string filename){
    ofstream play_list_save(filename);
    if(!play_list_save){
        cout<<"Error"<<endl;
        return;
    }
    for(auto& song:songs){
        play_list_save<<song.title<<" "<<song.artist<<endl;
    }
cout<<"Playlist saved to"<<filename<<endl;
}
    
};

class PlaylistManager{
    map<string, Playlist> playlists;
  //  map<string, Playlsit> playlists;
  void createPlaylist(const string& name) {
  //  ofstream play_list;
        play_list.open("playlistdata.txt", ios::app);
        if (playlists.find(name) == playlists.end()) {
            playlists[name] = Playlist();
            cout << "Playlist created: " << name << endl;
          //  play_list<<name<<'\t';
        } else {
            cout << "Playlist already exists: " << name << endl;
        }


    }

  void deletePlaylist(const std::string& name) {

        if (playlists.erase(name)) {
            std::cout << "Playlist deleted: " << name << "\n";
        } else {
            std::cout << "Playlist not found: " << name << "\n";
        }
    }

    Playlist* getPlaylist(const std::string& name) {
        auto it = playlists.find(name);
        if (it != playlists.end()) {
            return &it->second;
        } else {
            std::cout << "Playlist not found: " << name << "\n";
            return nullptr;
        }
    }

    void listPlaylists() const {
        if (playlists.empty()) {
            std::cout << "No playlists available.\n";
        } else {
            std::cout << "Available Playlists:\n";
            for (const auto& pair : playlists) {
                std::cout << "- " << pair.first << "\n";
            }
        }
    }
};

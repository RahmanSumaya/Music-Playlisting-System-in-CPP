#include <iostream>
#include<bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <map>
using namespace std;

class Song {
    public:
    string title, artist;

    Song(string t, string a) {
        title = t;
        artist = a;
    }
};

class Playlist {
public:
vector<Song> songs;
void addSong(string name, string artist){
    songs.emplace_back(name, artist);
    cout<<"Song added: "<<name<<" by "<<artist<<endl;
}
void removeSong(string title){
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
void displaySongs()
{
    if(songs.empty()) cout<<"Playlist is empty"<<endl;
    else {
        cout<<"song list "<<endl;
        for(auto& song:songs){
            cout<<song.title<<" by "<<song.artist<<endl;
        }
    }
}

    void searchSong(const string& khuja){
        bool found = false;
        for (auto& song : songs) {
            if (song.title.find(khuja) != string::npos || song.artist.find(khuja) != string::npos) {
                cout << "Found: " << song.title << " by " << song.artist << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No songs found matching: " << khuja << "\n";
        }
    }

void playSong(string kuja){
        bool found = false;
        for (auto& song : songs) {
            if (song.title.find(kuja) != string::npos || song.artist.find(kuja) != string::npos) {
                cout << "Playing " << song.title << " by " << song.artist << " " << kuja << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No songs found matching: " << kuja << "\n";
        }
    }

void shufflePlaylist() {
    srand(time(0));
    random_shuffle(songs.begin(),songs.end());
    cout<<"Playlist Shufflet"<<endl;
}

void savePlaylistSongs(string filename){
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
    void loadPlaylist(string filename){
        ifstream infile(filename);
        if(!infile){
            cerr<<"error ,oadinf"<<endl;
            return;
        }

        songs.clear();
        string title, artist;
        while (getline(infile, title) && getline(infile, artist)) {
            songs.emplace_back(title, artist);
        }

        cout << "Playlist loaded from " << filename << endl;
    }
};

class PlaylistManager{
    public:
    map<string, Playlist> playlists;
  //  map<string, Playlsit> playlists;
  void createPlaylist(const string& name) {
  //  ofstream play_list;
//play_list.open("playlistdata.txt", ios::app);
        if (playlists.find(name) == playlists.end()) {
            playlists[name] = Playlist();
            cout << "Playlist created: " << name << endl;
          //  play_list<<name<<'\t';
        } else {
            cout << "Playlist already exists: " << name << endl;
        }


    }

  void deletePlaylist(const string& name) {

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

    void savePlaylist(const string& playlistName, const string& filename) {
        auto it = playlists.find(playlistName);
        if (it == playlists.end()) {
            cout << "Playlist not found: " << playlistName << endl;
            return;
        }

        ofstream play_list_save(filename);
        if (!play_list_save) {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        play_list_save << "Playlist: " << playlistName << endl;
        for (const auto& song : it->second.songs) {
            play_list_save << song.title << " " << song.artist << endl;
        }

        cout << "Playlist " << playlistName << " saved to " << filename << endl;
    }

};

int main()
{
    PlaylistManager manager;

    int choice;
    string playlistName, title, artist, query, filename;

    do{
        cout<<"Music playlist management system"<<endl;
        cout<<"1. Create playlist"<<endl;
                cout<<"2. Delete playlist"<<endl;
        cout<<"3. List playlist"<<endl;
        cout<<"4. Manage playlist"<<endl;
        cout<<"5. Save Playlist"<<endl;
        cout<<"6. Exit"<<endl;
cout<<"Enter your choice : ";
cin>>choice;
cin.ignore();

switch(choice){

    case 1:
    cout<<"Enter Playlist Name : ";
    getline(cin, playlistName);
    manager.createPlaylist(playlistName);
    break;
    case 2:
    cout<<"Enter Playlist Name to Delete ";
    getline(cin, playlistName);
    manager.deletePlaylist(playlistName);
    break;
    case 3:
    cout<<"Here are The List of Playlists :"<<endl;
    manager.listPlaylists();
    break;
    case 4:
    cout<<"Enter Playlist Name to Manage :";
    getline(cin, playlistName);
    {
        Playlist* playlist = manager.getPlaylist(playlistName);
        if(playlist){
            int choice1;
            do{
                cout<<"Manage your playlist"<<endl;
                cout<<"1. Add a song"<<endl;
                 cout<<"2. Remove a song"<<endl;
  cout<<"3. Display songs"<<endl;
                 cout<<"4. Search song"<<endl;
                cout<<"5. Play song"<<endl;
                 cout<<"6. Shuffle song"<<endl;
                cout<<"7. Save Playlist "<<endl;
                 cout<<"8. Load songs"<<endl;
              cout<<"9. Back to mainmenu"<<endl;
              cout<<"Enter your choice";
              cin>>choice1;
              cin.ignore();

              switch (choice1) {
                        case 1:
                            cout << "Enter song title: ";
                            getline(std::cin, title);
                            cout << "Enter artist: ";
                            getline(std::cin, artist);
                            playlist->addSong(title, artist);
                            break;
                        case 2:
                            cout << "Enter song title to remove: ";
                            getline(std::cin, title);
                            playlist->removeSong(title);
                            break;
                        case 3:
                            playlist->displaySongs();
                            break;
                        case 4:
                            cout << "Enter title or artist to search: ";
                            getline(std::cin, query);
                            playlist->searchSong(query);
                            break;
                        case 5:
                            cout << "Enter song title to play: ";
                            getline(std::cin, title);
                            playlist->playSong(title);
                            break;
                        case 6:
                            playlist->shufflePlaylist();
                            break;
                        case 7:
                            cout << "Enter filename to save playlist: ";
                            getline(std::cin, filename);
                            playlist->savePlaylistSongs(filename);
                            break;
                        case 8:
                            cout << "Enter filename to load playlist: ";
                            getline(std::cin, filename);
                            playlist->loadPlaylist(filename);
                            break;
                        case 9:
                            cout << "Returning to main menu..."<<endl;
                            break;
                        default:
                            cout << "Invalid choice. Try again."<<endl;
                        }
             } while (choice1 != 9);
                }
    }  
        case 5:
            cout << "saved"<<endl;
            break;
        case 6:
        cout<<"bye bye"<<endl;
        break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
        
}

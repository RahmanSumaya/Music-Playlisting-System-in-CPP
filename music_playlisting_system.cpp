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
    void loadPlaylist(string filename){
        ifstream infile(filename);
        if(!infile){
            cerr<<"error ,oadinf"<<endl;
            return;
        }

        songs.clear();
        string title, artist;
        while (getline(inFile, title) && getline(inFile, artist)) {
            songs.emplace_back(title, artist);
        }

        cout << "Playlist loaded from " << filename << endl;
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
        cout<<"4. Managae playlist"<<endl;
        cout<<"5. exit"<<endl;
cout<<"enter yo cjoice"<<endl;
cin>>choice;
cin.ignore();

switch(choice){

    case 1:
    cout<<"enteer playlist name : ";
    getline(cin, playlistName);
    manager.createPlaylist(playlistName);
    break;
    case 2:
    cout<<"enter playlist anem to del ";
    getline(cin, playlistName);
    manager.deletePlaylist(playlistName);
    break;
    case 3:
    maanger.listPlaylists();
    break;
    case 4:
    cout<<"enter playlist name to manage :";
    getline(cin, playlistName);
    {
        Playlist* playlist = manager.getPlaylist(playlistName);
        if(playlist){
            int choice1;
            do{
                cout<<"manage yo plalist"<<endl;
                cout<<"1. add song"<<endl;
                 cout<<"2. remove"<<endl;
  cout<<"3. display songs"<<endl;
                 cout<<"4. search song"<<endl;
                cout<<"5. play song"<<endl;
                 cout<<"6. shuffle song"<<endl;
                cout<<"7. save "<<endl;
                 cout<<"8. load song"<<endl;
              cout<<"9. back to mainmenu"<<endl;
              cout<<"enter your choice"<<;
              cin>>choice1;
              cin.ignore();

              switch (subChoice) {
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
                            playlist->displayPlaylist();
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
                            playlist->savePlaylist(filename);
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
                    } while (subChoice != 9);
                }
            }
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
        }
    }
}



    }
}

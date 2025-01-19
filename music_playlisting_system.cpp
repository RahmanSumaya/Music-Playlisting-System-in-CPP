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

void lines(){
        cout<<endl<<endl<<endl<<endl<<endl;
}
vector<Song> songs;
void addSong(string name, string artist){
    
    songs.emplace_back(name, artist);
    cout<<endl<<"\t\t\tSong added: "<<name<<" by "<<artist<<endl;
}
void removeSong(string title){
    auto it = remove_if(songs.begin(), songs.end(), [&title](const Song& song) {
            return song.title == title;
        });

        if (it != songs.end()) {
            songs.erase(it, songs.end());
            cout<<"\t\t\tSong removed: " << title << endl;
        } else {
            cout<<"\t\t\tSong not found: " << title << endl;
        }
}
void displaySongs()
{
    lines();

    if(songs.empty()) cout<<"Playlist is empty"<<endl;
    else {
        cout<<"\t\t\tsong list "<<endl;
        for(auto& song:songs){
            cout<<"\t\t\t"<<song.title<<" by "<<song.artist<<endl;
        }
    }
}

    void searchSong(const string& khuja){
        
        bool found = false;
        for (auto& song : songs) {
            if (song.title.find(khuja) != string::npos || song.artist.find(khuja) != string::npos) {
                cout<<endl<<endl<<"\t\t\tFound: " << song.title << " by " << song.artist << endl;
                found = true;
            }
        }

        if (!found) {
            cout<<endl<<endl<<"\t\t\tNo songs found matching: " << khuja << "\n";
        }
    }

void playSong(string kuja){
    
        bool found = false;
        for (auto& song : songs) {
            if (song.title.find(kuja) != string::npos || song.artist.find(kuja) != string::npos) {
                cout<<"\t\t\tPlaying " << song.title << " by " << song.artist << " " << kuja << endl;
                found = true;
            }
        }

        if (!found) {
            cout<<endl<<endl<<"\t\t\tNo songs found matching: " << kuja << "\n";
        }
    }

void shufflePlaylist() {
    srand(time(0));
    random_shuffle(songs.begin(),songs.end());
    cout<<endl<<endl<<"\t\t\tPlaylist Shuffled"<<endl;
}

void savePlaylistSongs(string filename){
    

    ofstream play_list_save(filename);
    if(!play_list_save){
        cout<<"Error"<<endl;
        return;
    }
    for(auto& song:songs){
        play_list_save<<song.title<<","<<song.artist<<endl;
    }
cout<<endl<<"\t\t\tPlaylist saved to "<<filename<<endl;
}
   
void loadPlaylist(string filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error loading file" << endl;
        return;
    }

    songs.clear();
    string line, title, artist;
    cout << endl << endl << "\t\t\tPlaylist loaded from " << filename << endl;

    while (getline(infile, line)) {
        stringstream ss(line);
        if (getline(ss, title, ',') && getline(ss, artist)) {
            songs.emplace_back(title, artist);
            cout << "\t\t\t\tSong Name         : " << title << endl;
            cout << "\t\t\t\tArtist Name       : " << artist << endl;
            cout<<"\t\t\t\t--------------------------------------------------"<<endl;
        }
    }
}
};

class PlaylistManager{
    public:
   
void lines(){
        cout<<endl<<endl<<endl<<endl<<endl;
}
void welcome(){
lines();
        cout<<"\t\t\t**************************************"<<endl;
        cout<<"\t\t\t=                                    ="<<endl;
        cout<<"\t\t\t=              Welcome To            ="<<endl;
        cout<<"\t\t\t=  Music Playlist Management System  ="<<endl;
        cout<<"\t\t\t=                                    ="<<endl;
        cout<<"\t\t\t=                                    ="<<endl;
        cout<<"\t\t\t**************************************"<<endl;
conti();

}
 map<string, Playlist> playlists;
      void conti(){
        string xx;
        cout<<endl<<endl<<"\t\t\tPress Any Key To Continue : ";
        cin>>xx;
        system("cls");
        options();
    }
     
    
    void options1(Playlist* playlist) {
            int choice1;
            string title, artist, query, filename;

            cout<<endl<<"\t\t\tManage your playlist" << endl;
            cout<<"\t\t\t1. Add a song" << endl;
            cout<<"\t\t\t2. Remove a song" << endl;
            cout<<"\t\t\t3. Display songs" << endl;
            cout<<"\t\t\t4. Search song" << endl;
            cout<<"\t\t\t5. Play song" << endl;
            cout<<"\t\t\t6. Shuffle song" << endl;
            cout<<"\t\t\t7. Save Playlist " << endl;
            cout<<"\t\t\t8. Load songs" << endl;
            cout<<"\t\t\t9. Back to main menu" << endl;
            cout<<"\t\t\tEnter your choice: ";
            cin >> choice1;
            cin.ignore();

            switch (choice1) {
                case 1:
                system("cls");
                lines();
                    cout<<"\t\t\tEnter song title: ";
                    getline(std::cin, title);
                    cout<<"\t\t\tEnter artist: ";
                    getline(std::cin, artist);
                    playlist->addSong(title, artist);
                    conti1(playlist);
                    break;
                case 2:
                system("cls");

                    cout<<endl<<endl<<"\t\t\tEnter song title to remove: ";
                    getline(std::cin, title);
                    playlist->removeSong(title);
                    conti1(playlist);
                    break;
                case 3:
                                system("cls");

                    playlist->displaySongs();
                                        conti1(playlist);

                    break;
                case 4:
                                system("cls");

                    cout<<endl<<endl<<"\t\t\tEnter title or artist to search: ";
                    getline(std::cin, query);
                    playlist->searchSong(query);
                                        conti1(playlist);

                    break;
                case 5:
                                system("cls");

                    cout<<endl<<endl<<"\t\t\tEnter song title to play: ";
                    getline(std::cin, title);
                    playlist->playSong(title);
                                        conti1(playlist);

                    break;
                case 6:
                                system("cls");

                    playlist->shufflePlaylist();
                                        conti1(playlist);

                    break;
                case 7:
                                system("cls");

                cout<<endl<<endl<<"\t\t\tEnter filename to save playlist: ";
                    getline(std::cin, filename);
                    playlist->savePlaylistSongs(filename);
                                        conti1(playlist);

                    break;
                case 8:
                                system("cls");

                    cout<<endl<<endl<<"\t\t\tEnter filename to load playlist: ";
                    getline(std::cin, filename);
                    playlist->loadPlaylist(filename);
                                        conti1(playlist);

                    break;
                case 9:
                                system("cls");

                    cout<<endl<<endl<<"\t\t\tReturning to main menu..." << endl;
                    options();
                    break;
                default:
                cout<<endl<<endl<<"\t\t\tInvalid choice. Try again." << endl;
                                        conti1(playlist);

            }
        }
       void conti1(Playlist* playlist){
        string xx;
        cout<<endl<<endl<<"\t\t\tPress Any Key To Continue : ";
        cin>>xx;
        system("cls");
       options1(playlist);
    } 
    void options()
    {
int choice;
    string playlistName, title, artist, query, filename;
lines();
        cout<<"\t\t\tMusic playlist management system"<<endl;
        cout<<"\t\t\t1. Create playlist"<<endl;
                cout<<"\t\t\t2. Delete playlist"<<endl;
        cout<<"\t\t\t3. List playlist"<<endl;
        cout<<"\t\t\t4. Manage playlist"<<endl;
        cout<<"\t\t\t5. Exit"<<endl;
cout<<"\t\t\tEnter your choice : ";
cin>>choice;
cin.ignore();

switch(choice){

    case 1:
    system("cls");
    lines();

    cout<<"\t\t\tEnter Playlist Name : ";
    getline(cin, playlistName);
    createPlaylist(playlistName);
    break;
    case 2:
        system("cls");
        lines();

    cout<<"\t\t\tEnter Playlist Name to Delete ";
    getline(cin, playlistName);
    deletePlaylist(playlistName);
    break;
    case 3:
        system("cls");
lines();
    cout<<"\t\t\tHere are The List of Playlists :"<<endl;
    listPlaylists();
    break;
    case 4:
        system("cls");
lines();

    cout<<"\t\t\tEnter Playlist Name to Manage :";
    getline(cin, playlistName);
    {
       options1(&playlists[playlistName]);
    }  
        break;
        case 5:
        lines();

            system("cls");

        cout<<"\t\t\tThank You for Using My App"<<endl;
        exit(0);
    
        default:
        lines();

            cout<<"\t\t\tInvalid choice. Try again.\n";
            conti();
        }


    }
    

  //  map<string, Playlsit> playlists;
  void createPlaylist(const string& name) {
  //  ofstream play_list;
  
//play_list.open("playlistdata.txt", ios::app);
        if (playlists.find(name) == playlists.end()) {
            playlists[name] = Playlist();
            cout<<"\t\t\tPlaylist created: " << name << endl;
          //  play_list<<name<<'\t';
        } else {
    cout<<"\t\t\tPlaylist already exists: " << name << endl;
        }
        conti();
    }

  void deletePlaylist(const string& name) {
lines();
        if (playlists.erase(name)) {
            cout<<"\t\t\tPlaylist deleted: " << name << "\n";
        } else {
            cout<<"\t\t\tPlaylist not found: " << name << "\n";
        }
        conti();
    }

    Playlist* getPlaylist(const std::string& name) {
        auto it = playlists.find(name);
        if (it != playlists.end()) {
            return &it->second;
        } else {
            cout<<"\t\t\tPlaylist not found: " << name << "\n";
            return nullptr;
        }
    }

    void listPlaylists()  {
        lines();
        if (playlists.empty()) {
            cout<<"\t\t\tNo playlists available.\n";
        } else {
            cout<<"\t\t\tAvailable Playlists:\n";
            for (const auto& pair : playlists) {
                cout<<"\t\t\t- " << pair.first << "\n";
            }
        }
    conti();
    }


};

int main()
{
    PlaylistManager manager;
manager.welcome();
    manager.options();

    return 0;
        
}

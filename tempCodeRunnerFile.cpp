   
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
            cout << "\t\t\t\tArtist Name        : " << artist << endl;
        }
    }
};

#ifndef FOLDERS_H
#define FOLDERS_H

#include "./dataStructure.h"
using namespace std;

class Directory
{
    public:
        //CONSTRUCTOR
        Directory(int directoryId,string path,vector<File> files, vector<Directory> directories);
        
        //GETTERS
        int get_directoryId();
        string get_path();
        vector<File> get_files();
        vector<Directory> get_directories();

        //METHODS

    
    private:
        int directoryId;
        string path;
        vector<File> files;
        vector<Directory> directories;
};

// Member functions definitions including constructor

#endif

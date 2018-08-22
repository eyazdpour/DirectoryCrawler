#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <vector>
#include <dirent.h>
#include "./dataStructure.h"

using namespace std;

class Directory
{
  public:
    //CONSTRUCTOR
    Directory(int directoryId, string path);

    //GETTERS
    int get_directoryId();
    string get_path();
    string get_name();
    vector<File> get_files();
    vector<Directory> get_directories();

    //METHODS
    void save(); //to file in json format or xml
    void load(); //from file in json format or xml
    void crawl();
    bool has_directories();
    bool has_files();
    string list_directories();
    string list_files();

  private:
    int directoryId;
    string path;
    string name;
    vector<File> files;
    vector<Directory> directories;
};

// Member functions definitions including constructor
//CONSTRUCTOR:
Directory::Directory(int directoryId, string path)
{
    this->directoryId = directoryId;
    this->path = path;
}

//GETTERS:
int Directory::get_directoryId()
{
    return this->directoryId;
}
string Directory::get_path()
{
    return this->path;
}
string Directory::get_name()
{
    return this->name;
}
vector<File> Directory::get_files()
{
    return this->files;
}
vector<Directory> Directory::get_directories()
{
    return this->directories;
}

//METHODS:
void Directory::save()
{
}
void Directory::load()
{
}
void Directory::crawl()
{
    DIR *dirp = opendir(this->path.c_str());
    struct dirent *dp;
    int id = 0;
    while ((dp = readdir(dirp)) != NULL)
    {
        if (dp->d_type == DT_REG)
        {
            this->directories.push_back(Directory(1, dp->d_name));
            id++;
        }
        else if(dp->d_type == DT_DIR){
            this->files.push_back(File(1, dp->d_name)); //NEW CLASS OF FILE NEED TO BE CREATED
            id++;
        }
    }
    closedir(dirp);
}
bool Directory::has_directories()
{
    return (this->directories.size() > 0) ? true : false;
}
bool Directory::has_files()
{
    return (this->files.size() > 0) ? true : false;
}
string Directory::list_directories()
{
    string list = "Path: " + this->path + "\n";
    for (int i = 0; i < this->directories.size(); i++)
        list += "\t" + this->directories[i].path + "\n";
    return list;
}
string Directory::list_files()
{
    string list = "Path: " + this->path + "\n";
    // for (int i = 0; i < this->files.size(); i++)
    //     list += "\t" + this->files[i].path + "\n";
    return list;
}

#endif
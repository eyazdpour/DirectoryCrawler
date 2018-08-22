#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <typeinfo>
#include <vector>
#include <dirent.h>
#include "./File.h"

using namespace std;

class Directory
{
  public:
    //CONSTRUCTOR
    Directory(string path);

    //GETTERS
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
    string path;
    string name;
    vector<File> files;
    vector<Directory> directories;
};

// Member functions definitions including constructor
//CONSTRUCTOR:
Directory::Directory(string path)
{
    if(path=="." || path==".." || path.find("./")!= string::npos || path.find("../")!= string::npos ){
        throw std::invalid_argument( "Relative path is not supported!" );
    }
    this->path = path;
}

//GETTERS:
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
    while ((dp = readdir(dirp)) != NULL)
    {
        if (dp->d_type == DT_DIR)
        {
            string d_name = (string)(dp->d_name);
            if (d_name != "." && d_name != "..")
                this->directories.push_back(Directory(d_name));
        }
        else if (dp->d_type == DT_REG)
            this->files.push_back(File(dp->d_name));
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
    for (int i = 0; i < this->files.size(); i++)
        list += "\t" + this->files[i].name + "\n";
    return list;
}

#endif

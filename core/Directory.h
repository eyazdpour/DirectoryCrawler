#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <algorithm>
#include <vector>
#include <sstream>
#include <dirent.h>

#include "./File.h"

using namespace std;

class Directory
{
    friend class Recursive;

  public:
    //CONSTRUCTOR
    Directory(string path);

    //GETTERS
    string get_path();
    vector<File> get_files();
    vector<Directory> get_directories();

    //METHODS
    string get_name();
    void save(); //to file in json format or xml
    void load(); //from file in json format or xml
    void crawl();
    bool has_directories();
    bool has_files();
    string list_directories();
    string list_files();

  private:
    string path;
    vector<File> files;
    vector<Directory> directories;
    bool isCrawled = false;
};

// Member functions definitions including constructor
//CONSTRUCTOR:
Directory::Directory(string path)
{
    std::replace(path.begin(), path.end(), '/', '\\');
    if (path == "." || path == ".." || path.find(".\\") != string::npos || path.find("..\\") != string::npos)
    {
        throw std::invalid_argument("Relative path is not supported!");
    }
    this->path = path;
}

//GETTERS:
string Directory::get_path()
{
    return this->path;
}
vector<File> Directory::get_files()
{
    return this->files; //returning a copy of vector
}
vector<Directory> Directory::get_directories()
{
    return this->directories; //returning a copy of vector
}

//METHODS:
string Directory::get_name()
{
    std::stringstream ss(this->path);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, '\\'))
    {
        splittedStrings.push_back(item);
    }
    return splittedStrings[splittedStrings.size() - 1];
}
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
                this->directories.push_back(Directory(this->path + "\\" + d_name));
        }
        else if (dp->d_type == DT_REG)
            this->files.push_back(File(dp->d_name));
    }
    closedir(dirp);
    this->isCrawled = true;
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
    string list = "";
    for (int i = 0; i < this->directories.size(); i++)
        list += "\t" + this->directories[i].path + "\n";
    return list;
}
string Directory::list_files()
{
    string list = "";
    for (int i = 0; i < this->files.size(); i++)
        list += "\t" + this->files[i].get_fullName() + "\n";
    return list;
}

#endif

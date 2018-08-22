#ifndef FILE_H
#define FILE_H

using namespace std;
class File
{

  public:
    File(string name, string extension, string path);
    string fullName(void);
    string fullPath(void);

  private:
    string name;
    string extension;
    string path;
};

// Member functions definitions including constructor
File::File(string name, string extension, string path)
{
    File::name = name;
    File::extension = extension;
    File::path = path;
}
string File::fullName(void)
{
    return name + '.' + extension;
}
string File::fullPath(void)
{
    return path + '\\' + name + '.' + extension;
}

#endif


#ifndef FOLDERS_H
#define FOLDERS_H

#include <vector>
using namespace std;

class Folders
{
    public:
        Folders(string path,vector<string> folders);
        string get_path();
        vector<string> get_folders();

    private:
        string path;
        vector<string> folders;
};

// Member functions definitions including constructor
Folders::Folders(string path,vector<string> folders){
    Folders::path = path;
    Folders::folders = folders;
}
string Folders::get_path(){
    return path;
}
vector<string> Folders::get_folders(){
    return folders;
}

#endif

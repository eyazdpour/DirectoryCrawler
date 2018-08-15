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
    name = name;
    extension = extension;
    path = path;
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


#ifndef FOLDER_H
#define FOLDER_H

using namespace std;
class Folder
{
};

// Member functions definitions including constructor


#endif

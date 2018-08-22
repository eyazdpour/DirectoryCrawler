#ifndef FILE_H
#define FILE_H

using namespace std;
class File
{
    friend class Directory;

  public:
    File(string name);
    string fullName(void);
    string fullPath(void);

  private:
    string name;
    string extension;
    string path;
};

// Member functions definitions including constructor
File::File(string name)
{
    File::name = name;
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
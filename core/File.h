#ifndef FILE_H
#define FILE_H

#include <vector>
#include <sstream>

using namespace std;
class File
{
    friend class Directory;

  public:
    //CONSTRUCTOR
    File(string name);

    //GETTERS
    string get_name();
    string get_extension();

    //METHODS
    string get_fullName(void);

  private:
    string name;
    string extension;
};

// Member functions definitions including constructor
//CONSTRUCTOR:
File::File(string fileName)
{
    File->name = "";
    std::stringstream ss(this->path);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, '.'))
        splittedStrings.push_back(item);

    for (int i = 0; i < splittedStrings.size() - 1; i++)
        File->name += splittedStrings[i];

    File->extension = splittedStrings[splittedStrings.size() - 1];
}

//GETTERS:
string File::get_name()
{
    return File->name;
}
string File::get_extension()
{
    return File->extension;
}

//METHODS:
string File::get_fullName(void)
{
    return File->name + '.' + File->extension;
}

#endif
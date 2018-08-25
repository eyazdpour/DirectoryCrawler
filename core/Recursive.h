#ifndef RECURSIVE_H
#define RECURSIVE_H

#include "./Directory.h"

using namespace std;
class Recursive
{
public:
  //METHODS
  void crawl(Directory &dir);
  string list_directories(Directory &dir);
};

// Member functions definitions
//METHODS:
void Recursive::crawl(Directory &dir)
{
  if (!(dir.isCrawled))
    dir.crawl();
  for (int i = 0; i < dir.directories.size(); i++)
    dir.directories[i].crawl();

  for (int i = 0; i < dir.directories.size(); i++)
  {
    if (dir.has_directories())
      this->crawl(dir.directories[i]);
  }
}
string Recursive::list_directories(Directory &dir)
{
  string list = dir.path;

  for (int i = 0; i < dir.directories.size(); i++)
  {
    list += "\n\t\t" + dir.directories[i].get_name();
  }
  list += "\n--------------------------------\n";

  for (int i = 0; i < dir.directories.size(); i++)
  {
    if (dir.has_directories())
      list += this->list_directories(dir.directories[i]);
  }

  return list;
}

#endif

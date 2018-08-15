#ifndef CRAWLER_H
#define CRAWLER_H

#include <vector>
#include "dataStructure.h"

using namespace std;
class Crawler
{

public:
  string getPath(void);
  Crawler();
  Crawler(string);
  vector<Folder> directList_folders(string path);

private:
  string path;
};

// Member functions definitions including constructor
Crawler::Crawler(void)
{

}
Crawler::Crawler(string directoryPath)
{
  path = directoryPath;
}
string Crawler::getPath(void)
{
  return path;
}

vector<Folder> List_directFolders(string path){
  
}

#endif

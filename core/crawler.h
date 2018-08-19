#ifndef CRAWLER_H
#define CRAWLER_H

#include <vector>
#include <dirent.h>
#include "dataStructure.h"

using namespace std;
class Crawler
{

public:
  Crawler();
  Folders read_directory(string path);
};

// Member functions definitions including constructor
Crawler::Crawler(void)
{

}

Folders Crawler::read_directory(string path){
    vector<Folder> folders;
    DIR* dirp = opendir(path.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
         if(dp->d_type==16) /*for windows only*/ {
           folders.push_back(Folder(dp->d_name));
         }
    }
    closedir(dirp);
    return Folders(path,folders);
}

#endif

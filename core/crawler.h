#ifndef CRAWLER_H
#define CRAWLER_H

#include <vector>
#include <dirent.h>

using namespace std;
class Crawler
{

public:
  static Folders read_directory(string path);
};

// Member functions definitions including constructor
Folders Crawler::read_directory(string path){
    vector<string> folders;
    DIR* dirp = opendir(path.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
         if(dp->d_type==16) /*for windows only*/ {
           folders.push_back(dp->d_name);
         }
    }
    closedir(dirp);
    return Folders(path,folders);
}

#endif

#include <iostream>
#include <string>
#include <vector>

#include "../core/Directory.h"

int main()
{
    
    // Folders f1 = Crawler::read_directory(".");
    // vector<string> dirNames = f1.get_folders();
    // for(int i =0 ; i<dirNames.size() ;i++){
    //     cout<<dirNames[i]<<endl;
    // }

    Directory* d1 = new Directory(0,".");
    d1->crawl_directories();
    std::cout<<(d1->list_directories())<<std::endl;
}
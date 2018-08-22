#include <iostream>
#include <string>
#include <vector>

#include "../core/crawler.h"
#include "../core/dataStructure.h"

int main()
{
    
    Folders f1 = Crawler::read_directory(".");
    vector<string> dirNames = f1.get_folders();
    for(int i =0 ; i<dirNames.size() ;i++){
        cout<<dirNames[i]<<endl;
    }
}
/************************
 * dataStructure.h:
 *   Folder class is something more than enough and should be removed ASAP.
 *   We should only have a Folders Class including of a vector<string> prop.
 ***********************/
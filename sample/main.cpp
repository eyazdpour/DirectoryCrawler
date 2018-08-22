#include <iostream>
#include <string>
#include <vector>

#include "../core/Directory.h"

int main()
{
    Directory* d1 = new Directory(".");
    d1->crawl();
    std::cout<<"----------Directories----------\n"<<(d1->list_directories())<<std::endl;
    
    std::cout<<"----------Files----------\n"<<(d1->list_files())<<std::endl;
}
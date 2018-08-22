#include <iostream>
#include <string>

#include "../core/Directory.h"

int main()
{
    Directory *d1 = new Directory("C:/Erfan\\");
    d1->crawl();
    //cout<<d1->get_name()<<endl;
    std::cout << "----------Directories----------\n"
              << (d1->list_directories()) << std::endl;
    std::cout << "----------Files----------\n"
              << (d1->list_files()) << std::endl;
}
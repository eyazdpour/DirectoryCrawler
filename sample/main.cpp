#include <iostream>
#include <string>

#include "../core/Directory.h"
#include "../core/Recursive.h"

int main()
{
    Directory *d1 = new Directory("C:/Erfan/Music");

    //cout<<d1->get_name()<<endl;
    // std::cout << "----------Directories----------\n"
    //           << (d1->list_directories()) << std::endl;
    // std::cout << "----------Files----------\n"
    //           << (d1->list_files()) << std::endl;

    Recursive *r = new Recursive();
    r->crawl(*d1);
    std::cout << r->list_directories(*d1) << std::endl;
}
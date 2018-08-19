#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
 
#include <sys/types.h>
#include <dirent.h>
 
typedef std::vector<std::string> stringvec;

void read_directory(const std::string& name, stringvec& v)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
         if(dp->d_type==16) //for windows only
        v.push_back(dp->d_name);
        
    }
    closedir(dirp);
}
int main()
{
    stringvec v;
    read_directory("C:/$Recycle.Bin", v);
    std::copy(v.begin(), v.end(),
         std::ostream_iterator<std::string>(std::cout, "\n"));
}
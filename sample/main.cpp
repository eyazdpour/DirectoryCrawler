#include <iostream>
#include "../core/crawler.h"

using namespace std;
int main()
{
    cout<<"This will be a sample use of DirectoryCrawler\n*******************"<<endl;
    Crawler c = Crawler("hello");
    cout<<c.getDirAddress()<<endl;
}
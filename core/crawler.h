#ifndef CRAWLER_H
#define CRAWLER_H

using namespace std;
class Crawler
{

  public:
    string getDirPath(void);
    Crawler();
    Crawler(string);

  private:
    string dirPath;
};

// Member functions definitions including constructor
Crawler::Crawler(void){

}
Crawler::Crawler(string directoryPath){
  dirPath = directoryPath;
}
string Crawler::getDirPath(void){
  return dirPath;
}

#endif

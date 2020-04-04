#include <iostream>
#include <fstream>
using namespace std;

int main (){

  int NumberOfWords=0;
  string word;
  string Doc;
  word.clear();

  std::fstream File;

  std::cout << "Enter your document name: " << '\n';
  std::cin >> Doc;
  File.open(Doc, std::fstream::in);

  while(File>>word)
    NumberOfWords++;

  std::cout << "Number of Words: "<<NumberOfWords << '\n';

  File.close();
  return 0;
}

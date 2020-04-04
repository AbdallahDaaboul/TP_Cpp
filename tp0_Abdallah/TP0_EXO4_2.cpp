#include <iostream>
#include <fstream>
using namespace std;

int main (){

  string word;
  string Doc;
  word.clear();

  std::fstream File;
  std::fstream WriteFile;

  std::cout << "Enter your document name: " << '\n';
  std::cin >> Doc;
  File.open(Doc, std::fstream::in);
  WriteFile.open("WordsStartingWithA", std::fstream::out);

  while(File>>word)
    if (word[0]=='A') {
      WriteFile<<word<<endl;
    }

  File.close();
  WriteFile.close();
  return 0;
}

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//print a map
void printMMap(map <string,int> m){
  map<string, int>::iterator it;
  std::cout << "************************************" << '\n';
  for ( it = m.begin(); it != m.end(); it++ ){
    std::cout << it->first  // string (key)
    << ':'
    << it->second   // string's value
    << std::endl ;
  }
    std::cout << "************************************" << '\n';
}

int main()
{
  vector<string> v;
  string current;
  map <string,int> m;
  string A="Hello world hi i love world hi hi";
  istringstream buf(A);

  //create a map with all the sentence words as keys and their occurence
  while (buf>>current){
    //cout<<current<<endl;
    m[current]++;
  }

  printMMap(m);

  istringstream buf2(A);
  string FirstRepeatedLeft;
  string FirstRepeatedRight;
  int lock=0;
  while (buf2>>current){
    if (m[current]>=2){
      if(lock==0){
        FirstRepeatedLeft=current;
        lock=1;
      }
      FirstRepeatedRight=current;
    }
  }
  std::cout << "First Repeated from the left side: "<<FirstRepeatedLeft<< '\n';
  std::cout << "First Repeated from the right side: "<<FirstRepeatedRight<< '\n';

  return 0;
}


/*Words findTheRepeatedWords(std::string sentence, int repetitions) {
Words w;
int counter=0;
istringstream buf(sentence);
while (buf>>current){
if (find(v.begin(), v.end(), current) != v.end())
cout << current<<endl;
counter++;
v.push_back(current);

}
}
*/

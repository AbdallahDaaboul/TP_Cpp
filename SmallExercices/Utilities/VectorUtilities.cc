#include <iostream>
#include <vector>

using namespace std;
int main(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

std::cout << "iteration1" << '\n';
  for (size_t i = 0; i < v.size(); i++) {
      std::cout << v[i] << '\n';
  }
  std::cout << "iteration2" << '\n';

  // v  is   full
  vector<int>::iterator  iter ;
  for( iter  = v.begin() ;iter  !=  v.end();  ++iter ){
    cout <<*iter  << endl;
  }
  std::cout << "iteration3" << '\n';
  for(auto it  = v.begin() ;   it  !=  v.end();  ++it ){
    cout <<*it  << endl;
  }
  std::cout << "iteration4" << '\n';
  for(int i:v){
    std::cout << i << '\n';
  }



  std::cout << "erase" << '\n';
  v.erase(v.begin());
  v.erase(v.end()-1);

  for (size_t i = 0; i < v.size(); i++) {
      std::cout << v[i] << '\n';
  }

  std::cout << "empty? " <<v.empty() << '\n';
  v.clear();
  std::cout << "v.size  "<<v.size() << '\n';
  std::cout << "empty? " <<v.empty() << '\n';

  for (size_t i = 0; i < v.size(); i++) {
      std::cout << v[i] << '\n';
  }
}

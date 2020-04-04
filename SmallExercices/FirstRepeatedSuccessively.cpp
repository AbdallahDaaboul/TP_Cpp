//the first repeated word successively
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
   string current;
   string previous = "0";
   string A="Hello world hi i love world hi hi";
   istringstream buf(A);
   while (buf>>current){
        if(previous == current)
            cout << "Repeated Word: " << current << "\n";
        previous = current;
}

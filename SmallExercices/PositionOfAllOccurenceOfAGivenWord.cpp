// string::find
#include <iostream>       // std::cout
#include <string>         // std::string

using namespace std;
int main ()
{
  string str ("There are two needles in this haystack with needles.");
  string str2 ("needle");
  //printf("%ld\n",string::npos);
  size_t found=str.find(str2);
 // printf("%ld\n",found );

  while(found!=-1){
	printf("%ld\n",found );
	found=str.find(str2,found+1);
  }
}

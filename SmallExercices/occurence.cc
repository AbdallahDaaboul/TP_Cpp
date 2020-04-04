#include<iostream>
#include<string>
#include<cstring>
using namespace std;


int main() {
  string A="hello this is boudi is hello id boudi";
  size_t b;
  b=1;
  printf("%c\n",A[b-1]);
  while(strcmp(&A[b-1]," ")!=0){
    printf("%d\n", strcmp(&A[b-1]," "));
    b=A.find("is",b+1);
    //printf("%ld\n",b );
  }
  printf("%ld\n",b );
  return 0;
}

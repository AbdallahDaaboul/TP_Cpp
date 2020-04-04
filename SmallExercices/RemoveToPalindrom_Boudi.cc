#include <stdio.h>
#include<iostream>
using namespace std;

//Function that check if a given String is a Palindrom
bool isPalindrome(string A){
  int i=0;
  int size;
  size=A.size();
  for (size_t i = 0; i < size/2; i++) {
    if(A[i] != A[size-i-1])
    return 0;
  }
  return 1;
}

//Could we remove a character so the string could be palindrom ?
int RemoveToPalind(string A){

  //if palindrom no need to do anything
  //we return -1
  if (isPalindrome(A)==1)
  return -1;

  else{
    int i=0;
    int j;
    j=A.size()-1;

    while(A[i]==A[j]){
      i++;
      j--;
    }

    //we re in the positions where A[i] and A[j] doesn't match
    //we check if by removing A[i] the rest is palindrom then we return i
    //we check if by removing A[j] the rest is palindrom then we return i

    //cout<<A.substr(i+1,j-i)<<endl;
    if( isPalindrome(A.substr(i+1,j-i)) )
    return i;
    if( isPalindrome(A.substr(i,j-i)) )
    return j;

  }
  //if we don't have any chance so it could be a palindrom we return -2
  return -2;
}



int main(int argc, char const *argv[]) {

  string A="abbac";
  string B="abdbdba";
  string C="abdcbdba";

  //std::cout << isPalindrome(A) << '\n';
  //std::cout << isPalindrome(B) << '\n';
  //std::cout << isPalindrome(C) << '\n';

  cout<<RemoveToPalind(A)<<endl;
  cout<<RemoveToPalind(B)<<endl;
  cout<<RemoveToPalind(C)<<endl;


  return 0;
}

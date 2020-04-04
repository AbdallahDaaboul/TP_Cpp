#include <iostream>
int main(){

//pointeur
  int *p =new int(42);
  std::cout << *p << '\n';

//tableau dynamique
  int n=3;
  int *p2 =new int[n];
  p2[0]=1;
  p2[1]=2;
  p2[2]=3;

  for (int i = 0; i < n; i++) {
    std::cout << p2[i] << '\n';
  }

//matrice dynamique
  int **p3 =new int*[n];
  for (int i = 0; i < n; i++) {
    p3[i]=new int[3];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      p3[i][j]=i;
      std::cout << p3[i][j] << " ";
    }
    std::cout  << '\n';
  }

  delete p;
  delete[]  p2;
  for (int i = 0; i < n; i++) {
    delete p3[i];
  }
  delete[] p3;
}

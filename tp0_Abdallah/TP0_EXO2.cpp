#include <iostream>
#include <string>
using namespace std;

int main (){
  int n;
  float y;
  std::cout << "Donner un entier et un flottant" << '\n';
  cin >> n >> y;
  std::cout << "Le produit de " << n <<" par "<<y<<" est : "<<n*y<< '\n';
  return 0;
}

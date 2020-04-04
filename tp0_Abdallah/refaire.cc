#include <iostream>
#include <iomanip>

int main(){
  /*int n;
  float y;
  std::cout << "donner un entier et un flottant" << '\n';
  std::cin >> n >>y;
  std::cout << "le produit est "<< n*1.0*y << '\n';
  return 0;*/

  float partiel,exam;
  std::cin>> partiel >>exam;
  std::cout<<std::setprecision(4)<<0.4*partiel+0.6*exam;

  return 0;
}

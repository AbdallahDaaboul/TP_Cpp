#include <iostream>
using namespace std;
/*
int main(){
  int size;
  std::cin >> size ;

  int xm=size/2+2;
  int xl=xm;
  int xr=xm;

  for (int i = 0; i < size; i++) {
  //  std::cout << xl<<xr << '\n';
    for (int j = 0; j < 2*size+1; j++) {
      if (j==xl || j==xr) {
        std::cout << "*";
      }
      else{
        std::cout << " ";
      }
    }
  xl=xl-1;
  xr=xr+1;
  std::cout << '\n';
}

xl=xl+1;
xr=xr-1;


for (int i = 0; i < size-1; i++) {
//std::cout << xl<<xr << '\n';
xl=xl+1;
xr=xr-1;
  for (int j = 0; j < 2*size; j++) {
    if (j==xl || j==xr) {
      std::cout << "*";
    }
    else{
      std::cout << " ";
    }
  }

std::cout << '\n';
}
}
*/

int main(){
  size_t size;
  std::cin >> size ;
  size_t space=size-1;
  size_t spaceInt=-1;


  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < space; j++) {
      std::cout << " " ;
    }
    if(i==0){std::cout << "*" ;}
    else{
      std::cout << "*" ;
      for (size_t k = 0; k < spaceInt; k++) {
        std::cout << " " ;
      }
      std::cout << "*" ;
    }
    std::cout  << '\n';
    space--;
    spaceInt+=2;
  }

  spaceInt-=2;
  space++;
  //std::cout << spaceInt<<space << '\n';
  spaceInt-=2;
  space++;

  for (size_t i = 0; i < size; i++) {

    for (size_t j = 0; j < space; j++) {
    //  std::cout << "je boucle 1" << '\n';
      std::cout << " " ;
    }
    if(i==size-2){std::cout << "*" ;}
    else{
      std::cout << "*" ;
      for (size_t k = 0; k < spaceInt; k++) {
          //std::cout << spaceInt << '\n';
          //    std::cout << "je boucle 2" << '\n';
        std::cout << " " ;
      }
      std::cout << "*" ;
    }

    std::cout<< '\n';
    space++;
    if (spaceInt==1) {
      spaceInt=0;
    }
    else{
      spaceInt=spaceInt-2;
    }
    if (spaceInt<0||spaceInt>size) {
      break;
    }
  }

  return 0;
}

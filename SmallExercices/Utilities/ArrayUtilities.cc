#include <iostream>
int main(){
  const int DIM = 3;
  double tab[DIM] = {1,2,3};
  double number[] = {1,2,3,4,5,6};
  int size = sizeof(number)/sizeof(number[0]);

  std::cout << "sizeeee="<<size << '\n';
  for (size_t i = 0; i < DIM; i++)
    std::cout << tab[i] << '\n';

  for (int i = 0; i < size; i++) {
    std::cout << number[i] << '\n';
  }
}

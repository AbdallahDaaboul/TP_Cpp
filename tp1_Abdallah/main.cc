#include <iostream>
#include "passgrid.hh"
#include "path.hh"
#include <vector>

int main()
{
  srand(time(NULL));
  PassGrid pg(9,8);
  pg.print();
  pg.reset();
  std::cout << std::endl;
  pg.print();
  std::cout<< '\n' << "-----------Fin 1-----------" << '\n' << std::endl;

  Path c(5,9,8);
  c.print();

  std::cout<< '\n' << "-----------Fin 2-----------" << '\n' << std::endl;
  std::cout<< pg.generate(c) << std::endl;
  std::cout<< '\n' << "-----------Fin 3-----------" << '\n' << std::endl;

  std::cout << "fin exo" << '\n';
  pg.gridsvg("hey.svg");
/*  std::cout << (pg.generate(c)).size() << '\n';
  for (size_t i = 0; i < (pg.generate(c)).size(); i++) {
    std::cout << pg.generate(c)[i] << '\n';
  }*/
}

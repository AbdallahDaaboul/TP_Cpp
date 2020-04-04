#pragma once
#include <cstdlib>
#include <vector>
#include "path.hh"

class PassGrid{
 public:
  // Constructor
  PassGrid(std::size_t w, std::size_t h);
  // Destructor
  ~PassGrid();
  // Function members
  void print() const;
  void reset();
  char * generate(Path P);
  void gridsvg(char const *file);
 private:
   std::vector <std::vector<char>> Grille ;
  /*
  char **Grille; //
  size_t I;
  size_t J;
  */
};

#pragma once
#include <cstdlib>
#include<iostream>
#include<vector>

class Path{
public:
  //Constructor
  Path(int n, std::size_t hmax,std::size_t wmax);
  void print() const;
  std::vector<int> getChemin(){return Chemin;};
  size_t getxi(){return xi;};
  size_t getyi(){return yi;};
  size_t getnmax(){return nmax;};
private:
  int nmax;
  size_t xi;
  size_t yi;
  std::vector<int> Chemin;
};

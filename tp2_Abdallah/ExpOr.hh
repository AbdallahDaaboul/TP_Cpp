#pragma once
#include<string>
#include<iostream>
#include"ExpBin.hh"
#include"ExpLog.hh"
#include "Atom.hh"


class ExpOr:public ExpBin{
public:

  ExpOr(ExpLog& E1, ExpLog& E2):ExpBin(E1,E2){};

  std::string toString() const ;
  ThreeVal_t evaluate()const ;


  ~ExpOr(){};
private:
  const std::string name="Or";
};

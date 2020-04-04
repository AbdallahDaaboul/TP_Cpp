#pragma once
#include<string>
#include<iostream>
#include"ExpBin.hh"
#include"ExpLog.hh"
#include "Atom.hh"


class ExpAnd:public ExpBin{
public:

  ExpAnd(ExpLog& E1, ExpLog& E2):ExpBin(E1,E2){};

  std::string toString() const ;
  ThreeVal_t evaluate()const ;


  ~ExpAnd(){};
private:
  const std::string name="AND";
};

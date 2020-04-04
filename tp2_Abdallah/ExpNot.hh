#pragma once
#include<string>
#include<iostream>
#include"ExpLog.hh"
#include "Atom.hh"


class ExpNot:public ExpLog{
public:

  ExpNot(ExpNot& N): opd(N){};
  ExpNot(Atom& A): opd(A){};

  std::string toString() const ;
  ThreeVal_t evaluate()const ;


  ~ExpNot(){};
private:
  ExpLog&  opd;
  const std::string name="NOT";
};

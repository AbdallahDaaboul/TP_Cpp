#pragma once
#include<string>
#include<iostream>
#include"ExpLog.hh"
#include "Atom.hh"


class ExpBin:public ExpLog{
public:

  ExpBin(ExpLog& N1, ExpLog& N2): opd1(N1),opd2(N2){};
  virtual std::string toString() const =0;
  virtual ThreeVal_t evaluate()const = 0;

  ~ExpBin(){};

protected:
  ExpLog&  opd1;
  ExpLog&  opd2;
};

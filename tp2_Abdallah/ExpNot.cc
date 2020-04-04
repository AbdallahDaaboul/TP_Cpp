
#include<string>
#include<iostream>
#include"ExpLog.hh"
#include "Atom.hh"
#include "ExpNot.hh"

std::string ExpNot::toString() const {return "Not"+opd.toString();}

ThreeVal_t ExpNot::evaluate()const {
  if (opd.evaluate()== ThreeVal_t::T )
    return ThreeVal_t::F;
  if (opd.evaluate()== ThreeVal_t::F)
    return ThreeVal_t::T;
  else
    return ThreeVal_t::U;

}

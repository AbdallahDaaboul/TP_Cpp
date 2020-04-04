#include<string>
#include<iostream>
#include"ExpBin.hh"
#include"ExpLog.hh"
#include "Atom.hh"
#include "ExpAnd.hh"
#include "ExpOr.hh"

std::string ExpOr::toString() const{
return "("+opd1.toString()+" Or "+opd2.toString()+")";
}

ThreeVal_t ExpOr::evaluate()const{
  if(opd1.evaluate()==ThreeVal_t::T || opd2.evaluate()==ThreeVal_t::T)
    return ThreeVal_t::T;
  else if( opd1.evaluate()==ThreeVal_t::F && opd2.evaluate()==ThreeVal_t::F )
      return ThreeVal_t::F;
  else
    return ThreeVal_t::U;

}

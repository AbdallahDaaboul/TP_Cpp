#include "ExpLog.hh"
#include <iostream>

std::ostream& operator<<(std::ostream & out, ThreeVal_t val){
  switch (val) {
    case ThreeVal_t::T :
      out << "T" ;
      break;
    case ThreeVal_t::F :
      out << "F" ;
      break;
    case ThreeVal_t::U :
      out << "U" ;
      break;
  }
  return(out);
}

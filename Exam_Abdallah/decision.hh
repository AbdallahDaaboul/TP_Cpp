#pragma once

#include <string>
#include <iostream>
#include "processing.hh"
#include "utilities.h"
class Decision : public Processing{
 public:
  Decision(const std::string& label):Processing(label,2){}
  Decision(const std::string& label, const std::string& i):Processing(label,i,2){}
  Decision(Decision & d):Processing(d._label,d._instr,d._nb_connect_max){}
  std::string toString() const;
  void setText(const std::string& s){_instr = removeLines(s);}
  int simulate(TableOfVariables & t) const;
private:
  typedef enum{LT,GT,EQ,NEQ,LEQ,GEQ,NOP} Operator;
  Operator findOperator() const;
  size_t positionOperator(Operator op) const;
};

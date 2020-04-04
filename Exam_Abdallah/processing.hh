
#pragma once

#include <string>
#include "shape.hh"

class Processing : public Shape{
protected:
  std::string _instr;
 public:
  Processing(const std::string& label):Shape(label){}
  Processing(const std::string& label, const std::string& i):Shape(label),_instr(i){}
  Processing(const std::string& l, const std::string& i,const size_t& n):Shape(l,n),_instr(i){}
  Processing(const std::string& label, const size_t& n):Shape(label,n){}

  void setText(std::string t);
  std::string toString() const;
  int simulate(TableOfVariables & t) const;
};

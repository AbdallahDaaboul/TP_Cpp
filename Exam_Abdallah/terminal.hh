#pragma once

#include <string>
#include "shape.hh"

class Terminal: public Shape
{
 public:
  Terminal(const std::string& label):Shape(label){}
  Terminal(const std::string& label, size_t n):Shape(label,n){}
  ~Terminal(){}
  std::string toString() const;
  int simulate(TableOfVariables & t) const = 0;
};

class Start : public Terminal
{
public:
  Start():Terminal("Start"){}
  int simulate(TableOfVariables & t) const {return 0;}

};


class End : public Terminal
{
public:
  End():Terminal("End",0){}
  int simulate(TableOfVariables & t) const {return -1;}

};

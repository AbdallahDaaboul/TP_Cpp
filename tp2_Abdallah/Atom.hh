#pragma once
#include<string>
#include<iostream>
#include"ExpLog.hh"

class Atom:public ExpLog{

public:
  Atom(ThreeVal_t Valeur);
  Atom();
  Atom(const Atom & a);
  Atom(bool b);
  std::string toString() const;
  ThreeVal_t evaluate() const;
  //~Atom(){};
  Atom& operator=(const Atom & a);
  //Atom& operator=(ThreeVal_t t);
  ThreeVal_t get_val(){return val;}
  
private:

  static int counter;
  ThreeVal_t val;
  std::string name;
};

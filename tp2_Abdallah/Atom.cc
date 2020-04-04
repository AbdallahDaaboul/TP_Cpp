#include<string>
#include<iostream>
#include "Atom.hh"
#include "ExpLog.hh"

Atom::Atom(ThreeVal_t Valeur){
  val= Valeur;
  name="a_" + std::to_string(counter);
  counter=counter+1;
}

Atom::Atom(){
  val = ThreeVal_t::U ;
  name = "a_" + std::to_string(counter);
  counter = counter+1;
}

Atom::Atom(bool b){
  if(b==false)
    val=ThreeVal_t::F;
  else
    val=ThreeVal_t::T;

  name="a_"+std::to_string(counter);
  counter+=1;
}

Atom::Atom(const Atom & a){
  val=a.val;
  name="a_" + std::to_string(counter);
  counter=counter+1;
}

std::string Atom::toString() const{
  std::string value;
  switch (val) {
    case ThreeVal_t::T :
      value = "T" ;
      break;
    case ThreeVal_t::F :
      value = "F" ;
      break;
    case ThreeVal_t::U :
      value = "U" ;
      break;
  }
  return ( "(" + name + " = " + value +")" );
}
ThreeVal_t Atom::evaluate() const{
  return val;
}

Atom& Atom::operator=(const Atom & a){
  val=a.val;
  return *this;
}

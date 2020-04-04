#pragma once

#include <string>
#include <cassert>
#include "utilities.h"
class Shape{


protected:
  std::string _label;
  const size_t _nb_connect_max;
  size_t _id;
  static int _cpt_id;

public:
  Shape():_nb_connect_max(1),_id(_cpt_id++){}
  Shape(const std::string& l):_label(l),_nb_connect_max(1),_id(_cpt_id++){}
  Shape(const std::string& l, size_t  n):_label(l),_nb_connect_max(n),_id(_cpt_id++){}
  virtual std::string toString() const = 0;
  virtual int simulate(TableOfVariables & t) const = 0;
  virtual ~Shape(){_cpt_id--;}
  size_t id() const {return _id;}
  size_t nb_connect_max() const{return _nb_connect_max;}
  std::string label() const {return _label;}
  virtual void setText(std::string){}


private :

};

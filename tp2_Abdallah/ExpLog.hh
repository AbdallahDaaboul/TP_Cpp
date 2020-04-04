#pragma once
#include<string>
#include<iostream>

enum class ThreeVal_t {T,F,U};

std::ostream& operator<<(std::ostream & out, ThreeVal_t val);

class ExpLog{
public:
  virtual std::string toString() const =0;
  virtual ThreeVal_t evaluate()const = 0;
  bool operator==(ThreeVal_t T){if (this->evaluate()==T) return 1;else return 0; }
  ~ExpLog(){};
};

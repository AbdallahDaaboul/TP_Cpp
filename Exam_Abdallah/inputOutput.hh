#pragma once

#include "processing.hh"

class InputOutput: public Processing{


 public:
   InputOutput(const std::string& label,const bool& b);
   InputOutput(const std::string& label,const std::string& i,bool b);

   std::string toString()const;

 private:
   bool bb;
};

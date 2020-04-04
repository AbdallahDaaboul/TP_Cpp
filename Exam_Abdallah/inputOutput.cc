#include "inputOutput.hh"
#include <sstream>
 InputOutput::InputOutput(const std::string& label,const std::string& i,bool b):Processing(label,i){}
InputOutput::InputOutput(const std::string& label,const bool& b):Processing(label){}


 std::string InputOutput::toString()const{
   std::istringstream ss(_instr);
   std::string s(_instr);

   std::string chaine;
   std::string tmp;

   std::size_t nbreofline=numberofLine(s);
   for (size_t i = 0; i < nbreofline; i++)
     chaine=chaine+" ";


   std::size_t maxlength=maxLength(s);
   for (size_t i = 0; i < maxlength+1; i++)
     chaine=chaine+"_";


   chaine=chaine+"\n";

  while(nbreofline!=1){
    nbreofline--;

    for (size_t i = 0; i < nbreofline; i++)
     chaine=chaine+" ";

    chaine=chaine+"/";
    std::getline(ss,tmp);
    chaine=chaine+tmp+"/";
    chaine=chaine+("\n");
  }

for (size_t i = 0; i < maxlength+2; i++)
  chaine=chaine+"-";

 return chaine;
 }

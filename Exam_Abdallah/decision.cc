#include "decision.hh"

std::string Decision::toString() const
{
  std::string s(_instr);
  unsigned int max = maxLength(s);
  unsigned int mid = (max%2 == 0)?max/2:max/2+1;
  size_t size =  (max%2 == 0)?max + 2: max + 1;
  size_t intern =(max%2 == 0)?0:1;
  std::string chaine;
  if( max%2 == 1 ) //first line odd
    {
      chaine +=std::string(mid,' ') + "^\n";
      mid--;
    }
  for (size_t j = 0 ; j < size/2 - 1 ; ++j)
    {
      chaine +=std::string(mid,' ') + "/" + std::string(intern,' ') + "\\\n";
      intern += 2;
      mid -= 1;
    }
   chaine += "/" + s + "\\\n";
   for (size_t j = size/2+1 ; j <= size ; ++j)
    {
      chaine +=std::string(mid,' ') + "\\" + std::string(intern,' ') + "/\n";
      intern -= 2;
      mid += 1;
    }
   if( max%2 == 1 ) //last line odd
     {
       chaine +=std::string(mid,' ') + "V\n";
     }
   
  return chaine;
}
// return std::string::npos if not found
Decision::Operator Decision::findOperator() const
{
  if(_instr.find('<')  != std::string::npos) return LT;
  if(_instr.find('>')  != std::string::npos) return GT;
  if(_instr.find("==") != std::string::npos) return EQ;
  if(_instr.find("!=") != std::string::npos) return NEQ;
  if(_instr.find("<=") != std::string::npos) return LEQ;
  if(_instr.find(">=") != std::string::npos) return GEQ;
  return NOP;

}
size_t Decision::positionOperator(Operator op) const
{
  switch(op)
    {
    case LT:
      return _instr.find('<');
    case GT:
      return _instr.find('>');
    case EQ:
      return _instr.find("==");
    case NEQ:
      return _instr.find("!=");
    case LEQ:
      return _instr.find("<=");
    case GEQ:
      return _instr.find(">=");
    default:
      return std::string::npos;
    }
}

int Decision::simulate(TableOfVariables & t) const
{
  std::cerr << "Not implemented yet !" << std::endl;
  return 0;

}


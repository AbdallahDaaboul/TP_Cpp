#include "terminal.hh"

std::string Terminal::toString() const
{
  size_t l = _label.length();
  std::string out = " ";
  out = out + std::string(l,'-') + "\n";
  out = out +  "/" + std::string(l,' ') +"\\\n";
  out = out +  "|" + _label +"|\n";
  out = out + "\\" + std::string(l,'_') + "/\n";
  return out;
}


#include "molecule.hh"
#include "utility.hh"
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

Molecule::Molecule(const std::string& eclateeString){
  std::string s(eclateeString);
  std::replace( s.begin(), s.end(), '=', '-');
  atomVector=split(s, "-");
}

std::ostream& operator<<(std::ostream & out,const Molecule& mol){
  out << "[";
  unsigned int cpt=0;
  for(const auto& iter : mol.atomVector){
    out << iter;
    if (cpt!=mol.atomVector.size()-1)
    out << ";";
    cpt++;
  }
  out<<"]";
  return out;
}



std::string Molecule::normalise() const{
  std::map<std::string, int> mymap;

  for(const auto& iter : atomVector){
    auto it = mymap.find(iter);
    if (it==mymap.end())
    mymap.insert(std::make_pair(iter,1));
    else
    mymap[iter]++; //it->second++
  }
  std::string output;
  for(const auto& iter : mymap){
    //for (int i = 0; i < iter.second; i++)
    if(iter.second != 1)
    output += iter.first + std::to_string(iter.second);
    else
    output += iter.first;
  }
  return output;
}

/*
void Molecule::afficherAtomVector() const{
  std::cout << "[";
  unsigned int cpt=0;
  for(const auto& iter : atomVector){
    std::cout << iter;
    if (cpt!=atomVector.size()-1)
    std::cout << ";";
    cpt++;
  }
  std::cout<<"]";
}
*/

#ifndef MOLECULE_HH
#define MOLECULE_HH

#include<iostream>
#include<vector>
#include<string>

class Molecule{

private:
  std::vector<std::string> atomVector;

public:
  Molecule(const std::string& eclateeString);
  friend std::ostream& operator<<(std::ostream & out,const Molecule& mol);
  //std::ostream& operator<<(std::ostream & out);
  std::vector<std::string> get_atomVector(){return atomVector;};
  void afficherAtomVector() const;
  std::string normalise() const;
};

#endif

#include "molecule.hh"
#include "reaction.hh"
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
  cout << "*** Exercice 1 ***" << endl;
  ifstream file("molecules.txt");
  list<Molecule> les_molecules;
  string s;
  while( file >> s)  {
    les_molecules.push_back(Molecule(s));
  }
  for(const auto& iter : les_molecules) {
    std::cout << iter ;
    //iter.afficherAtomVector();
    std::cout  << '\n';
  }


  std::cout<< '\n' << "**************Test normalise**************" << '\n'<< '\n';

  for(const auto& iter : les_molecules)
    cout << iter.normalise() << std::endl;

  file.close();

  ofstream fichier;
  fichier.open("FormeNormalisee_exo1.txt", ios::out);

  if(fichier)
  for(const auto& iter : les_molecules)
    fichier << iter.normalise() << std::endl;
  else
    cerr<<"Error, Cant open ur doc";
  fichier.close();

  cout << '\n'<< "************* Exercice 2 **************" << '\n'<< endl;

  file.open("reactions.txt");
  list<Reaction> lesReactions;
  while(getline(file,s))
  {
    if(!s.empty())
    lesReactions.push_back(Reaction(s));
  }

  std::cout << "/* TestAfficher  */" << '\n'<< '\n';
  for(const  auto& iter : lesReactions){
    std::cout << iter;
    std::cout  << std::endl;
  }

  std::cout<< '\n' << "**************Test normalise**************" << '\n'<< '\n';
  for(const  auto& iter : lesReactions)
    std::cout << iter.normalise() << endl;

  file.close();

  ofstream fichier2;
  fichier.open("FormeNormalisee_exo2.txt", ios::out);

  if(fichier2)
  for(const auto& iter : lesReactions)
    fichier << iter.normalise() << std::endl;
  else
    cerr<<"Error, Cant open ur doc";
  fichier.close();
}

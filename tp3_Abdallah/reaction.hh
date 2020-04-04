#ifndef REACTION_HH
#define REACTION_HH
#include "molecule.hh"
#include <vector>

class Reaction{
private:
  std::vector<Molecule> MoleculesGauche;
  std::vector<Molecule> MoleculesDroite;
public:
  Reaction(const std::string& equationEclatee);
  void affichageReaction() const;
  friend std::ostream& operator<<(std::ostream & out,const Reaction& Reac);
  std::string normalise() const;
};


#endif

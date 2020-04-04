#include "reaction.hh"
#include "utility.hh"
#include "molecule.hh"
#include <vector>

Reaction::Reaction(const std::string& equationEclatee){

  std::string equationEclate;
  for (size_t i = 0; i < equationEclatee.length(); i++)
    if (equationEclatee[i]!=' ')
      equationEclate+=equationEclatee[i];

  std::string PartieGauche=split(equationEclate,">" )[0];
  std::string PartieDroite=split(equationEclate,">")[1];

  std::vector<std::string> molGauche=split(PartieGauche,"+");
  std::vector<std::string> molDroite=split(PartieDroite,"+");

  for (auto iter : molGauche )
    MoleculesGauche.push_back(Molecule(iter));

  for (auto iter : molDroite )
    MoleculesDroite.push_back(Molecule(iter));
}

std::ostream& operator<<(std::ostream & out,const Reaction& Reac){
  unsigned int cpt=0;
  for( const auto iter: Reac.MoleculesGauche){
    out << iter;
    //iter.afficherAtomVector();

    if (cpt!=Reac.MoleculesGauche.size()-1)
    out  << " + ";

    cpt++;
  }
  out << " > ";

  cpt=0;

  for( const auto& iter: Reac.MoleculesDroite){
    out<<iter;
    //iter.afficherAtomVector();

    if (cpt!=Reac.MoleculesDroite.size()-1)
    out  << " + ";
    cpt++;
  }
  return out;
}



std::string Reaction::normalise() const {
  std::string output;
  unsigned int cpt=0;
  for( const auto& iter : MoleculesGauche){
    output+= iter.normalise();
    if (cpt!=MoleculesGauche.size()-1)
      output+=" + ";
    cpt++;
  }
  cpt=0;
  output+=" > ";
  for( const auto& iter : MoleculesDroite){
    output+= iter.normalise();
    if (cpt!=MoleculesDroite.size()-1)
      output+= " + ";
    cpt++;
  }
  return output;
}

/*
void Reaction::affichageReaction() const{
unsigned int cpt=0;
for( const auto iter: MoleculesGauche){
iter.afficherAtomVector();

if (cpt!=MoleculesGauche.size()-1)
std::cout  << '+';

cpt++;
}
std::cout << " > ";

cpt=0;

for( const auto& iter: MoleculesDroite){
iter.afficherAtomVector();
if (cpt!=MoleculesDroite.size()-1)
std::cout  << '+';
cpt++;
}
*/

  
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main (){
  string Nom;
  float NotePartiel , NoteFinal , NoteDevoir, MoyenneDevoir;
  int N(0);
  
  cout << "Entrez votre nom svp : " << '\n';
  cin >> Nom;
  cout << "Bonjour " << Nom << ". Veuillez entrer votre note de final suivie par celle du partiel : " << '\n';
  cin >> NoteFinal>> NotePartiel;
  cout<< "Entrez vos notes de devoirs"<<'\n';
  while(cin>>NoteDevoir){
      MoyenneDevoir+=NoteDevoir;
      N=N+1;
  }
  
  MoyenneDevoir=MoyenneDevoir/N;
 
  cout << setprecision(4) << " Votre Moyenne est " << 0.4*NoteFinal+0.2*NotePartiel+0.4*MoyenneDevoir << '\n';
  return 0;
}

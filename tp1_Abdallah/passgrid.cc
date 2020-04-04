#include "passgrid.hh"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

const int MAX=94;
const int MIN=33;

//Constructor
PassGrid::PassGrid(std::size_t w, std::size_t h){
  //  Grille=new char*[w];
  Grille.reserve(h);
  Grille.resize(h);
    for (size_t i = 0; i < h; i++) {
      Grille[i].reserve(w);
      Grille[i].resize(w);
      for (size_t j = 0; j < w; j++)
        Grille[i][j]= (char) (rand() % (MAX - MIN + 1) + MIN);
    }
}

//Destructor
PassGrid::~PassGrid(){
  /*for (size_t i = 0; i < Grille.size(); i++)
    Grille[i].erase(Grille[i].begin(),Grille[i].end());
  Grille.erase(Grille.begin(),Grille.end());*/
}
// Function members
void PassGrid::print() const{
  for (size_t i = 0; i < Grille.size(); i++) {
    for (size_t j = 0; j < Grille[i].size(); j++){
      std::cout << Grille[i][j];
      std::cout<<"(" << i << j <<") " ;
    }

    std::cout << '\n';
  }
}

void PassGrid::reset(){
  for (size_t i = 0; i < Grille.size(); i++)
    for (size_t j = 0; j < Grille[1].size(); j++)
      Grille[i][j]= (char) (rand() % (MAX - MIN + 1) + MIN);
}

char * PassGrid::generate(Path P){
  char *Code= new char [P.getnmax()+1];
  /*std::vector<char> Code;
  Grille.reserve((P.getChemin()).size());
  Grille.resize((P.getChemin()).size());
  */
  size_t x=P.getxi();
  size_t y=P.getyi();
  Code[0] = Grille[x][y];

  for (size_t i = 0; i < 5 ; i++) {
    //std::cout << "pchemin" <<P.getChemin()[i]  << std::endl;
    if (P.getChemin()[i]==1) {x=x+1; y=y-1;}     //sw
    else if (P.getChemin()[i]==2) {x=x+1;}       //S
    else if (P.getChemin()[i]==3) {x=x+1; y=y+1;}//SE
    else if (P.getChemin()[i]==4){y=y+1;}        //E
    else if (P.getChemin()[i]==5){x=x-1; y=y+1;}//NE
    else if (P.getChemin()[i]==6){x=x-1;}       //N
    else if (P.getChemin()[i]==7){x=x-1; y=y-1;} //NW
    else if (P.getChemin()[i]==8){y=y-1;}       //W

    Code[i+1]=Grille[x][y] ;
  }
  return Code;
}

void PassGrid::gridsvg(char const *file){
    std::ofstream File;
    File.open (file, std::ofstream::out);
  File << "<svg viewBox=\"0 0 "<< 50*Grille.size()+100<<" "<<100+50*Grille[1].size() <<"\" version=\"1.1\">"<<std::endl;
    File << "<text fill=\"navy\" font-size=\"30\">"<<std::endl;
    for (size_t i = 0; i < Grille[1].size(); i++) {
      for (size_t j = 0; j < Grille.size(); j++) {
        if (Grille[j][i]=='<') {
            File <<"<tspan x=\""<<50 +50*j <<"\" y=\""<< 50+i*50 <<"\"> " << "&lt;"<<" </tspan>"<<std::endl;
        }
        else if (Grille[j][i]=='&') {
            File <<"<tspan x=\""<<50 +50*j <<"\" y=\""<< 50+i*50 <<"\"> " << "&amp;"<<" </tspan>"<<std::endl;
        }
      else  File <<"<tspan x=\""<<50 +50*j <<"\" y=\""<< 50+i*50 <<"\"> " << Grille[j][i]<<" </tspan>"<<std::endl;
      }
      File<< '\n';
    }
    File << "</text>"<<std::endl;
    File << "</svg>"<<std::endl;

    File.close();
}

//https://www.w3schools.com/graphics/svg_intro.asp

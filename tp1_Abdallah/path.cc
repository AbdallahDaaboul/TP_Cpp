#include "path.hh"
#include <iostream>
#include <string>
#include <vector>

//Constructor
    Path::Path(int n, std::size_t hmax,std::size_t wmax){
    nmax=n;
    std::cout << "nmax = :"<<nmax << '\n';
    Chemin.reserve(n);
    Chemin.resize(n);

    size_t x=rand()%wmax;
    size_t y=rand()%hmax;

    xi=x;
    yi=y;

    std::cout << "Je commence en ("<<xi<<" , "<<yi<<")"<< std::endl;



    int Step_x=rand()%3-1;
    int Step_y=rand()%3-1;

    for (int i = 0; i < n; i++) {

      while(x+Step_x >= wmax || x+Step_x < 0 || y+Step_y>=hmax || y+Step_y < 0 || (Step_x==0 && Step_y==0)){
        Step_x=rand()%3-1;
        Step_y=rand()%3-1;
      }
      x+= Step_x;
      y+= Step_y;

      std::cout << "("<<x<<" , "<<y<<")" << '\n';

      if (Step_x == 1 && Step_y ==-1)
      {
        //Chemin.push_back(1);
        Chemin[i]=1;
      }
      else if(Step_x == 1 && Step_y ==0)
      {
        //Chemin.push_back(2);
        Chemin[i]=2;
      }
      else if(Step_x == 1 && Step_y ==1)
      {
        //Chemin.push_back(3);
        Chemin[i]=3;

      }
      else if(Step_x == 0 && Step_y ==1)
      {
        //Chemin.push_back(4);
        Chemin[i]=4;

      }
      else if(Step_x == -1 && Step_y ==1)
      {
        //Chemin.push_back(5);
        Chemin[i]=5;

      }
      else if(Step_x == -1 && Step_y ==0)
      {
        //Chemin.push_back(6);
        Chemin[i]=6;

      }
      else if(Step_x == -1 && Step_y ==-1)
      {
        //Chemin.push_back(7);
        Chemin[i]=7;

      }
      else if(Step_x == 0 && Step_y ==-1)
      {
        //Chemin.push_back(8);
        Chemin[i]=8;

      }
    }
  }


  void Path::print() const{
  char t[8][3] = {"SW", "S", "SE", "E", "NE", "N", "NW", "W"};
  std::cout<<"La longueur de votre chemin : " << Chemin.size() << '\n';
  for (size_t i = 0; i < Chemin.size(); ++i)
  {
    std::cout << "-->" << t[Chemin[i]-1];
  }
  std::cout  << '\n';
  }

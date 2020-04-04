#pragma once
#include <iostream>

template<typename T>
class Tableau2D
{
protected:
  T** table;
  std::size_t nbLine;
  std::size_t nbColumn;

public:
  Tableau2D(std::size_t nbC, std::size_t nbL);
  Tableau2D(const Tableau2D&);
  void init (std::size_t nbC , std::size_t nbL);
  T operator()(std::size_t C, std::size_t L)const;
  T& operator()(std::size_t C, std::size_t L);
  template<typename U>
  friend std::ostream& operator<<(std::ostream& , const Tableau2D<U> &);
  bool operator== (const Tableau2D<T>& lhs) const;
  Tableau2D<T>& operator=(const Tableau2D<T>& m);
  virtual ~Tableau2D();
};


template<typename T>
void Tableau2D<T>::init (std::size_t nbC , std::size_t nbL){
  nbColumn = nbC;
  nbLine = nbL;
  table= new T*[nbC];
  for(std::size_t i =0 ;  i < nbC  ;  ++ i )
    table[i] = new T[nbL] ;
}

template<typename T>
Tableau2D<T>::Tableau2D(std::size_t nbC, std::size_t nbL){
  init(nbC,nbL);
}

template<typename T>
Tableau2D<T>::Tableau2D(const Tableau2D<T>& t)
{
  init(t.nbColumn,t.nbLine);
  for (std::size_t i = 0; i < t.nbColumn; i++)
    for (std::size_t j = 0; j < t.nbLine; j++)
      table[i][j]=t.table[i][j];
}


template<typename T>
Tableau2D<T>::~Tableau2D()
{
  for (std::size_t i = 0; i < nbColumn; i++)
      delete(table[i]);
  delete(table);
}

template<typename T>
std::ostream& operator<<(std::ostream& os , const Tableau2D<T> & t)
{
  for (std::size_t i = 0; i < t.nbColumn; i++){
    for (std::size_t j = 0; j < t.nbLine; j++)
      os<<' '<<t.table[i][j]<<' ';
    os<<'\n';
  }
  return os;
}

template<typename T>
bool Tableau2D<T>::operator==(const Tableau2D<T>& rhs) const
{
  for (std::size_t i = 0; i < rhs.nbColumn; i++)
    for (std::size_t j = 0; j < rhs.nbLine; j++)
        if (rhs.table[i][j]!=table[i][j])
          return false;
  return true;
}
template<typename T>
Tableau2D<T>& Tableau2D<T>::operator=(const Tableau2D<T>& m)
{
  this->nbColumn = m.nbColumn;
  this->nbLine = m.nbLine;
  this->table= new T*[m.nbColumn];
  for(std::size_t i =0 ;  i < m.nbColumn  ;  ++ i )
    this->table[i] = new T[m.nbLine] ;

  for (std::size_t i = 0; i < this->nbColumn; i++)
    for (std::size_t j = 0; j < this->nbLine; j++)
      this->table[i][j]=m.table[i][j];
  return *this;
}

template<typename T>
T& Tableau2D<T>::operator()(std::size_t c,std::size_t l){
  return table[c][l];
}

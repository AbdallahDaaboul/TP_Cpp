#pragma once
#include <iostream>
#include "tableau2D.hh"

template<typename T>
class Matrix: public Tableau2D<T>{
private:

public:
  static const bool identity;
  Matrix(std::size_t nbC, std::size_t nbL,int val);
  Matrix(std::size_t nbC, std::size_t nbL,const bool &identity);

  Matrix<T> operator+(const Matrix<T>& m) const;
  Matrix<T> operator-(const Matrix<T>& m) const;
  Matrix<T> operator*(const Matrix<T>& m) const;

  template<typename U>
  friend Matrix<U> operator*(float a,const Matrix<U>& m);
  template<typename U>
  friend Matrix<U> operator*(const Matrix<U>& m,float a);
  template<typename U>
  friend Matrix<U> operator/(const Matrix<U>& m,float a);


  template<typename U>
  friend Matrix<U> operator+(float a,const Matrix<U>& m);
  template<typename U>
  friend Matrix<U> operator+(const Matrix<U>& m,float a);

  template<typename U>
  friend Matrix<U> operator-(float a,const Matrix<U>& m);
  template<typename U>
  friend Matrix<U> operator-(const Matrix<U>& m,float a);

  Matrix<T> transpose() ;
};

template<typename T>
const bool Matrix<T>::identity=true;

template<typename T>
Matrix<T>::Matrix(std::size_t nbC, std::size_t nbL,int  val):Tableau2D<T>(nbC,nbL){

    for (size_t i = 0; i < nbC; i++)
      for (size_t j = 0; j < nbL; j++)
          this -> table[i][j]=val;
}

template<typename T>
Matrix<T>::Matrix(std::size_t nbC, std::size_t nbL,const bool& identity):Tableau2D<T>(nbC,nbL){
    for (size_t i = 0; i < nbC; i++)
      for (size_t j = 0; j < nbL; j++){
        if(i==j)
          this -> table[i][j]=1;
        else
          this->table[i][j]=0;
      }
}


template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m) const{
  Matrix<T> output(m.nbColumn,m.nbLine,0);
  for (size_t i = 0; i < m.nbColumn; i++)
    for (size_t j = 0; j < m.nbLine; j++)
      output.table[i][j] = Tableau2D<T>::table[i][j] + m.table[i][j];
  return output;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m) const{
  Matrix<T> output(m.nbColumn,m.nbLine,0);
  for (size_t i = 0; i < m.nbColumn; i++)
    for (size_t j = 0; j < m.nbLine; j++)
      output.table[i][j] = Tableau2D<T>::table[i][j] - m.table[i][j];
  return output;
}


template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m) const{
  Matrix<T> output(this->nbColumn,m.nbLine,0);
  for (size_t i = 0; i < this->nbLine; i++)
    for (size_t j = 0; j < m.nbColumn; j++)
      for (size_t k = 0; k < m.nbLine; k++)
        output.table[i][j] += this->table[i][k] * m.table[k][j];
  return output;
}


template<typename T>
Matrix<T> operator*(float a,const Matrix<T>& m){
  Matrix<T> output(m.nbColumn,m.nbLine,0);
  for (size_t i = 0; i < m.nbColumn; i++)
    for (size_t j = 0; j < m.nbLine; j++)
      output.table[i][j] = a * m.table[i][j];
  return output;
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& m,float a){
  Matrix<T> output(m.nbColumn,m.nbLine,0);
  for (size_t i = 0; i < m.nbColumn; i++)
    for (size_t j = 0; j < m.nbLine; j++)
      output.table[i][j] = a * m.table[i][j];
  return output;
}


template<typename T>
Matrix<T> operator/(const Matrix<T>& m,float a){
  Matrix<T> output(m.nbColumn,m.nbLine,0);
  for (size_t i = 0; i < m.nbColumn; i++)
    for (size_t j = 0; j < m.nbLine; j++)
      output.table[i][j] =  m.table[i][j]/a;
  return output;
}


template<typename T>
Matrix<T> operator+(const Matrix<T>& m,float a){
  Matrix<T> output(m.nbColumn,m.nbLine,0);
  for (size_t i = 0; i < m.nbColumn; i++)
    for (size_t j = 0; j < m.nbLine; j++)
      output.table[i][j] =  m.table[i][j]+a;
  return output;
}

template<typename T>
Matrix<T> operator+(float a,const Matrix<T>& m){
  Matrix<T> output(m.nbColumn,m.nbLine,0);
  for (size_t i = 0; i < m.nbColumn; i++)
    for (size_t j = 0; j < m.nbLine; j++)
      output.table[i][j] =  m.table[i][j]+a;
  return output;
}

template<typename T>
Matrix<T> operator-(const Matrix<T>& m,float a){
  Matrix<T> output(m.nbColumn,m.nbLine,0);
  for (size_t i = 0; i < m.nbColumn; i++)
    for (size_t j = 0; j < m.nbLine; j++)
      output.table[i][j] =  m.table[i][j]-a;
  return output;
}

template<typename T>
Matrix<T> operator-(float a,const Matrix<T>& m){
  Matrix<T> output(m.nbColumn,m.nbLine,0);
  for (size_t i = 0; i < m.nbColumn; i++)
    for (size_t j = 0; j < m.nbLine; j++)
      output.table[i][j] =  a-m.table[i][j];
  return output;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() {
  Matrix<T> output(this->nbLine,this->nbColumn,0);
  for (size_t i = 0; i < this->nbLine; i++)
    for (size_t j = 0; j < this->nbColumn; j++)
      output.table[i][j]=this->table[j][i];
  return output;
}

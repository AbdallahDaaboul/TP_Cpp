/* this program returns the pth factor of a number (double)*/
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;


double getfactor(double n, int p){
vector<double> factors;

  if (fmod(n,2)==0){   //fmod = % for doubles
    for (size_t i = 1; i < n/2+1; i++) {
      if(fmod(n,i)==0)
        factors.push_back(i);
    }
  }

  if (fmod(n,2) !=0){
    for (double i = 1; i <= n/2; i=i+2) {
      if(fmod(n,i)==0)
        factors.push_back(i);
    }
  }

  factors.push_back(n);

  for (double i = 0; i < factors.size(); i++) {
    std::cout << factors[i] << '\n';
  }
  return factors[p-1];
}

int main(){
double n=100;
int p=3;
double result=getfactor(n,p) ;
std::cout <<"The "<<p<<"th factor is: "<< result<< '\n';

}

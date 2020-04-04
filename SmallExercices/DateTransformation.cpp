//Given a date in format 20111201 aaaammdd transform it to ddMMaaaa 20111201 -> 01Dec2011

#include<iostream>
#include<string>
#include<cstring>
using namespace std;




string dateTransformation(string S){

  string tab[12];
  tab[0]="Jan";
  tab[1]="feb";
  tab[2]="mar";
  tab[3]="apr";
  tab[4]="may";
  tab[5]="jun";
  tab[6]="Jul";
  tab[7]="aug";
  tab[8]="SEp";
  tab[9]="Oct";
  tab[10]="Nov";
  tab[11]="Dec";

  string newdate;
  string month;
  month=S.substr(4,2);
  int Month=stoi(month);
  newdate=S.substr(6,2)+tab[Month-1]+S.substr(0,4);
  return newdate;
}

int main(){

  string S="20111201";
  cout<<dateTransformation(S);
  return 0;
}

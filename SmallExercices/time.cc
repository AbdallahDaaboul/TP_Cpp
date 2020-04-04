#include<iostream>
#include<string>
#include"stdio.h"
using namespace std;


/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    int hour,min;
    string retour;
    char sec[5];
    const char *cstr = s.c_str();
    sscanf(cstr, "%d:%d:%s",&hour,&min,sec);

    if(sec[2]=='A'){
        hour=hour%12;
        retour="0"+std::to_string(hour) + s.substr(2,6);
        return retour;
       }
    else{
        if(hour !=12)
            hour=(hour+12)%24;
        if(hour==0)
            retour="0"+std::to_string(hour) + s.substr(2,6);
        retour=std::to_string(hour) + s.substr(2,6);
        return  (retour);
    }
    
}

int main(){
    cout<<timeConversion("12:40:22AM");
    return 0;
}

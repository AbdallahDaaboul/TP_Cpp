#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> split_string(string);

// Complete the plusMinus function below.
void plusMinus(vector<int> arr) {
    int p=0;
    int n=0;
    int z=0;

    int s=arr.size();
    for (int i = 0; i < s; i++) {
        if(arr[i]>0)
            p++;
        else if(arr[i]<0)
            n++;
        else
            z++;
   }
   cout<<setprecision(5)<<p*1.0/s<<endl;
   cout<<setprecision(5)<<n*1.0/s<<endl;
   cout<<setprecision(5)<<z*1.0/s<<endl;
}

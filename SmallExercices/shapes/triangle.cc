#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
int space=n-1;
for(int i=0;i<n;i++){
    for(int j=0;j<space;j++)
        cout<<" ";
    for(int k=0;k<n-space;k++)
        cout<<"#";
    cout<<"\n";
    space--;
}
}

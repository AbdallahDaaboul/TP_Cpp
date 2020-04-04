#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) {
    sort(arr.begin(),arr.end());
    vector<long int> v(2,0);
    for(int i=0;i<4;i++){
        v[0]+=arr[i];
        v[1]+=arr[arr.size()-i-1];
    }
    cout<<v[0]<<" "<<v[1];
}

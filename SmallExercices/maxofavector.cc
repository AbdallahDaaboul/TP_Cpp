#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the birthdayCakeCandles function below.
int birthdayCakeCandles(vector<int> ar) {
    int max;
    max = *max_element(ar.begin(), ar.end());
    int counter=0;
    for(int i=0;i<ar.size();i++){
        if (max==ar[i])
            counter++;
    }
    return counter;
}

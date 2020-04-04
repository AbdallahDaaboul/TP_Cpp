#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    int n;
    int k(1);
    int p(20000);
    bool test(true);
    //cout << "Jusqu'a quel nombre voulez vous afficher les nombres premiers ?" << endl;
    //cin >> p;

    vector<int> premier(1, 2);
    premier.reserve(p);
for(n = 3; n <= p; n+=2)
{
    test = true;
    double fs = floor(sqrt(n));
        for(int j = 3; j <= fs; j=j+2)
        {
            if(n % j == 0)
            {
                test = false;
                break;
            }
        }
        if(test)
        {
        premier.push_back(n);
        k += 1;
        }
}

for(int i = 0; i < premier.size(); i++)
{
    cout << premier[i] << "\n";
}
cout << endl << endl;
cout << "Parmi les " << p << " premiers nombre, " << k << " sont premiers." << endl;
    return 0;
}

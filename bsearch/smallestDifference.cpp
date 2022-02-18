#include <bits/stdc++.h>
using namespace std;

int findSmallestSum(vector<int>&, vector<int>&);


int main()
{
    vector<int> a, b;
    srand(time(NULL));
    int size = rand() % 20;
    while(size--) {
        a.push_back(rand() % 500 + 1);
    }
    size = rand() % 20;
    while(size--) {
        b.push_back(rand()%500 + 1);
    }

    cout << "a : ";
    for(auto x:a) {
        cout << x << " ";
    }
    cout << endl;

    cout << "b : ";
    for(auto x: b) {
        cout << x << " ";
    }
    cout << endl;

    cout << "smallest difference : " << findSmallestSum(a,b) << endl;

    return 0;
}


int findSmallestSum(vector<int>& a, vector<int>& b) {
    if(a.size() == 0 || b.size() == 0) return -1;
    sort(a.begin(), a.end());
    sort(b.begin(),b.end());
    
    int iA = 0, iB = 0;
    int smallestDiff = INT_MAX;

    while(iA < a.size() && iB < b.size()) {
        int diff = abs(a[iA] - b[iB]);
        smallestDiff = min(smallestDiff, diff);

        if(a[iA] < b[iB]) {
            iA++;
        } else {
            iB++;
        }
    }

    return smallestDiff;
}
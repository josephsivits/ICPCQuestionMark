#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool checkFromHead(vector<ll> v)
{
    int head = 0;
    int tail = v.size();
    
}

int main()
{
    ll m = 0, n = 0;
    cin >> m >> n;

    vector<ll> roll;
    int a = 0;
    int size = m;
    while (m--)
    {
        cin >> a;
        roll.push_back(a);
    }

    int q = 0;
    while(n--)
    {
        cin >> q;

        if(checkFromHead(roll) || checkFromTail(roll))
        {
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }


    }

    return 0;
}
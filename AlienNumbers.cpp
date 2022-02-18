#include <bits/stdc++.h>
using namespace std;

// could use unsigned long long, 1 <= N <= 10^15
#define ull unsigned long long

#define MAX 10000000000000000

ull findsmallNum(map<ull,int,greater<int>> m, set<int> s)
{
    ull ans = 0;
    bool firstPos = true;

    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(firstPos)
        {
            int number = it->second;
            ull decimalPos = it->first;

            while(number >= 0) 
            {
                if(number == 1 && decimalPos!=1) break;

                if(s.count(number)) number--; // continue
                else // add to ans
                {
                    ans += decimalPos * number;
                    break; // get out of while loop
                }
            }
            // add later
            // if(number = it->second) return 8008135; // for now, could change later
            firstPos = false;
        } // end first number position
        else
        {
            int number = 9; // start at 9 and work way down
            ull decimalPos = it->first;

            while(number >= 0)
            {
                if(s.count(number)) --number;
                else{
                    ans += decimalPos * number;
                    break; // get outta while loop
                }
            }
            if(number == -1) return 8008135; // no smauller number
        }
    } // end for loop iteration
    return ans;
}

ull findBigNumber(map<ull,int,greater<int>> m, set<int> s)
{
    ull ans = 0;
    bool firstPos = true;

    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(firstPos)
        {
            int number = it->second;
            ull decimalPos = it->first;

            if(number == 9)
            {
                decimalPos *= 10;
                number = 1;
            }
            //
            if(number==0 && decimalPos == 1)
            {
                return 1;
            }

            while(number <= 9) 
            {
            //  if(s.count(++number)) continue;
                if(s.count(number)) ++number; // continue
                else // add to ans
                {
                    ans += decimalPos * number;
                    break; // get out of while loop
                }
            }
            // add later
            // if(number = it->second) return 8008135; // for now, could change later
            firstPos = false;
        } // end first number position
        else
        {
            int number = 0; // start at 0 and work way up
            ull decimalPos = it->first;

            while(number >= 0)
            {
                if(s.count(number)) ++number;
                else{
                    ans += decimalPos * number;
                    break; // get outta while loop
                }
            }
            if(number == 10) return 8008135; // no number bigger than 10
        }
    } // end for loop iteration
    if(ans >= MAX) return 8008135;
    return ans;
}

int main()
{
    ull Y = 0;
    cin >> Y;

    ull temp = Y;

    bool arr[10] = {false};
    set<int> s;
    map<ull,int,greater<int>> m;
    ull dec = 1;

    while(temp != 0)
    {
        m[dec] = temp % 10;
        s.insert(temp% 10);
        temp /= 10;
        dec *= 10;
    }
   
   if(Y == 0)
   {
       cout << "1" <<endl;
       return 0;
   }

    ull smallNum = findsmallNum(m,s), bigNum = findBigNumber(m,s);

    //cout << "smallNum: " << smallNum << endl << "bigNum : " << bigNum << endl;

    if(smallNum == 8008135 && bigNum == 8008135) cout <<  "Impossible" << endl;
    else if(Y - smallNum == bigNum - Y) cout << smallNum << " " << bigNum << endl;
    else if(Y - smallNum < bigNum - Y) cout << smallNum << endl;
    else {
        cout << bigNum << endl;
    }
   return 0;
}
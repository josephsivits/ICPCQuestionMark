#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& v, int target);

int main() {
    vector<int> a = {2,7,11,15};
    int t = 9;

    vector<int> b = twoSum(a,t);
    for(auto i : b) cout << i << " ";
    cout << endl;

    return 0;
}

vector<int> twoSum(vector<int>& v, int target)
{
    vector<int> previousNumbers;
    set<int> sPrev;
    
    for(int i = 0; i < v.size(); i++)
    {
        int currentNumber = v[i];
        int neededNumber = target - currentNumber;
        if(sPrev.find(neededNumber) != sPrev.end()) {
            vector<int> ans = {currentNumber, neededNumber};
            return ans;
        } else {
            sPrev.insert(currentNumber);
        }
    } // if reaching the end of this, return that
    return previousNumbers;
}
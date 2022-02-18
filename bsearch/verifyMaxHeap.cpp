#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>&); // function protototype

int main()
{
    vector<int> nums = {1,1,3,0};
    cout << solve(nums) << endl;

    return 0;
}


bool solve(vector<int>& nums) {
    int size = nums.size(), i_range = nums.size() / 2;
    // if size is greaterthan equal to 3 and an odd number, flag is true
    bool flag = (size >= 3 && size % 2 == 1) ? true : false;

    if (size == 0 || size == 1)
        return true;

    else {
        if (flag) {
            cout << "ODD NUMBER SIZE\n";
            for (int i = 0; i < i_range; i++) {
                if (nums[i] < nums[(2 * i) + 1] || nums[i] < nums[(2 * i) + 2]) return false;
            }
            return true;
        } else {
            cout << "EVEN NUMBER SIZE\n";
            for (int i = 0; i < i_range; i++) {
                if (nums[i] < nums[(2 * i) + 1]) {
                    return false;
                }
            }
            return true;
        }
        // reaching this base case because
        return false;
    }
    return false;
}

/*
    // max heap pattern

    [i]                 size = 1    i = 0,      true always
    [i,r]               size = 2    i = 0 r = 1
    [i,r,s]             size = 3    i = 0 r = 1 s = 2
    [0,i,0,r]           size = 4    i = 1 r = 3
    [0,i,0,r,s]         size = 5    i = 1 r = 3 s = 4
    [0,0,i,0,0,r]       size = 6    i = 2 r = 5
    [0,0,0,i,0,0,0,r]   size = 8    i = 4 r = 7
                        size = 10   i = 5 r = 11 +

    (A) check modulus for r /\ (r + s)
        size() >= 3 && size%2 == 1
    (B) run to in range of size()/2
    (B) check where statement is checked
                                    i = size-1/2
                                    r = i * 2 + 1

    */
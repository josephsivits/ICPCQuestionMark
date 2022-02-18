#include <bits/stdc++.h>
using namespace std;

int countFactZeros(int);

unsigned long long int findFact(int);

int main() {
    cout << "Enter number to calculate the number of trailing zerious by continuously dividing by ten.\n? ";
    int fact = 0;
    cin >> fact;

    cout << fact << "!  = " << findFact(fact) << " : " << countFactZeros(fact) << endl;

    return 0;
}

int countFactZeros(int num) {
    int count = 0;
    if(num < 0) {
        return -1;
    } 
    for(int i = 5; (num / i) > 0; i *= 5)  { 
        count += num / i;
    }
    return count;
}

/*
This method works up to 65!, which is  9223372036854775808 (incorrect)
maximum for unsigned long long int is 18446744073709551615
                        66! is        544344939077443064003729240247842752644293064388798874532860126869671081148416000000000000000
                                   == 5.443E92

Future work would be fixing this issue for obsurdly large numbers
*/
unsigned long long int findFact(int f) {
    unsigned long long int ans = 1; // unsigned can have zero, that's cool
    for(int i = 1; i <= f; i++) {
        ans *= i;
    }
    return ans;
}
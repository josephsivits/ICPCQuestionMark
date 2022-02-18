#include <bits/stdc++.h> // C++ mother library, don't use this its pretty bad practice lul
using namespace std;

int main() {
    double x, x2, y, yi, integration, error, analytical,step,xi;
    int n,i;

    analytical = 14/log(15);
    integration = 0;
    n = 2;
    x = 0;
    x2= 1;
    /* unused variable
    y = pow(15,x);
    yi= pow(15,x2);
    */

    cout << left << setw(15) << "N" << setw(15) << "Integration" << setw(15) << "Error" << endl; // this is just C++ i/o, ignore this
    for(n=2;n<=513;) {
        xi=0;
        // converting n to a double to use in arithmetic operations in line 25
        double nDouble = static_cast<double>(n);
        // best practice to step out of scope of for-loop so it can be used in line 35, also does not need to be repeated per iteration of i
        step = (1/(nDouble-1));

        for(i=1;i<=n-1;i++) {
            // converting i to a double so it can be used in artihmetic in line 30
            double iDouble = static_cast<double>(i);
            xi = x+(iDouble*step); // added parenthesis to enforce order of ops
            integration += pow(15,x) + pow(15,xi); // integration here could be wrong, did += instead if integraiton = integration + ... (to clean up code a bit)
            x = xi;
        }

        integration *= (step/2); // same thing as before, cleaning up code a bit
        error = abs((integration-analytical)/analytical) *100;

        cout << left << fixed<<setprecision(7) << setw(15) << n << setw(15) << integration << setw(15) << error <<endl; // some more c++ I/O, ignore this
        integration = 0;
        x = 0;
        n = n * 2 - 1;
    }
    return 0;
}
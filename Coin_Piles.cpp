#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int tc;
    cin >> tc;
    while(tc--) {
         long double a, b;

       cin >> a >> b;
              long double x = (2*a - b)/3.0;
       long double y = (2*b - a)/3.0;
       cout << (x == (long long int)x && y == (long long int)y && x >= 0 && y >= 0? "YES\n" : "NO\n"); 
    }
}
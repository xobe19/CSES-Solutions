#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int main() {
    long long int a;
    cin >> a;
    a--;
    int answ = 2;
   while(a >0) {
       answ = (answ * 2) % mod;
       a--;
   }
   cout << fixed << setprecision(0) << answ;
}
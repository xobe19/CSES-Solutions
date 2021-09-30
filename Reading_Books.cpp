#include <bits/stdc++.h>
using  namespace std;

int main() {
 int n; cin >> n;
 unsigned long long sum = 0;
 long long int maxi = 0;
 for(int i = 0; i < n; i++) {
     long long int t; cin >> t;
    maxi = max(t, maxi);
     sum += t;
 }
 sum -= maxi;
 if(maxi > sum) {
     cout << 2 * maxi;
 }
 else cout << maxi + sum;

}
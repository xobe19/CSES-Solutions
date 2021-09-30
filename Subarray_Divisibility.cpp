#include <bits/stdc++.h>
using namespace std;
 int main() {
    long long int n; cin >> n;
    map<long long int, long long int> s;
    s[0] = 1;
    long long int ans = 0;
    long long int cs = 0;
    for(long long int i = 0; i < n ;i++) {
        long long int t; cin >> t;
       cs += t; 
       long long int cm = cs%n;
        cm = cm < 0 ? n + cm : cm;
       ans += s[cm];
       s[cm]++;
    }
    cout << ans;
}
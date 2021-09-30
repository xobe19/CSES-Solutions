#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    long long int n; cin >> n;
    ll cs = INT_MIN;
    ll ms = INT_MIN;
    for(ll i = 0; i < n; i++) {
        ll t; cin >> t;
    cs = max(cs + t, t);
        ms = max(cs, ms);
    }

cout << ms;
}
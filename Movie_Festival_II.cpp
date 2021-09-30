#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >>  k;
    int answ = 0;
    set<array<int, 2>> ending;
    set<array<int, 3> > sorted;
    for(int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        sorted.insert({b,  a, i});
    }
    for(auto&x:sorted) {
        int st = x[1], en = x[0];
        auto it = ending.upper_bound({st, INT_MAX});
        if(it != ending.begin()) {
             it--; 
             answ++;
             ending.insert({en, x[2]});
           ending.erase(it);
        }
        else {
           if(k > 0) {
               k--;
               answ++;
               ending.insert({en, x[2]});
           }
        }
    }
    cout << answ;
}
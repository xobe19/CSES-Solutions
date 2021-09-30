#include <bits/stdc++.h>
using namespace std;

 int main() {
     int n;
     cin >> n;
     map<int, int> w;
     for(int i  =  0; i < n; i++) {
            int a; int b;
            cin >> a >> b;
            w.insert({a, 1});
            w.insert({b, -1});
     }
     int cc = 0;
     int mc = 0;
     for(auto &x : w) {
       cc += x.second;
       mc = max(cc, mc);
     }
     cout << mc;
}







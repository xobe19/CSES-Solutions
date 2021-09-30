#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<vector<int>> data;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        data.insert({t, i});
    }
    while(m--) {
        int t; cin >> t;
       auto it = data.lower_bound({t+1,0});
        if(it == data.begin())  {
            cout << "-1\n";
        }
        else {
            it--;
            cout << (*it)[0] << "\n";
            data.erase(it);
        }
    }
}
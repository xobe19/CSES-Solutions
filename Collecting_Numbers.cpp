#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
cin >> n;
map<int, int> data;
for(int i = 0; i < n; i++) {
    int t; cin >> t;
    data.insert({t, i});
} 

int prev = -1;
int rounds = 0;

for(auto x : data) {
    if(x.second > prev) {
       prev = x.second;
    }
    else {
        rounds++;
        prev = x.second; 
    }
}
cout << rounds + 1;


}
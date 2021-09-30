#include <bits/stdc++.h>
using namespace std;

int main() {
long long int ans = 0;
map<long long int,long long int> prefix;
long long int n, k; cin >> n >> k;
prefix[0] = k == 0 ? 0 : 1;
long long int cs = 0;
for(long long int i = 0; i < n; i++) {
long long int t; cin >> t;
cs += t;
prefix[cs]++;
ans += prefix[cs - k];

}
cout << ans;
}
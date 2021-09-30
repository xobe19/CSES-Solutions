#include <bits/stdc++.h>
using namespace std;
long long int**dp;
const long long int mod = 1e9 + 7;
   int main() {
    long long int tc;
cin >> tc;
long long int tcs[tc];
long long int m_tc = 0;
for(long long int i = 0; i < tc; i++) {
 cin >> tcs[i];
 m_tc = max(tcs[i], m_tc);
}
long long int n = m_tc;
dp = new long long int*[n+1];
for(long long int i = 0; i < n+1; ++i) {
dp[i] = new long long int[2];
}
dp[1][0] = 1;
dp[1][1] = 1;

for(long long int i = 2; i< n+1; i++) {
dp[i][0] = 4 * (( dp[i-1][0] )%mod)+ dp[i-1][1];
dp[i][0] %= mod;
dp[i][1] = 2 * ((dp[i-1][1])%mod) + dp[i-1][0];
dp[i][1] %= mod;
}
for(long long int i = 0; i < tc; i++) {
    cout <<(( dp[tcs[i]][0]  + dp[tcs[i]][1] ) % mod )<<  "\n";

}
}
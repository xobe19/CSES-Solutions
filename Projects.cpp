#include <bits/stdc++.h>
using namespace std;

  int main() {
    long long int n; cin >> n;
   vector<array<long long int, 3> > inp(n); 
    // array<long long int, 3> inp[n];    
    for(long long int i = 0; i < n; i++) {
        long long int a, b, c; cin >> a >> b >> c;
        inp[i] = {a, b, c};
    }
    sort(inp.begin(), inp.end());
   long long int dp[n];
   long long int mx_dp[n];
    dp[n-1] = inp[n-1][2]; 
    mx_dp[n-1] = inp[n-1][2];
    long long int max_dp = inp[n-1][2];
    for(long long int i = n-2; i >= 0; i--) {
       array<long long int,3> ts = {inp[i][1] + 1, 0, 0}; 
         auto lb = lower_bound(inp.begin()+i+1, inp.end(), ts);
         long long int a = inp[i][2]; 
          long long int indx_lb = lb - inp.begin();
         long long int mx_a = indx_lb >= n ? 0 : mx_dp[indx_lb];
        //  for(auto it = lb ; it != inp.end(); it++) {
        //     long long int indx_lb = it-inp.begin();
        //     mx_a = max(mx_a, dp[indx_lb]); 
        //  }
         dp[i] = a + mx_a;

         max_dp = max(dp[i], max_dp);
         mx_dp[i] = max_dp;
    }
    cout << max_dp;
}
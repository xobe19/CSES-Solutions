#include <bits/stdc++.h>
using namespace std;
 int mod = 1e9 + 7;
  int main() {
     int n, k; cin >> n >> k;
         int* dp = new int[k+1];
   for(long long int i = 0; i <= k; i++) {
     dp[i] = 0;
   }
   dp[0] = 1;
     int arr[n];
  //  for(long long int i = 0; i < n; i++) {
  //    cin >> arr[i];
  //  }
   for(long long int i = 0; i < n; i++) {
     cin >> arr[i];
     for(long long int j = 0; j < k + 1; j++) {
       if(j - arr[i] < 0) continue;
       dp[j] += dp[j - arr[i]]; 
       dp[j]%=mod;
      //  if(dp[j] > mod) {
      //    dp[j]%=mod;
      //  }
     }
    //  for(int j = k ; j >= 0; j--) {
    //    if(dp[j] > mod) {
    //      dp[j]%=mod;
    //    }
    //    else break;
    //  }
   }
     int answ = dp[k]%mod;
   cout << answ;
  //  cout << (answ < 0 ? answ + mod : answ);
}
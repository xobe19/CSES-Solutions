#include <bits/stdc++.h>
using namespace std;

  int main() {
    long long int n; cin >> n;
    long long int arr[n];
    long long int cs[n];
    long long int sum = 0;
    for(long long int i = 0; i < n; i++) {
      cin >> arr[i];

 sum += arr[i];
 cs[i] = sum;
    }
    long long int** dp = new long long int*[n];
    for(long long int i = 0; i < n; i++) {
        dp[i] = new long long int[n];
        for(long long int j = 0; j < n  ;j++) {
            if(i == j) {
                dp[i][j] = arr[i]; 
            }
            else dp[i][j] = 0;
        }
    }

for(long long int i = n -1 ; i >= 0; i--) {
    for(long long int j = 0; j < n; j++) {
        if(i<j)
        dp[i][j] = max(arr[i] + cs[j] - (i >= 0 ? cs[i] : 0) - (i < n ? dp[i+1][j] : 0), arr[j] + (j >= 1 ? cs[j-1] : 0) - (i >= 1 ? cs[i-1]: 0) - ( j >= 1 ? dp[i][j-1] : 0));
    }
}

cout << dp[0][n-1];

}
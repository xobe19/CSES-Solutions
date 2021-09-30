#include <bits/stdc++.h>
using namespace std;


const int mod = 1e9 + 7;

int n, m;
int**dp;
int* inp;
int main() {
cin >> n >> m;
dp = new int*[n];
inp = new int[n];
for(int i = 0; i < n; i++) {
    cin >> inp[i];
}
for(int i = 0; i < n; i++) {
    dp[i] = new int[m+1];
    
}
if(inp[0] == 0) {
for(int j = 1; j <= m; j++) {
    
    dp[0][j] = 1;
}
dp[0][0] = 0;
}
else {
    for(int j = 0; j <= m; j++) {
        if(inp[0] == j) dp[0][j] = 1;
        else dp[0][j] = 0;
    }
}
for(int i = 1; i < n; i++) {
    if(inp[i] == 0) {
    for(int j = 1; j <= m; j++) {
          dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] ) % mod+ (j + 1 <= m ? dp[i-1][j+1] : 0); 
          dp[i][j] %= mod;
    }
    dp[i][0] = 0;
    }
    else {
        for(int j = 1; j <= m; j++) {
             if(inp[i] == j) {
           dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod + (j + 1 <= m ? dp[i-1][j+1] : 0); 
          dp[i][j] %= mod;
          
             }
             else {
                 dp[i][j] = 0;
             }
        }
        dp[i][0] = 0;
    }
}
int s = 0;
for(int i = 0; i <= m; i++) {
    s += dp[n-1][i];
    s %= mod;
}
cout << s;
}
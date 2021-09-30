#include <bits/stdc++.h>
using namespace std;

int**dp;


int main() {
int a, b;
cin >> a  >> b;
dp = new int*[a+1];
for(int i = 1; i < a + 1; i++) {
    dp[i] = new int[b+1];
    if(i < b + 1) dp[i][i] = 0;
}


for(int i = 1; i < a + 1; i++) {
    for(int j = 1; j < b + 1; j++) {
        // cout << i << " " << j << endl;
       if(i != j) {
           int answ_h = INT_MAX;
           for(int s = 1; s < j; s++) {
               answ_h = min(answ_h, dp[i][s] + dp[i][j-s]);
           }
           int answ_v = INT_MAX;
           for(int s = 1; s < i; s++) {
              answ_v = min(answ_v, dp[s][j] + dp[i-s][j]);
           }
           dp[i][j] = min(answ_h, answ_v) + 1;
       } 
    }
}

cout << dp[a][b];



}
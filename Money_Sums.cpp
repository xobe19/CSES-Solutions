#include <bits/stdc++.h>
using namespace std;
bool*dp;

int main() {
 int n;
 cin >> n;
 int s = 0;
 int arr[n];
 int ff = 0;
for(int i = 0; i < n; i++) {
    cin >> arr[i];
    s += arr[i];
}
dp = new bool[s+1];
for(int i = 0; i < s + 1 ; i++) dp[i] = false;
dp[0] = true;
for(int j = 0; j < n; j++) {

    bool ss = false;
    for(int k = s; k >= 0; k--) {
        if(dp[k]) continue;
        if(k - arr[j] >= 0) {
            ss = dp[k -arr[j]];
            if(ss) {
               ff++; 
                dp[k] = true;
            } 
        }
    }
}
cout << ff << "\n";
for(int i = 1; i < s + 1; i++) {
    if(dp[i]) cout << i << " ";
}





}
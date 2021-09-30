#include <bits/stdc++.h>
using namespace std;

int*prices;
int*pages;
int n, k;
int**mem;
int*dp;

int f(int max_cost, int size) {
    if(max_cost <= 0 || size <= 0) return 0;
    if(mem[max_cost][size] != -1) return mem[max_cost][size];
    int first_indx = n-size;
    int pgs = 0;
    if(prices[first_indx] > max_cost) {
        pgs = f(max_cost, size-1);
    } 
    else {
        pgs = max(f(max_cost, size-1), pages[first_indx] + f(max_cost-prices[first_indx], size-1));
    }
    mem[max_cost][size] = pgs;
    return pgs;
}

int main() {
    cin >> n >> k;
    prices = new int[n];
    pages = new int[n];
    dp = new int[k+1];
    for(int i = 0; i <= k; i++) {
        dp[i] = 0;
    }
    for(int i = 0; i < n; i++) {

        cin >> prices[i];
    }
  for(int i = 0; i < n; i++) {
        cin >> pages[i];
    }

   for(int j = 1;  j < n + 1; j++) {
       for(int i = k; i >= 0; i--) {
           int first_indx = n-j;
           if(prices[first_indx] > i) {
           }
           else {
               dp[i] = max(dp[i], pages[first_indx] + dp[i-prices[first_indx]]);
           }
       }
   } 
        // for(int i = 1; i < k + 1 ; i++) {
            
        //     for(int j = 1; j < n + 1; j++) {
        //         int first_indx = n - j;
        //         if(prices[first_indx] > i) {
        //             mem[i][j] = mem[i][j-1];
        //         }
        //         else {
        //             mem[i][j] = max(mem[i][j-1], pages[first_indx] + mem[i-prices[first_indx]][j-1]);
        //         }
        //     }
        // }

//    cout << mem[k][n]; 
cout << dp[k];
}
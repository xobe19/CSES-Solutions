#include <bits/stdc++.h>
using namespace std;
int n, x;
int**mem;
array<int, 2>*dp;
int*arr;
int f(int k , int curr_set) {
// cout << k << " " << curr_set << endl;
if(curr_set == 0) {
    return 1;
}

if(mem[curr_set][k] != -1) return mem[curr_set][k];
int glbl =    INT_MAX;
for(int i = 0; i < n; i++) {
    // if ith element in inside curr_set
    int answ =    INT_MAX;
    if(curr_set&(1<<i)) {
      if(k + arr[i] < x) {
        answ = f(k+arr[i], curr_set&~(1<<i)); 
      }
    //   else if(k + arr[i] == x) {
    //       answ = 1 + f(0, curr_set&!(1<<i));
    //   }
      else {
          answ = 1 + f(k+arr[i]-x, curr_set&~(1<<i));
      }
glbl = min(answ, glbl);
    }
}

 mem[curr_set][k] = glbl;
 return glbl;


}


   int main() {
   cin >> n >> x; 
  //  mem = new int*[(1<<n)];
  //  for(int i = 0; i < 1<<n; i++) {
  //   mem[i] = new int[x];
  //   for(int j = 0; j < x; j++) {
  //       mem[i][j] = -1; 
  //   }
  //  }
   arr = new int[n];
   for(int i = 0; i < n; i++) cin >> arr[i];
    dp = new array<int, 2>[1<<n];
   dp[0] = {1, 0}; 
   for(int i = 1; i < (1<<n); i++) {
     int glbl =  INT_MAX;
     int glbl_b;
     for(int j = 0; j < n; j++){
      if(i&(1<<j)) {
  int answ =  INT_MAX ;
       int weight = arr[j];      
      
         auto& p = dp[i&~(1<<j)];
         if(p[1] + arr[j] <= x) {weight = p[1]+arr[j]; 
        answ = p[0]; 
         }
         else {
           weight =  arr[j];
           answ = p[0] + 1;
         }
      if(glbl > answ) {
        glbl = answ;
        glbl_b = weight;
      } 
      if(glbl == answ) {
        if(glbl_b > weight) {
          glbl_b = weight;
        }
      }
       }

     }

     dp[i] = {glbl, glbl_b};
   }



// cout << dp[(1<<n)-2][0] << endl;
   cout << dp[(1<<n)-1][0]; 
}
#include <bits/stdc++.h>
using  namespace std;

int main() {
    int tc; cin>>tc;
    cout << fixed;
    cout << setprecision(0);
    while(tc--) {
        unsigned long  long int i; unsigned long long int j;
        cin >> i >> j;
        unsigned long long int curr_sq = max(i, j);
        unsigned long long prev_sq  = curr_sq-1;
        if(curr_sq%2==0){



      unsigned long long int diff = curr_sq + prev_sq;
     unsigned long long int by2 = diff/2;
     by2++;
     if(curr_sq == i) {
          unsigned long long int d = i-j;
       cout << powl(prev_sq, 2) + d + by2 << endl;
     }
     else{
         cout << powl(prev_sq, 2) + i << endl;
     }


        } 
        
        else{
      swap(i, j);




       unsigned long long int diff = curr_sq + prev_sq;
      unsigned long long int by2 = diff/2;
     by2++;
     if(curr_sq == i) {
          unsigned long long int d = i-j;
       cout << powl(prev_sq, 2) + d + by2 << endl;
     }
     else{
         cout << powl(prev_sq, 2) + i << endl;
     }



        }
    }
}
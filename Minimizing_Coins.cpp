#include <bits/stdc++.h>
using namespace std;
long long int*m;
long long int f(long long int*arr, long long int n, int size) {
if(n < 0) return INT_MAX;
if (n == 0) return 0;
if(m[n] != -1) return m[n];
long long int ans = INT_MAX;
for(long long int i = 0; i < size; i++) {
   ans = min(ans, f(arr,n-arr[i],size)); 
}
m[n] = 1 + ans;

return m[n];


}

  int main() {
    long long int n, k; cin >> n >> k;
    long long int arr[n];
    m = new long long int[k+1];
     for(long long int i = 0; i < n; i++) {
         cin >>  arr[i];
     }
     for(long long int i = 0; i < k + 1; i++) {
         m[i] = -1;
     }

     long long int answ =  f(arr, k, n);
     cout << (answ >= INT_MAX ? -1 : answ);

}
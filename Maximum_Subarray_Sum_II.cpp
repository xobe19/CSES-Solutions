#include <bits/stdc++.h>
using namespace std;


int main() {
    long long int n, a, b; cin >> n >> a >> b;
    long long int arr[n];
    long long int pfx[n];
    long long int s = 0;
    for(long long int i = 0; i < n; i++) {
        cin >> arr[i];
         s += arr[i];
         pfx[i] = s;
    }
    set<long long int> pfx_j;
 for(long long int i = a; i <= b && i <= n; i++){
     pfx_j.insert(pfx[i-1]);
 }     
 auto en = pfx_j.end();
en--;
long long int mx = *en;

    for(long long int i = 1; i <= n; i++) {
       pfx_j.erase(pfx[a+i-1-1]); 
     if(b + i - 1< n)   pfx_j.insert(pfx[b+i-1]);
       en = pfx_j.end();
       if(pfx_j.empty()) break;
       en--;
         mx = max(mx, *en - pfx[i-1]);
    }
    cout << mx;
}
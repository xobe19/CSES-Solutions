#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n, k; cin >> n >> k;
    long long int arr[n];
    for(long long int i = 0; i< n;i++) {
        cin >> arr[i];
    }
    map<long long int, long long int> seen;
    long long int s = 0, e = 0;
long long int ans = 0;    
    while(e < n) {
      //  cout << s << " " << e << " " << seen.size() << endl;;
       if(seen.count(arr[e]) > 0) {
           seen[arr[e]]++;
        ans++;
        //    if(s!=e) {
        //        ans++;
        //    }
  ans += e-s;
           e++;
       }  
       else if(seen.size() < k) {

ans++;
seen[arr[e]]++;
          //seen.insert(arr[e]); 
        //  if(s!=e) {
        //      ans++;
        //  } 
        ans += e-s;
          e++;

       }
       else {
           seen[arr[s]]--;
           if(!seen[arr[s]]) seen.erase(arr[s]);
        //seen.erase(seen.find(arr[s]));
        s++;

       }
    }
    // e = n-1;
    // s++;
    // ans += e-s;
   cout << ans;
}
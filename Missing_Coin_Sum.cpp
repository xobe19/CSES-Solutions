#include <bits/stdc++.h>
using namespace std;

  int main() {

long long int n; cin >> n;
long long int a[n];
for(long long int i = 0; i < n; i++) {
    cin >> a[i];
}
sort(a, a +n);
if(a[0] > 1) {
    cout << 1;
    return 0;
} 
long long int ans = a[0];
for(long long int i = 1; i < n; i++) {
    if(a[i] > ans + 1) {
      cout << ans + 1; 
      return 0;
    }
    ans = ans + a[i];
}
cout << ans + 1;
}
#include <bits/stdc++.h>
using namespace std;

bool valid(long long int x,long long int* p, long long int k, long long int n) {
    long long int ans = 0;
    for(long long int i = 0; i < n; i++) {
        long long int y = p[i];
        ans += (x/y);
    }
    return ans >= k;
}

long long int bs(long long int a, long long int b,long long int k ,long long int*p,long long int n) {
    if(a == b) {
        return a;
    }
long long int mid = (a + b)/2;
if(valid(mid, p, k, n)) {
    return bs(a, mid,k, p, n);
}
else {
    return bs(mid+1,b,k, p, n);
}
}
int main() {
    long long int n, k; cin >> n >> k;
    long long int min_v = LLONG_MAX;
    long long int p[n];
    for(long long int i = 0; i < n; i++) {
       cin >> p[i];
       min_v = std::min(p[i], min_v);
    }
    long long int z = min_v * k;
    cout << bs(1, z,k , p, n);
}
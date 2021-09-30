#include <bits/stdc++.h>
using namespace std;
int*m;
int f(int n) {
    if( n < 0) return 0;
if(n == 0) return 1;

    if(m[n] != -1) return m[n];
int ans = 0;
for(int i = 1; i <= 6; i++) {
ans += f(n-i);
ans %= 1000000007;
}
ans %= 1000000007;
m[n] = ans;

return ans;
}


int main() {

int n; cin >> n; 
m = new int[n+1];
for(int i = 0; i < n+1; i++) {
m[i] = -1;
}


cout <<f(n);

}
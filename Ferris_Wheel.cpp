#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
 int n,x; cin >> n >> x;
 int arr[n];
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}

sort(arr, arr+n);
int ans= 0;
int i = 0;
int j = n-1;
while(i <= j) {
    if(i == j) {
        ans++;
        break;
    }
    if(arr[i] + arr[j] <= x) {
        ans++;
        i++;
        j--;
    }
    else {
        ans++;
        j--;
    }
}
cout << ans;
}
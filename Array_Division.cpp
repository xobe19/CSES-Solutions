#include <bits/stdc++.h>
using namespace std;

bool valid(long long int a, long long int*arr,long long int n ,long long int k) {
long long int p_left = k-1;
long long int cs = 0;
for(long long int i = 0; i < n; i++) {
cs += arr[i];
if(cs > a) {
if(p_left == 0) return false;
p_left--;
cs = arr[i];
}
}
return true;
}

 int main() {
long long int n,k; cin >> n >> k;
long long int lb = 0;
long long int ub = 0;
long long int arr[n];
for(long long int i = 0; i < n; i++) {
    cin >> arr[i];
    lb = max(lb, arr[i]);
    ub += arr[i];
}
while(lb < ub) {
    long long int mid = (lb + ub)/2;
    if(valid(mid, arr, n, k)) {
         ub = mid;
    }
    else {
        lb = mid+1;
    }
}
cout << lb;


}
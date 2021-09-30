#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n>> k;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
int count = 0;
    int s = 0, e = 0;
    int cs = arr[0];
    while(e < n) {
       if(cs == k) {
    count++; 

    cs -= arr[s];
    s++;
       } 
       else if(cs > k) {

           cs -= arr[s];
           s++;
       }
       else {
           e++;
           cs += arr[e];
       }
    }
    cout << count;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int*arr;
    int n; cin >> n;
    arr = new int[n+1];
    arr[0] = 0;
    for(int i = 1; i < 10; i++) {
        arr[i] = 1;
    }
    for(int i = 10; i <= n; i++) {
      string digs = to_string(i);
      int mi = INT_MAX; 
      for(char x : digs) {
          if(x != '0') 
          mi = min(mi, 1 + arr[i - x + '0']);
      }
      arr[i] = mi;
    }
    cout << arr[n];
}
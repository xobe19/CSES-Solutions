#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    vector<int> c;
    cin >> arr[0];
    c.push_back(arr[0]);
  for(int i = 1; i < n; i++) {
      cin >> arr[i];
     if(arr[i] > c[c.size()-1])  {
         c.push_back(arr[i]);
     }
     else {
         auto it = lower_bound(c.begin(), c.end(), arr[i]);
         *it = arr[i];
     }



  }
  cout << c.size();

  
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n;
    vector<int> inp;
  while(n--) {
      long long int t; cin >> t;
      inp.push_back(t);
  }
  long long int score = 0;
  for(long long int i = 1; i < inp.size();i++) {
    if(inp[i] < inp[i-1]) {
        score += (inp[i-1] - inp[i]);
        inp[i] = inp[i-1];
    }
  }
  cout <<  score;
}
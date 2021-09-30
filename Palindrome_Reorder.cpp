#include <bits/stdc++.h>
using namespace std;

int main() {
    string inp;
    cin >> inp;
  unordered_map<char, int> freq;
  for(char x: inp) {
   freq[x]++;
  }
   int odd = 0;
   string odd_one;
   string a;
   string b;
  for(auto&x:freq) {
   if(odd > 1) {
       cout << "NO SOLUTION";
       return 0;
   }
   else {
  if(x.second % 2) {

  while(x.second) {
     odd_one += x.first;
     x.second--;
    }
odd++;

  }
  else {
   int times = x.second/2;
   while(times--) {
       a+=x.first;
   }
   

  }
     }



  }

if(odd > 1) {cout << "NO SOLUTION"; return 0;}

cout << a << odd_one;
for(auto it = a.rbegin(); it < a.rend(); it++) {
    cout << *it;
}

  



}
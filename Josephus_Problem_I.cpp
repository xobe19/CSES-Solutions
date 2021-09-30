#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
  set<int> s;
  for(int i = 1; i <= n; i++) {
   s.insert(i);
  }
bool first = false;
  while(!s.empty()) {

      if(s.size() == 1) {
          cout << *s.begin() << " ";
          break;
      }
      else {
    auto it = s.begin();
    if(!first) it++;       
         while(true) {

            if(it == s.end()) break;
            auto e = it;
            cout << *it << " ";
            it++;
            if(it == s.end()) {
                first = false;
             s.erase(e);
                break;
            }
            it++;
           if(it == s.end()) {
               first = true;
               s.erase(e);
               break;
           }
           s.erase(e);
         }






      }
  }







}
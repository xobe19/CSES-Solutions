#include <bits/stdc++.h>
using namespace std;
#define ar array
int* arr;

// unordered_map<int, vector<int>*> s;
vector<int>** s;
int st;

int calc(int ind, int st) {
        ind--;
        while(st--) {
          ind = arr[ind]-1;
        }
        return ind+1;

}


void succ(int y) {
  vector<int>* answ = new vector<int>(st);
  if(y == 0) {
      for(int i = 0; i < st; i++) {
        answ -> at(i) = arr[i];
      }
      s[y] = answ;
      return;
  }
  succ(y-1);
auto&prev = s[y-1];
for(int i = 0; i < st; i++) {
int stps = 1<<(y-1);
int orig = prev->at(i);
for(int i = 0; i <= 31; i++) {
  if(stps&(1<<i)) {
    orig = s[i]->at(orig-1);
  }
}

answ->at(i) = orig;
}
s[y] = answ;

}


int main() {
    int v, q; cin >> v >>q;
    st = v;
    arr = new int[v];
    for(int i = 0; i < v; i++) cin >> arr[i];
    vector<ar<int, 2>> queries(q);
    int mx_steps = INT_MIN;
    for(int i = 0; i < q; i++) {
       int a, b; cin >> a >> b; 
       queries[i] = {a, b};
       mx_steps = max(mx_steps, b);
    }
    int pw = 0;
    int last_pw = 0;
    for(; pw <= 31; pw++) {
      if(mx_steps&(1<<pw)) {
          last_pw = pw;
      }
    }

    s = new vector<int>*[last_pw+2];
    succ(last_pw+1);

    for(auto&y:queries) {
int stps = y[1];
int orig = y[0];
for(int i = 0; i <= 31; i++) {
  if(stps&(1<<i)) {
    orig = s[i]->at(orig-1);
  }
}
cout << orig << "\n";
    }



}
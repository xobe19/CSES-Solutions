#include <bits/stdc++.h>
using namespace std;
int my_mod(long long a, int b) {
    long long div = a/b;
    return a - (div*b);
}

void circularNext(list<int> &l, list<int>::iterator &it)
{
    it = std::next(it) == l.end() ? l.begin() : std::next(it);
}

int main() {
long long int n, k; cin >> n >> k;
list<int> l;
for(int i = 1; i<=n; i++) {
    l.push_back(i);
}
int lu = my_mod(k, n);
auto it = l.begin(); 
int indx = 0;
for(int i = 0; i < lu; i++) {
    indx++;
    circularNext(l, it);
}
while(!l.empty()) {
    cout << *it << " ";
    auto e = it;
    circularNext(l, it);
    l.erase(e);
    if(l.empty()) break;
    lu = my_mod(k, l.size());
    //cout << lu  << " " << indx << endl;
   if(indx + lu >= l.size()) {
  int indd = indx;
  indx = my_mod(indx+lu, l.size());
         int moves = l.size() - indd;
         lu = lu-moves;
         it = l.begin();

          } 
          else {
    indx = indx + lu;
          }
   for(int i = 0; i < lu; i++) {

        circularNext(l, it);
    }
}
}
#include <bits/stdc++.h>
using namespace std;
long long answ = LLONG_MAX;
long long a = 0;
long long b = 0; 
void f(vector<int>&inp, int processed) {
if(processed == inp.size()) {
   answ = min(answ, abs(a-b)); 
}
else {
    a += inp[processed]; 
    f(inp, processed+1);
    a -= inp[processed];
    b += inp[processed];
    f(inp, processed+1);
    b -= inp[processed];
}
}



int main() {
int n;
cin >> n;
vector<int> inp;
while(n--) {
    int t; cin >> t;
inp.push_back(t);
}
f(inp, 0);
cout << answ;
}
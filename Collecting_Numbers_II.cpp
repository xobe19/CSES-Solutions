#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
cin >> n >> m;
int data[n+1];
int inp[n];
for(int i = 0; i < n; i++) {
    int t; cin >> t;
    data[t] = i;
    inp[i] = t;
} 



int prev = -1;
int rounds = 0;

for(int i = 1; i < n+1; i++) {
    if(data[i]> prev) {
       prev = data[i];
    }
    else {
        rounds++;
        prev = data[i]; 
    }
}


while(m--) {

int i1, i2; cin >> i1 >> i2;
if(i1 == i2) {
    cout << rounds + 1 << "\n";
    continue;
}
int a = inp[i1-1] , b = inp[i2-1];
int x = min(a, b), y = max(a, b);
a = x; b = y;
if((b-a) == 1) {
if(a!=1) {
    rounds += (data[a-1] > data[a] == data[a-1] > data[b]) ? 0 : (data[a-1] > data[a] ? -1 : 1);
}
if(a!=n) {
rounds += (data[b] < data[a] ? -1 : 1);    
}

if(b!=n) {
    rounds += (data[b+1] > data[b] == data[b + 1] > data[a]) ? 0 : (data[b+1] > data[b] ? 1 : -1);
}
swap(inp[i1-1], inp[i2-1]);
swap(data[a], data[b]);
cout << rounds + 1 << "\n";
continue;


}




if(a!=1) {
    rounds += (data[a-1] > data[a] == data[a-1] > data[b]) ? 0 : (data[a-1] > data[a] ? -1 : 1);
}
if(a!=n) {
    rounds += (data[a+1] > data[a] == data[a+1] > data[b]) ? 0 : (data[a+1] > data[a] ? 1 : -1);
}


if(b!=1) {
    rounds += (data[b-1] > data[b] == data[b-1] > data[a]) ? 0 : (data[b-1] > data[b] ? -1 : 1);
}
if(b!=n) {
    rounds += (data[b+1] > data[b] == data[b + 1] > data[a]) ? 0 : (data[b+1] > data[b] ? 1 : -1);
}


swap(inp[i1-1], inp[i2-1]);
swap(data[a], data[b]);
cout << rounds + 1<< "\n";
}


}
#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
int* arr;
int max_comp_size = -1;
int num_comp;
DSU(int v) {
arr = new int[v+1];
num_comp = v;

for(int i = 1; i <= v; i++) arr[i] = -1;
}

int root(int x) {
   if(arr[x] < 0) return x;
   int answ = root(arr[x]);
   arr[x] = answ;
   return answ;
}

void join(int a, int b) {
int ra = root(a);
int rb = root(b);
if(ra == rb) {
    return;
}
if(arr[ra] < arr[rb]) {
    arr[ra] += arr[rb];
    max_comp_size = min(arr[ra], max_comp_size);
    arr[rb] = ra;

}
else {
    arr[rb] = arr[rb] + arr[ra];
    max_comp_size = min(arr[rb], max_comp_size);
    arr[ra] = rb;
}
num_comp--;
return;
}

};


int main() {
int v, e;
cin >> v >> e;
DSU dsu(v);
for(int i = 0; i < e; i++){
    int a,  b;
    cin >> a >> b;
    dsu.join(a, b);
    cout << dsu.num_comp << " " << -1*dsu.max_comp_size << "\n";
}

}
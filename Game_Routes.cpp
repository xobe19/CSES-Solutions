#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
vector<int>*graph;
int* mem;
int st;
int dfs(int x) {
if(mem[x] != -1) return mem[x];
int answ = 0;
for(auto&y:graph[x]) {
answ += dfs(y);
answ %= mod;
}
return mem[x] = answ;

}

int main() {
    int v, e; cin >> v >> e;

    graph = new vector<int>[v+1];
    mem = new int[v+1];
    for(int i =0; i <e; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i = 0; i < v; i++) {
        mem[i] = -1;
    }
    mem[v] = 1;

   cout << dfs(1);
    

}
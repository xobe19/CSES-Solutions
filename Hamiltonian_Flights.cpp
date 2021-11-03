#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long 
array<array<int, 1048577>, 21> mem;
vector<int>*graph;
int visited = 0;
int st;
int dfs(int x) {
if(visited&(1<<x)) return 0;
if(x == st && (1<<st) - visited == 2) return 1;
if(x == st) return 0;
if(mem[x][visited] != -1) return mem[x][visited];
int answ = 0;
visited ^= 1<<x;
for(int y: graph[x]) {
answ += dfs(y);
answ %= mod;
    }
visited ^= 1<<x;
return mem[x][visited] = answ;
}


int main() {
int v, e; cin >> v >> e;
st = v;
for(int i = 0; i < 21; i++) {
   for(int j = 0; j < 1048577; j++) {
       mem[i][j] = -1;
   } 
}
graph = new vector<int>[v+1];
for(int i = 0; i < e; i++) {
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
}

cout << dfs(1);


}
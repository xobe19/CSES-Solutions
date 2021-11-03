#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array



vector<int>*graph;
bool* visited;
int tf;
void cls() {
    for(int i = 0; i < tf+1; i++) {
      visited[i] = false;
    }
}
unordered_set<int> cycle;
bool should = false;

void dfs3(int x) {
    if(visited[x]) return;
    visited[x] = true;
if(cycle.find(x) == cycle.end()) {
for(auto&y:graph[x]) {
    dfs3(y);
}
}
else {
    cout << -1;
    exit(0);
}
}


void dfs(int x) {
    if(visited[x])  {
        cls();
        dfs3(1);
   return;
    }
    visited[x] = true;
    cycle.insert(x);
// if(x == tf) {
    
//     cout << -1;
//     exit(0);
// }
  for(auto& y: graph[x]) {
        dfs(y);
  } 
visited[x] = false;
cycle.erase(x);
}


void dfs2(int x) {
    if(visited[x]) return;
    visited[x] = true;
    if(x == tf) {
        should = true;
        return;
    }
    else {
        for(auto&y:graph[x]) {
            dfs2(y);
        }
    }
    visited[x] = false;
}
int main() {
int v, e; cin >> v >> e;
tf = v;
ar<int, 3> edges[e];
graph = new vector<int>[v+1];
for(int i = 0; i<e;i++) {
    int a, b, c; cin >> a >> b >> c;
    edges[i] = {a, b,c};
    graph[a].push_back(b);
}


ll distance[v+1];
for(int i = 1; i < v+1; i++) {
    distance[i] = LLONG_MIN;
}
distance[1] = 0;
for(int i = 0; i < v-1; i++) {
    for(int i = 0; i < e; i++) {
        ll u = edges[i][0], v = edges[i][1], w = edges[i][2];
        __int128_t sum = (__int128_t)distance[u] + w;
        if(distance[v] < sum) {
           distance[v] = sum; 

    //   cout << distance[u] << " " << w << " " << distance[v] << endl;
        }
    }
}
visited = new bool[v+1];
for(int i = 1; i < v+1; i++) {
    visited[i] = false;
}
for(int i = 0; i < e; i++) {
        ll u = edges[i][0], vv = edges[i][1], w = edges[i][2];
        if(distance[vv] < distance[u]+w) {
            should = false;
            // cout << vv << endl;
dfs2(vv);
if(should) {
    cls();
dfs(vv);
}
else break;

           distance[vv] = distance[u]+w; 
        }

}


cout << distance[v];




}
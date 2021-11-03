#include <bits/stdc++.h>
using namespace std;
vector<int>* graph;
bool* processed;
bool* loc;
vector<int> topo;
void dfs(int x) {
    if(!processed[x]) {
        processed[x] = true;
        loc[x] = true;
        for(auto&y:graph[x]) {
            if(loc[y]) {
                cout << "IMPOSSIBLE"; exit(0);
            }
            dfs(y);
        }
        loc[x] = false;
        topo.push_back(x);
    }
}


int main() {

int v, e; cin >> v >> e;
graph = new vector<int>[v+1];
processed = new bool[v+1];
loc = new bool[v+1];
for(int i = 0; i < e; i++) {
int a, b; cin >> a >> b;
graph[a].push_back(b);
}

for(int i = 1; i <=v ;i++) {
    loc[i] = false;
    processed[i] = false;
}
for(int i = 1; i <= v; i++) {
    if(!processed[i]) {
        dfs(i);
    }
}
int bgin = *topo.begin();
for(auto it = topo.rbegin(); it != topo.rend(); it++) cout << *it << " ";



}
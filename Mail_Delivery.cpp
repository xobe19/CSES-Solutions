#include <bits/stdc++.h>
using namespace std;

int total_edges = 0;
int vis_edges = 0;
unordered_set<int>*graph;

void remove_edge(int a, int b) {
graph[a].erase(b);
graph[b].erase(a);
}

vector<int> answ;

void dfs1(int x) {


while(!graph[x].empty()) {
auto it = graph[x].begin();
int y = *it;
graph[x].erase(it);
graph[y].erase(x);
vis_edges++;
dfs1(y);
}
answ.push_back(x);



}


int main() {
int v, e; 
cin >> v >> e;
total_edges = e;

graph = new unordered_set<int>[v+1];

for(int i = 0; i < e; i++) {
    int a, b; cin >> a >> b;
    graph[a].insert(b);
    graph[b].insert(a);
}

for(int i = 1; i<= v; i++) {
    if(graph[i].size()&1) {
        cout << "IMPOSSIBLE";
        exit(0);
    }
}

dfs1(1);
if(vis_edges != total_edges) {
    cout << "IMPOSSIBLE";
    exit(0);
}
for(auto it = answ.rbegin(); it != answ.rend(); it++) {
    cout << *it << " ";
}


}
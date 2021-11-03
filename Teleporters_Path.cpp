#include <bits/stdc++.h>
using namespace std;

int total_edges = 0;
int vis_edges = 0;
unordered_set<int>*graph;
int* in_degree;
int* out_degree;

vector<int> answ;

void dfs1(int x) {


while(!graph[x].empty()) {
auto it = graph[x].begin();
int y = *it;
graph[x].erase(it);
vis_edges++;
dfs1(y);
}
answ.push_back(x);



}


int main() {
int v, e; 
cin >> v >> e;
total_edges = e;
in_degree = new int[v+1];
out_degree = new int[v+1];
graph = new unordered_set<int>[v+1];
for(int i = 0; i <= v; i++) {
    in_degree[i] = 0;
    out_degree[i] = 0;
}
for(int i = 0; i < e; i++) {
    int a, b; cin >> a >> b;
     out_degree[a]++;
     in_degree[b]++;
    graph[a].insert(b);
}

if(in_degree[1]-out_degree[1] != -1) {
        cout << "IMPOSSIBLE";
        exit(0);

}
if(in_degree[v]-out_degree[v] != 1) {
            cout << "IMPOSSIBLE";
        exit(0);

}
for(int i = 2; i< v; i++) {
    if(in_degree[i] != out_degree[i]) {
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
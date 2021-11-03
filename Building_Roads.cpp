#include <bits/stdc++.h>
using namespace std;

vector<int> components;
vector<int>* graph;
bool* visited;
void dfs(int x) {
if(visited[x]) return;
visited[x] = true;
for(auto&y:graph[x]) {
dfs(y);
}

}

int main() {

int v, e; cin>>v>>e;
graph = new vector<int>[v+1];
visited = new bool[v+1];
for(int i = 1; i < v+1; i++) {
    visited[i] = false;
}
for(int i = 0; i < e; i++) {
    int a, b; cin >> a >> b;
    graph[a].push_back(b); graph[b].push_back(a);
}
for(int i = 1; i < v+1; i++) {
    if(!visited[i]) {
        dfs(i);
        components.push_back(i);
    }
}
cout << components.size() - 1<< "\n";
for(int i = 0; i < components.size()-1; i++) {
    cout << components[i] << " " << components[i+1] << "\n";
}


}
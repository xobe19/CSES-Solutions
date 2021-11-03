#include <bits/stdc++.h>
using namespace std;

bool* visited1;
bool* visited2;
vector<int>* graph;
vector<int>* rev_graph;
stack<int> s;
int st;
int* ans;

void dfs1(int x) {
    if(!visited1[x]) {
        visited1[x] = true;
        for(int y : graph[x]) {
            dfs1(y);
        }
        s.push(x);
    }
}
int curr = 1;
void dfs2(int x) {
if(visited2[x]) {
return;
}
ans[x] = curr;
visited2[x] = true;
for(int y : rev_graph[x]) {
    dfs2(y);
}


}

int main() {

int v, e; cin >> v >> e;

visited1 = new bool[v+1];
visited2 = new bool[v+1];
graph = new vector<int>[v+1];
rev_graph = new vector<int>[v+1];
ans = new int[v+1];
st = v;
for(int i = 1; i<=v; i++) {
    visited1[i] = false;
    visited2[i] = false;
}

for(int i = 0; i< e; i++) {
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    rev_graph[b].push_back(a);
}
for(int i = 1; i <=v; i++) {
    if(!visited1[i]) dfs1(i);
}
while(!s.empty()) {
    auto top = s.top();
    s.pop();
    if(visited2[top]) continue;
    else {
  dfs2(top);
curr++;
    }
}

cout << curr-1 << "\n";
for(int i = 1; i<=v; i++) {
    cout << ans[i] << " ";
}



}
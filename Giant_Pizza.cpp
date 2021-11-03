#include <bits/stdc++.h>
using namespace std;

int e, v;
unordered_map<int, vector<int>> graph;
unordered_map<int, vector<int>> rev_graph;
stack<int> s;
queue<int> qq;
unordered_map<int, bool> assigned;
unordered_map<int, bool> visited1;
unordered_map<int, bool> visited2;
unordered_map<int, bool> assigned_val;
void dfs1(int x) {
if(!visited1[x]) {
    visited1[x]=true;
    for(int y : graph[x]) {
        dfs1(y);
    }
    s.push(x);
    qq.push(x);
}
}


unordered_set<int> vis;

void dfs2(int x) {

if(visited2[x]) {
return;
}
if(vis.find(-x) != vis.end()) {
    cout << "IMPOSSIBLE";
// cout << x << endl;
exit(0);
}

vis.insert(x);
visited2[x] = true;
for(int y : rev_graph[x]) {
    dfs2(y);
}


}




int main() {
cin >> e >> v;
for(int i = 0; i < e; i++) {
    int a, b;
    char p, q;
    cin >> p;
    cin >> a;
    if(p == '-') a *= -1;
    cin >> q >> b;
    if(q == '-') b *= -1;
// cout << a << " " << b << endl;
    graph[-a].push_back(b);    
    graph[-b].push_back(a);
    rev_graph[b].push_back(-a);
    rev_graph[a].push_back(-b);
}

for(int i = -v; i<=v; i++) {
    if(!visited1[i] && !graph[i].empty()) {
      dfs1(i);
    }
}

while(!s.empty()) {
    auto top = s.top();
    s.pop();
    if(visited2[top]) continue;
    vis = unordered_set<int>();
    dfs2(top);
    
}

while(!qq.empty()) {
auto front = qq.front();
qq.pop();
if(assigned[front]) continue;
assigned[front] = true;
assigned[-front] = true;
assigned_val[front] = true;
assigned_val[-front] = false;
}

for(int i = 1; i <= v; i++) {
    cout << (assigned_val[i] ? '+' : '-') << " ";
}




}
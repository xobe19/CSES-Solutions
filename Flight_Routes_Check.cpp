#include <bits/stdc++.h>
using namespace std;

vector<int>* graph;
vector<int>* rev_graph;
bool* visited;
int st;
int visited_count;
void cls() {
for(int i = 0; i <= st; i++) visited[i] = false;
visited_count = 0;
}

void dfs(int x, bool r) {
if(visited[x]) return;
visited[x] = true;
visited_count++;
if(r) {
for(int y: rev_graph[x]) {
    dfs(y,r);
}


}
else for(int y: graph[x]) {
    dfs(y, r);
}
}


int main() {
int v, e; cin >> v >> e;
st = v;
graph = new vector<int>[v+1];
visited = new bool[v+1];
rev_graph = new  vector<int>[v+1];
cls();
for(int i = 0; i < e; i++) {
int a, b; cin >> a >> b;

graph[a].push_back(b);
rev_graph[b].push_back(a);

}

dfs(1, false);
if(visited_count != v) {
    for(int i = 1; i <= v; i++) {
      if(!visited[i]) {
          cout << "NO\n" << 1 << " " << i;
          exit(0);
      }
    }
}

cls();
dfs(1, true);

if(visited_count != v) {
    for(int i = 1; i <= v; i++) {
      if(!visited[i]) {
          cout << "NO\n" << i << " " << 1;
          exit(0);
      }
    }

}




cout << "YES";

}
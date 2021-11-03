#include <bits/stdc++.h>
using namespace std;

vector<int>*graph;
bool* visited;
vector<int> curr_path;
// void print_cycle(int x, int start, int prev) {
//     // cout <<  "BHASHAN";
// // cout << start << " " << prev << endl;
// cycle.push_back(x);
// if(x == start && cycle.size() != 1) return;
// for(int y : graph[x]){
// if(y != prev) print_cycle(y, start, x);
// }


// }


void dfs(int s, int prev) {

if(visited[s]) { 
int j = 0;
for(; j < curr_path.size(); j++) {
    if(curr_path[j] == s) break;
}
 cout << curr_path.size() -j + 1 << "\n";
 for(int k = j; k < curr_path.size(); k++) cout << curr_path[k] << " ";
            cout << curr_path[j];
exit(0);

}
else {
    visited[s] = true;
    curr_path.push_back(s);
    for(int x : graph[s]) {
        if(x != prev) {
            dfs(x, s);
        }
    }
    curr_path.pop_back();
}


}



int main() {


int v, e; cin >> v >> e;
graph = new vector<int>[v+1];
visited = new bool[v+1];
for(int i = 0; i <= v; i++) {
    visited[i] = false;
}
for(int i = 0; i < e; i++) {
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}

for(int i = 1; i <= v; i++){
    if(!visited[i]) {
                dfs(i, -1);
    }
}
cout << "IMPOSSIBLE";

}

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

vector<int>*graph;
bool* visited;
int curr_path[1'00'001];
bool curr_set[1'00'001];
int syz = 0;
// void print_cycle(int x, int start, int prev) {
//     // cout <<  "BHASHAN";
// // cout << start << " " << prev << endl;
// cycle.push_back(x);
// if(x == start && cycle.size() != 1) return;
// for(int y : graph[x]){
// if(y != prev) print_cycle(y, start, x);
// }


// }


void dfs(int s) {
// cout << s << endl;
    // if(glbl[s]) return;
if(visited[s]) { 
    if(!curr_set[s]) return;
int j = 0;
for(; j < syz; j++) {
    if(curr_path[j] == s) break;
}
// if(syz == j) {
//  return;
//     // cout << "IMPOSSIBLE";
//     // exit(0);
// }
 cout << syz-j + 1 << "\n";
 for(int k = j; k < syz; k++) cout << curr_path[k] << " ";
            cout << curr_path[j];
exit(0);

}
else {
    visited[s] = true;
    curr_path[syz++] = s;
    curr_set[s] = true;
    for(int x : graph[s]) {
            dfs(x);
    }
    curr_set[s] = false;
    syz--;
    // visited[s] = false;
}


}



int main() {


int v, e; cin >> v >> e;
graph = new vector<int>[v+1];
visited = new bool[v+1];
for(int i = 0; i <= v; i++) {
    visited[i] = false;
    curr_set[i] = false;
    // glbl[i] = false;
}
for(int i = 0; i < e; i++) {
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
}

for(int i = 1; i <= v; i++){
    // cout << v << endl;
    // usleep(3000000);
    //   for(int j = 1; j <= v; j++) {
    //                 glbl[j] = visited[j];
    //                 // visited[j] = false;
    //             }
if(!visited[i])
                dfs(i);


}
std::cout << "IMPOSSIBLE";

}

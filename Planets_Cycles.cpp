#include <bits/stdc++.h>
using namespace  std;

vector<int> cycle;
int* depth;
int* root;
int*graph;
int* cycled;
int* cycle_start;
vector<int>*rev_graph;
int max_depth = 0;


void dfs(int x, int prev){
    cycled[x] = cycle.size();
    cycle_start[x] = cycle[0];
if(rev_graph[x].empty())  {
   max_depth = max(max_depth, prev); 
}
else {
for(auto&y:rev_graph[x]) {
    if(depth[y] == 0) {
        continue;
    }
    depth[y] = prev+1;
    root[y] = root[x];
    dfs(y, prev+1);
}


}
}

int main() {
int v; cin >> v;
graph = new int[v+1];
depth = new int[v+1];
root = new int[v+1];
cycled = new int[v+1];
cycle_start = new int[v+1];
rev_graph = new vector<int>[v+1];
for(int i = 0; i < v; i++) {
    cin >> 
    graph[i+1];
    rev_graph[graph[i+1]].push_back(i+1);
    depth[i] = -1;
    cycled[i] = -1;
}
depth[v] = -1;
cycled[v] = -1;



for(int babloo = 1; babloo <= v; babloo++) {
if(cycled[babloo] != -1) continue;
cycle.clear();
int ptr1 = graph[babloo];
int ptr2 = graph[graph[babloo]];

while(ptr1 != ptr2) {
ptr1 = graph[ptr1];
ptr2 = graph[graph[ptr2]];
}

ptr1 = babloo;
while(ptr1 != ptr2) {
    ptr1 = graph[ptr1];
    ptr2 = graph[ptr2];
}

int start = graph[ptr1];
cycle.push_back(ptr1);
depth[ptr1] = 0;
root[ptr1] = ptr1;
while(start != ptr1) {
    cycle.push_back(start);
depth[start] = 0;
root[start] = start;
    start = graph[start];
}

for(int i = 0; i < cycle.size(); i++) {
    dfs(cycle[i], 0);
}


}



// for(auto&zz:dist) {
//     cout << zz.first << " " << zz.second << endl;
// }

// for(int i = 1; i <= v; i++) {
//     cout << depth[i] << " ";
// }
// cout << endl;
// for(int i = 1; i <= v; i++) {
//     cout << root[i] << " ";
// }


for(int curr = 1; curr <= v; curr++) {

cout << depth[curr] + cycled[curr] << " ";

}

}



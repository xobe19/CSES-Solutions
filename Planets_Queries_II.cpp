#include <bits/stdc++.h>
using namespace  std;

vector<int> cycle;
int* depth;
int* root;
unordered_map<int, int> dist;
int*graph;
int** two_power_arr;
int* cycled;
int* cycle_start;
vector<int>*rev_graph;
int max_depth = 0;

int jump(int x, int t) {
    for(int k = 0; k <= 31; k++) {
          if(t&(1<<k)) {
              x = two_power_arr[k][x];
          }
    }
    return x;
}


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
int v, q; cin >> v >> q;
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
int d = 0;
dist[ptr1] = 0;
while(start != ptr1) {
    cycle.push_back(start);
depth[start] = 0;
root[start] = start;
dist[start] = ++d;
    start = graph[start];
}

for(int i = 0; i < cycle.size(); i++) {
    dfs(cycle[i], 0);
}


}




int pw = 0;
for(int i = 0; i <= 31; i++) {
    if(max_depth&(1<<i)) {
        pw = i;
    }
}

two_power_arr = new int*[pw+1];

    two_power_arr[0] = new int[v+1];

    for(int i = 1; i <= v; i++) {
        
        two_power_arr[0][i] = graph[i];
        if(depth[i] == 0) two_power_arr[0][i] = 0;
    }
for(int i =1; i < pw+1; i++) {
    two_power_arr[i] = new int[v+1];
    for(int j = 1;  j <= v; j++) {
        int cu = j;

        int ssss = 1<<i;
        if(depth[j] < ssss) {
            two_power_arr[i][j] = 0;
            continue;
        }
              cu = two_power_arr[i-1][cu]; 
              cu = two_power_arr[i-1][cu];
        two_power_arr[i][j] = cu;
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


while(q--) {
    int a, b; cin >> a >> b;
   if(cycle_start[a] != cycle_start[b]) {
       cout << -1 << "\n";
    continue;
   } 
    if(a == b) {
        cout << 0 << "\n";
    }
    else if(root[a] == root[b]){
        if(depth[a] == depth[b]) cout << -1 << "\n";
      else if(depth[a] > depth[b]) {
        //   cout << "und";
        //   cout << max_depth << endl;
          
        //   cout<<depth[a] << " " << depth[b];
        int new_a = jump(a, depth[a]-depth[b]);
        // cout << new_a << endl;
        // cout << endl << endl;
        // for(int i = 1; i< pw+1; i++) {
        //     for(int j = 1; j <= v; j++) {
        //         cout << two_power_arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if(new_a!=b) cout << -1 << "\n";
        else {
            cout << depth[a]-depth[b] << "\n";
        }
      }
      else {
        cout << -1 << "\n"; 
      }
    }
    else if(depth[a] == 0 && depth[b] == 0) {
        int fin = dist[b]-dist[a];
        if(fin < 0) {
            fin += cycled[a];
        }
        cout << fin << "\n";
    }
    else if(depth[a] == 0) {
        cout << -1 << endl;
        // int fin = depth[b];
        // int fin2 = -dist[root[b]]+dist[a];
        // if(fin2<0) {
        //     fin2+=cycled[a];
        // }
        // cout << fin + fin2<<"\n";
    }
    else if(depth[b] == 0) {
       int fin = depth[a];
       int fin2 = -dist[root[a]]+dist[b];
       if(fin2<0) {
           fin2+=cycled[b];
       }
       cout << fin + fin2<<"\n";
    }
    else {
        cout << -1 << "\n";
    }
}

}


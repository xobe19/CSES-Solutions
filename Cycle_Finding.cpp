#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array



vector<ar<int, 2>>*graph;
bool* visited;
int tf;
void cls() {
    for(int i = 0; i < tf+1; i++) {
      visited[i] = false;
    }
}
vector<int> cycle;
ll sum_dfs = 0;

void dfs(int x, int start, int prev_weight) {
    // cout << x << " ";
    if(visited[x])  {

        if(x != start || sum_dfs + prev_weight>= 0) return;
    cout << "YES\n";
    for(int j = 0; j < cycle.size(); j++) cout << cycle[j] << " ";
    cout << x;
    exit(0);

    }
    visited[x] = true;
    cycle.push_back(x);
    sum_dfs += prev_weight;
// if(x == tf) {
    
//     cout << -1;
//     exit(0);
// }
  for(auto& y: graph[x]) {
    //   if(!dnt_visit[y[0]])
        dfs(y[0], start, y[1]);
  } 
visited[x] = false;
// dnt_visit[x] = true;
sum_dfs-=prev_weight;
cycle.pop_back();
}


// void dfs2(int x) {
//     if(visited[x]) return;
//     visited[x] = true;
//     if(x == tf) {
//         should = true;
//         return;
//     }
//     else {
//         for(auto&y:graph[x]) {
//             dfs2(y);
//         }
//     }
//     visited[x] = false;
// }
int main() {
int v, e; cin >> v >> e;
tf = v;
ar<int, 3> edges[e];
for(int i = 0; i<e;i++) {
    int a, b, c; cin >> a >> b >> c;
    edges[i] = {a, b,c};
}


ll distance[v+1];
for(int i = 1; i < v+1; i++) {
    distance[i] = LLONG_MAX;
}
int prev[v+1];
distance[1] = 0;
for(int i = 0; i < v-1; i++) {
    for(int i = 0; i < e; i++) {
        ll u = edges[i][0], v = edges[i][1], w = edges[i][2];
        __int128_t sum = (__int128_t)distance[u] + w;
        if(distance[v] > sum) {
            prev[v] = u;
           distance[v] = sum; 

    //   cout << distance[u] << " " << w << " " << distance[v] << endl;
        }
    }
}
// for(int i = 0; i < v+1; i++) cout << prev[i] << " ";
for(int i = 0; i < e; i++) {
        ll u = edges[i][0], vv = edges[i][1], w = edges[i][2];
        __int128_t sum = (__int128_t)distance[u] + w;
        if(distance[vv] > sum) {

          distance[vv] = distance[u]+w; 
          prev[vv] = u;
            // cout << vv << endl;
        vector<int> bt;
        int curr = vv;
        bool*visited;
        visited = new bool[v+1];
        for(int i = 0; i < v+1;i++) visited[i] = false;
        while( !visited[curr]) {
            visited[curr] = true; 
            bt.push_back(curr);
            curr = prev[curr];
        }

        bt.push_back(curr);
        int it = 0; 
        for(; bt[it] != curr; it++) {}
        cout << "YES\n";
        for(int it_n = bt.size()-1; it_n != it-1;it_n--) {
            cout << bt[it_n]  << " ";
        }
        exit(0);

        }

}

cout << "NO";




}
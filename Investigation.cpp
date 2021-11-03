#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;
const int mod = 1e9+7;
vector<ar<int, 2>>*graph;
vector<int>*prev_v;
ll* dist;
bool* memed;
ar<ll, 3>* mem;
ar<ll, 3> dfs(int x) {
    if(memed[x]) return mem[x];
  ar<ll, 3> answ;
  int sa = 0;
  ll sb = LLONG_MAX;
  ll sc = 0;
for(auto&y:prev_v[x]) {
    auto pr = dfs(y);
   sa += pr[0]; 
   sa %= mod;
   sc = max(sc, pr[2]);
  sb = min(sb, pr[1]); 

}
answ = {sa, sb + 1, sc + 1};
memed[x] = true;
return mem[x]= answ;

}

int main() {
int v, e; cin>>v>>e;
graph = new vector<ar<int, 2>>[v+1];
prev_v = new vector<int>[v+1];
dist = new ll[v+1];
memed = new bool[v+1];
mem = new ar<ll, 3>[v+1];
for(int i = 0; i < e; i++) {
    int a, b, c; cin >> a >> b >> c;
    graph[a].push_back({b,c});
}

priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> q;

for(int i= 0; i < v+1; i++) {
    dist[i] = LLONG_MAX;
    memed[i] = false;
}
 mem[1] = {1LL, 0, 0}; 
memed[1] = true; 
 
 dist[1] = 0;

q.push({0, 1});

while(!q.empty()) {
    auto front = q.top();
    q.pop();
    if(dist[front[1]] < front[0]) continue;

    for(auto&y:graph[front[1]]) {
        __int128_t sum = (__int128_t)y[1] + front[0];
        if(sum < dist[y[0]]) {
            dist[y[0]] = sum;
           prev_v[y[0]].clear(); 
            prev_v[y[0]].push_back(front[1]); 
            ar<ll, 2> sdfs = {dist[y[0]], y[0]};
            q.push(sdfs);
            // q.push({dist[y[0]], y[0]});
        }
        else if(sum == dist[y[0]]) {
           
            prev_v[y[0]].push_back(front[1]); 
        }

    }

}

cout << dist[v] << " ";
// cout << prev_v[v].size();

// for(int i = 1; i <= v; i++) {
//     // cout << i << endl;
//     for(int j = 0; j < prev_v[i].size(); j++) {
// // cout << prev_v[i][j] << " ";
//     }
//     // cout << endl;
// }

auto anss = dfs(v);
cout << anss[0] << " " << anss[1] << " " << anss[2];








}
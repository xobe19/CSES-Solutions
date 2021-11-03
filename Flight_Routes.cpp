#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
ll** dist;
vector<ar<int, 2>>*graph;
int main() {
int v, e, k; cin >> v >> e >> k;
dist = new ll*[v+1];
graph = new vector<ar<int, 2>>[v+1];

for(int i = 0; i < e; i++) {
    int a, b, c; cin >> a >> b >> c;
    graph[a].push_back({b, c});
}


// for(int i = 1; i <= 1; i++) {
//  dist[i] = new ll[k];    

//  for(int j = 0; j  < k; j++) dist[i][j] = 0;

// }
for(int i = 1; i <= v; i++) {
 dist[i] = new ll[k];    

 for(int j = 0; j  < k; j++) dist[i][j] = LLONG_MAX;

}
dist[1][0] = 0;
priority_queue<ar<ll, 2> , vector<ar<ll, 2>>, greater<ar<ll, 2>>> q;
q.push({0, 1});
while(!q.empty()) {
auto front = q.top();
q.pop();
if(dist[front[1]][k-1] >= front[0]) {
for(auto&y:graph[front[1]]) {
    __int128_t sum = (__int128_t)front[0] + y[1];
if(sum < dist[y[0]][k-1]) {
dist[y[0]][k-1] = sum; 

    q.push({dist[y[0]][k-1], y[0]});
sort(dist[y[0]], dist[y[0]]+k);

}


}
}


}

for(int i = 0; i < k; i++) {
    cout << dist[v][i] << " ";
}



}
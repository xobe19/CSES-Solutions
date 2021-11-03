#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

vector<ar<int, 2>>*graph;
int v, e;
bool*processed;

int main() {
cin >> v >> e;
graph = new vector<ar<int, 2>>[v+1];

for(int i = 0; i < e; i++) {
   int a, b, c; cin >> a >> b >> c;
   graph[a].push_back({b,c});
   graph[b].push_back({a, c});


}
processed = new bool[v+1];

for(int i = 0; i < v+1; i++) processed[i] = false;
int num_pr = 0;
ll cost = 0;
priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> q;
q.push({0, 1});

while(!q.empty()) {
auto front = q.top();
q.pop();
if(processed[front[1]]) continue;
processed[front[1]] = true;
cost += front[0];
num_pr++;
for(auto&y:graph[front[1]]) {
    if(!processed[y[0]]) {
        q.push({y[1], y[0]});
    }
}
}
if(num_pr == v) cout << cost;
else cout << "IMPOSSIBLE";

}
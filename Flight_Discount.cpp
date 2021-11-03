#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long



int main() {


priority_queue<ar<ll, 2>, vector<ar<ll, 2> >, greater<ar<ll, 2>> > q;
int v, e; cin >> v >> e;
vector<ar<int,2>>*graph = new vector<ar<int, 2>>[v+1];
auto graph2 = new vector<ar<int, 2>>[v+1];

bool* processed = new bool[v+1];
bool* processed2 = new bool[v+1];
ll* distance = new ll[v+1];
ll* distance2 = new ll[v+1];
for(int i = 0; i < v+1;i++) {
    processed[i] = false;
    distance[i] = LLONG_MAX;
     processed2[i] = false;
    distance2[i] = LLONG_MAX;
    
}

distance[1] = 0;
distance2[v] = 0;

for(int i = 0; i < e; i++) {
    int a, b, c; cin >> a >> b >> c;
graph[a].push_back({b, c});
graph2[b].push_back({a, c});
}
q.push({0, 1});

while(!q.empty()) {
auto front = q.top();
q.pop();
if(!processed[front[1]]) {
    processed[front[1]] = true;
__int128_t dist = front[0];
for(auto&y:graph[front[1]]) {

__int128_t sum = dist + y[1]; 
if(sum < distance[y[0]]) {
    distance[y[0]] = sum;
    q.push({distance[y[0]], y[0]});
}


}

}


}
q = priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>>();
q.push({0, v});

while(!q.empty()) {
auto front = q.top();
q.pop();
if(!processed2[front[1]]) {
    processed2[front[1]] = true;
__int128_t dist = front[0];
for(auto&y:graph2[front[1]]) {

__int128_t sum = dist + y[1]; 
if(sum < distance2[y[0]]) {
    distance2[y[0]] = sum;
    q.push({distance2[y[0]], y[0]});
}


}

}


}
ll mc = LLONG_MAX;

for(int x = 1; x < v+1; x++) {
    for(auto&y:graph[x]) {
   int u = x, vv = y[0]; 
   __int128_t w = y[1]/2;
   __int128_t cc = distance[u] + w + distance2[vv];
   if(cc < mc) {
       mc = cc;
   }
    }
}

cout << mc;



}
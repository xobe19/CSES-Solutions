#include <bits/stdc++.h>
using namespace std;
priority_queue<array<long long int,2>,vector<array<long long int, 2>>, greater<array<long long int, 2>>> q;
long long int *distances;
bool* processed;
vector<array<long long int, 2>>*graph;
  int main() {
long long int v, e; cin >>v >>e;
distances = new long long int[v+1];
processed = new bool[v+1];
graph = new vector<array<long long int, 2>>[v+1];

for(long long int i = 0; i < e; i++) {
  long long int a, b, c; cin >> a >> b >> c; 
  graph[a].push_back({b,c});
  


}
for(long long int i= 1; i < v+1; i++) {
distances[i] =  LLONG_MAX ;
processed[i] = false;
}
distances[1]=0;
q.push({0, 1});
while(!q.empty()) {
auto front = q.top();
q.pop();
if(!processed[front[1]]) {
    processed[front[1]] = true;
long long int dist = front[0];

for(auto&x:graph[front[1]]) {
    if( distances[x[0]] > dist + x[1]) {
        distances[x[0]] = dist + x[1];
        q.push({distances[x[0]], x[0]});
    }

}


}
}

for(long long int i = 1; i <= v; i++) cout << distances[i] << " ";

}
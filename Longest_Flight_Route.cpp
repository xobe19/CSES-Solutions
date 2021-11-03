#include <bits/stdc++.h>
#define ll long long 
#define ar array
using namespace std;


int main() {
    int v, e; cin >> v >> e;
    ll dist[v+1];
    int prev[v+1];
    vector<int> graph[v+1];
    for(int i = 0; i < e; i++) {
      int a, b; cin >> a >> b;
      graph[a].push_back(b);
    }

    for(int i = 0; i < v+1; i++) {
     dist[i] = LLONG_MIN;   
    }

    dist[1] = 0;
 priority_queue<ar<ll, 2>, vector<ar<ll, 2>> , greater<ar<ll, 2>>> q;
q.push({0, 1});
prev[1] = 0;
while(!q.empty()) {
    auto front = q.top();
    q.pop();
    if(front[0] < dist[front[1]]) continue;
    
    for(auto y: graph[front[1]]) {
        __int128_t sum = (__int128_t)1 + dist[front[1]];
        if(dist[y] < sum) {
            dist[y] = sum;
            prev[y] = front[1];
            ar<ll, 2> aff = {dist[y], y};
            q.push(aff);
        }

    }


}

if(dist[v] == LLONG_MIN) {cout << "IMPOSSIBLE"; return 0;}


int curr = v;
vector<int> answ;
while(curr != 1) {
answ.push_back(curr); 
curr = prev[curr];
}
answ.push_back(1);


cout << answ.size() << "\n";
for(auto it = answ.rbegin(); it != answ.rend(); it++) cout << *it << " ";



}
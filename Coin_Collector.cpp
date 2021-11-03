#include <bits/stdc++.h>
using namespace std;
#define ll long long


unordered_set<ll>*dag;
vector<ll>*graph;
vector<ll>*rev_graph;
ll* vals;
ll* scc_vals;
bool* visited1;
bool* visited2;
ll* arr;

ll* mem;


ll dfs3(ll x) {
if(mem[x] != -1) return mem[x];

ll answ = 0;
for(auto&y:dag[x]) {
    if(y!=x)
    answ = max(answ, dfs3(y));
}
return mem[x] = answ+scc_vals[x];

}

stack<ll> s;
void dfs1(ll x) {
    if(!visited1[x]) {
        visited1[x] = true;
        for(ll y : graph[x]) {
            dfs1(y);
        }
        s.push(x);
    }
}
ll curr = 1;
ll sum = 0;
void dfs2(ll x) {
if(visited2[x]) {
return;
}
arr[x]=curr;
sum += vals[x];
visited2[x] = true;
for(ll y : rev_graph[x]) {
    dfs2(y);
}


}


int main() {

ll v, e; cin >> v >> e;
graph = new vector<ll>[v+1];
rev_graph = new vector<ll>[v+1];
vals = new ll[v+1];
scc_vals = new ll[v+1];
visited1 = new bool[v+1];
visited2 = new bool[v+1];
mem = new ll[v+1];
arr = new  ll[v+1];
for(ll i = 1; i <= v; i++) {
    visited1[i] = false;
    visited2[i] = false;
    cin >> vals[i];
}



for(ll i = 0; i < e; i++) {
    ll a, b; cin >> a >> b;
graph[a].push_back(b);
rev_graph[b].push_back(a);
}

for(ll i = 1; i <= v;i++) {
    if(!visited1[i]) {
        dfs1(i);
    }
}

while(!s.empty()) {
    auto top = s.top();
    s.pop();
    if(visited2[top]) continue;
    dfs2(top);
    scc_vals[curr] = sum;
curr++;
sum = 0;
}
dag = new unordered_set<ll>[curr+1];
for(ll x = 1; x <= v; x++) {
    for(auto y : graph[x]) {
       dag[arr[x]].insert(arr[y]);
    //    cout << arr[x] << " " << arr[y];
    }
}
ll a;
cin >> a;
for(ll i = 0; i < v+1; i++) {
    mem[i] = -1;
}
ll mxx = dfs3(1);
for(int i = 2; i < curr; i++) {
mxx = max(mxx, dfs3(i));
}
cout << mxx;




}
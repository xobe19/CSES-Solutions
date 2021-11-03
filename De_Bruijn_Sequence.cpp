#include <bits/stdc++.h>
using namespace std;


unordered_set<int>* graph;
vector<int> answ;

void dfs1(int x) {


while(!graph[x].empty()) {
auto it = graph[x].begin();
int y = *it;
graph[x].erase(it);
dfs1(y);
}
answ.push_back(x);



}

int main() {
int n; cin >> n;
int v = 1<<(n-1);
graph = new unordered_set<int>[v+1];
int curr = 0;
while(curr < v) {
    int a, b;
    a = curr << 1;
    if(a&v) {
     a ^=v; 
    }
    b = a ^ 1;
    graph[curr].insert(a);
    graph[curr].insert(b);
curr++;
}
dfs1(0);

int bgn = *answ.rbegin();
for(int i = n-2; i >= 0; i--) {
cout << (bool)(bgn&(1<<i));
}

for(auto it = answ.rbegin()+1; it != answ.rend(); it++) {
    int val = *it;
    cout << (bool)(val&1);
}



}
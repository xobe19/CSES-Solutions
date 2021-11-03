#include <bits/stdc++.h>
using namespace std;

int* color;
vector<int>*graph;
bool color_bipart(int s, int c) {
if(color[s]!=-1) {
   if(color[s] == c) return true;
   else return false;
}
else {
    color[s] = c;
    for(auto x:graph[s]) {
        bool succ = color_bipart(x, c == 1 ? 2 : 1);
        if(!succ) return false;
    }
    return true;
}



}


int main() {
int v, e; cin >> v >> e;
color = new int[v+1]; graph = new vector<int>[v+1];
for(int i = 0; i < v+1;i++) {
    color[i] = -1;
}
for(int i = 0; i < e; i++) {
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}

for(int i = 1; i <= v; i++) {
    if(color[i] == -1) {
     bool succ = color_bipart(i, 1);
     if(!succ) {
         cout << "IMPOSSIBLE";
         return 0;
     }
    }
}

for(int i = 1; i <= v; i++) cout << color[i] << " ";




}
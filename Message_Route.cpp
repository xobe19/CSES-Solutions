#include <bits/stdc++.h>
using namespace std;

int* who_sent;
vector<int>* graph;
bool* visited;


int main() {

int v, e;
cin >> v >> e;
who_sent = new int[v+1];
graph = new vector<int>[v+1];

visited = new bool[v+1];
for(int i = 0; i < v + 1; i++) {
    visited[i]=false;
    who_sent[i] = -1;
}
for(int i = 0; i < e; i++) {
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}


queue<int> q;
vector<int> bt;

q.push(1);
visited[1] = true;
while(!q.empty()) {

int front = q.front();
q.pop();


for(auto x:graph[front]) {
if(!visited[x]) {
visited[x] = true;
who_sent[x] = front;
if(x == v) {
   while(x != -1) {
       bt.push_back(x);
       x = who_sent[x];
       
   } 
   cout << bt.size() << "\n";
   for(auto it = bt.rbegin(); it != bt.rend(); it++) {
       cout << *it << " ";
   }
   return 0;
}
else {
    q.push(x);
}
}

}




}
cout << "IMPOSSIBLE";

}
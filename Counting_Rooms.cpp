#include <bits/stdc++.h>
using namespace std;

bool**visited;
int n, m;
int d1[] = {0, 0, 1, -1};
int d2[] = {1, -1, 0, 0};

void dfs(int i, int j) {
if(i < 0 || j < 0 || i >= n || j >= m) return;
if(visited[i][j]) return;
visited[i][j] = true;
for(int k = 0; k < 4; k++) {
dfs(i + d1[k], j + d2[k]);
}
}


int main() {

cin >> n >> m;
visited = new bool*[n];

for(int i = 0; i < n; i++) {
    visited[i] = new bool[m];
    string s; cin >> s;
    for(int j =0; j < m; j++) {
        
        visited[i][j] = s[j] == '#';
            
    }
}

int cnt = 0;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        if(!visited[i][j]) {
            dfs(i, j);
            cnt++;
        }
    }
}
cout << cnt;
}
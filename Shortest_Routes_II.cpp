#include <bits/stdc++.h>
using namespace std;
#define ll long long



int32_t main(){
ll** grid;
int v, e, q; cin >> v >> e >> q;
grid = new ll*[v+1];
for(int i = 1 ; i < v+1; i++) {
    grid[i] = new ll[v+1];
    for(int j = 1; j < v+1; j++) {
       if(i==j) grid[i][j] = 0;
       else {
           grid[i][j] = LLONG_MAX;
       }
    }
}
for(int i=0; i < e; i++) {
    ll a, b, c; cin >> a >> b >> c; 
    grid[a][b] = min(grid[a][b], c); grid[b][a] = min(grid[b][a], c);
}
for(int k = 1; k <= v; k++) {
for(int i = 1; i <= v; i++) {
 for(int j = 1; j <= v; j++) {
     ll sum = grid[i][k] + grid[k][j];
     sum = sum < 0 ? LLONG_MAX : sum;
      grid[i][j] = min(grid[i][j], sum);
 } 
}
}

while(q--) {
    int a, b; cin >> a >> b;
    cout << (grid[a][b] == LLONG_MAX ? -1 : grid[a][b]) << "\n";
}

}
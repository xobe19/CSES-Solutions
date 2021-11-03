#include <bits/stdc++.h>
using namespace std;
char** grid; 
int n,m; 
int** time_grid;
char** dir;
bool** visited;
bool** monster_visited;
vector<int> bt;

char d[] = {'D', 'U', 'R', 'L'};
int d1[] = {1, -1, 0, 0};
int d2[] = {0, 0, 1 , -1};
bool e(int i, int j) {
    // cout << i << " " << j;
    return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '#' && !monster_visited[i][j];}

bool e(int i, int j, int timer) {
    return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '#' && time_grid[i][j] > timer && !visited[i][j];
}
bool can_exit(int i, int j) {
return (i == 0 || j == 0 || i == n-1 || j == m-1) && grid[i][j] != '#';
}

void dfs(int i, int j, int timer, char di) {
if(!e(i, j , timer)) return;

    // cout << " " << i << " " << j << " " << timer << endl;
visited[i][j] = true;
dir[i][j] = di;
if(can_exit(i, j)) {
   while(grid[i][j] != 'A') {

   bt.push_back(dir[i][j]) ;
      int indx = 0;
      while(d[indx] != dir[i][j]) {
        indx++;
      }
      i -= d1[indx];
      j -= d2[indx];
   }

   cout << "YES\n" << bt.size() << "\n";
   for(auto it = bt.rbegin(); it != bt.rend(); it++) {
 cout << (char)*it;
   }
   exit(0);
}
for(int k = 0; k < 4; k++) {
// if(e(i + d1[k], j + d2[k], timer + 1))
 dfs(i + d1[k], j + d2[k], timer + 1,d[k]);

}
visited[i][j] = false;


}

int main() {
cin>>n>>m;
grid = new char*[n];
time_grid = new int*[n];
dir = new char*[n];
visited = new bool*[n];
monster_visited = new bool*[n];
int si, sj;
queue<array<int, 3>> ms_bfs;
for(int i = 0; i < n; i++) {
    grid[i] = new char[m];
    time_grid[i] = new int[m];
    visited[i] = new bool[m];
    dir[i] = new char[m];
    monster_visited[i] = new bool[m];
    string s; cin >> s;
    for(int j = 0; j < m; j++) {

       monster_visited[i][j] = false;
        if(s[j] == 'M') {ms_bfs.push({i, j, 0});
        
monster_visited[i][j] = true;
        }
        if(s[j] == 'A') {si = i; sj = j;}
       grid[i][j] = s[j]; 
       visited[i][j] = false;
       time_grid[i][j] = INT_MAX;
    }
}

while(!ms_bfs.empty()) {
array<int, 3> front = ms_bfs.front();
// cout << front[0] << " " << front[1] << " " << front[2] << endl;
ms_bfs.pop();
time_grid[front[0]][front[1]] = front[2];
for(int k = 0; k < 4; k++) {
    if(e(front[0] + d1[k], front[1] + d2[k])) {
        // cout << k << endl;
monster_visited[front[0]+d1[k]][front[1]+d2[k]] = true;

      ms_bfs.push({front[0]+d1[k], front[1] + d2[k], front[2]+1}); 
      
      }

}
// cout  << "size: \n";
// cout << ms_bfs.size() << endl;




}
// cout << si << " " << sj << endl; 
// for(int i = 0; i < n; i++) {
//     for(int j = 0; j < m; j++) {
//         cout << time_grid[i][j] << " ";
//     }
//     cout << endl;
// }

// cout << "done";
dfs(si, sj, 0, 'N');

cout << "NO";





}
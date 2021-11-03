#include <bits/stdc++.h>
using namespace std;

int n, m;
// char**grid;
bool visited[1000][1000];
char how_reached[1000][1000];
char d[] = {'D', 'R', 'U', 'L'};
int d1[] = {1, 0, -1, 0};
int d2[] = {0, 1, 0, -1};
int ei, ej;
string bt;
void bfs(int i, int j) {

queue<array<int, 2> > q;
q.push({i, j});
while(!q.empty()) {
    auto front = q.front();

    // cout << front[0] << " " << front[1] << endl;
    q.pop();
    // if(visited[front[0]][front[1]] || grid[front[0]][front[1]] == '#') continue;
    for(int k = 0; k < 4; k++) {

array<int, 2> arr = {front[0] + d1[k], front[1] + d2[k]};
        if(arr[0] >= 0 && arr[1] >= 0 && arr[0] <n && arr[1]<m && !visited[arr[0]][arr[1]]) {
 visited[arr[0]][arr[1]] = true;
        if(arr[0] == ei && arr[1] == ej) {
            // cout << "hai";
         bt.push_back(d[k]); 
         while(front[0] != i || front[1] != j) {
             
char dir = how_reached[front[0]][front[1]];
// cout << front[0] << " " << front[1] << " " << dir << endl;
             bt.push_back(dir);
             int indx = 0;
             while(d[indx] != dir) {
                 indx++;
             }
             front[0] -= d1[indx];
             front[1] -= d2[indx];
         }
         return;
        }
        q.push(arr);
        how_reached[arr[0]][arr[1]] = d[k];
        
        }
        
    }

}
}


int main() {

cin >> n >> m;
// cout << "u";
int si, sj;
for(int i = 0; i < n; i++) {
    string s; cin >> s;
    // cout << i << endl;
    for(int j = 0; j < m; j++) {
        if(s[j] == 'A') {
            si = i; sj = j;
        }
        else if(s[j] == 'B') {
            ei = i; ej = j;
        }
        visited[i][j] = s[j] == '#';
        // how_reached[i][j] = 'N';

    }
}

// cout << si << " " << sj;
visited[si][sj] = true;
bfs(si, sj);
if(bt.size() == 0) {
    cout << "NO";
    return 0;
}
cout << "YES\n" << bt.size() << "\n";
for(auto it = bt.rbegin(); it != bt.rend(); it++) {
   cout << *it; 
}



}
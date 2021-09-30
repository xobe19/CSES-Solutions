#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
char** grid;
int n;
int** mem;
int f(int x, int y) {
if(x < 0 || y < 0 || x >= n || y >= n) return 0;
if(grid[x][y] == '*') return 0;
if(x == n - 1 && y == n - 1) return 1;
if(mem[x][y] != -1) return mem[x][y];

mem[x][y] =  f(x + 1, y) + f(x, y + 1);
mem[x][y] %= mod;
return mem[x][y];
}


int main() {
    cin >> n;
    grid =  new char*[n];
    mem = new int*[n]; 
    for(int i = 0; i < n; i++) {
        string s; cin>>s;
        grid[i] = new char[n];
        mem[i] = new int[n];
        for(int j = 0; j < n; j++) {
            grid[i][j] = s[j];
            mem[i][j] = -1;
        }
    }
    cout << f(0,0);
}

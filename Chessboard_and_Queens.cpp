#include <bits/stdc++.h>

using namespace std;
char**board = new char*[8];
void place_queen(char** board, int i, int j) {
board[i][j] = 'q';
}

bool is_safe(char** board, int i, int j) {

for(int k = 0; k < 8; k++) {
    if(board[i][k] == 'q') return false;
    if(board[k][j] == 'q') return false;
}
int diff = i - j;
for(int a = 0; a < 8; a++) {
    for(int b = 0; b < 8; b++) {
        if(a - b == diff || a + b == i + j) {
            if(board[a][b] == 'q') return false;
        }
    }
}
return true;
}

void remove_queen(char**  board, int i , int j){
 board[i][j] = '.';
}
int ans = 0;
void f(char** board, int processed) {
  if(processed == 8) {
    ans++;
}
else {
    for(int j = 0; j < 8; j++) {
        if(board[processed][j] == '.' && is_safe(board, processed, j)) {
            place_queen(board , processed , j);
            f(board, processed+1);
            remove_queen(board, processed, j);
        }
    }
}
}


int main() {
    for(int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        char* tmp = new char[8];
      for(int j = 0; j < 8; j++)
      tmp[j] = s[j];
      board[i] = tmp;
    }
    f(board, 0);
    cout << ans;
}
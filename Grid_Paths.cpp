#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
int ans = 0;
int** visited;
bool exists(int i, int j) {
    if(i < 0 || j < 0 || j >= 7 || i >= 7 || visited[i][j] != 0) return false; 
    return true;
}
void f(int** visited, int prev_i, int prev_j, string&pattern, int steps_processed) {
if(prev_i < 0 || prev_j < 0 || prev_j >= 7 || prev_i >= 7 || visited[prev_i][prev_j] != 0) return;
if(steps_processed == 48) {
    if(prev_i == 6 && prev_j == 0)
 {
   ans++; 
  // cout << ans;
}
}
else if(prev_i == 6 && prev_j == 0) {

}
else {
visited[prev_i][prev_j] = 1;

 if(pattern[steps_processed] == '?' || pattern[steps_processed] == 'U') {
     if(exists(prev_i-1, prev_j) && !(!exists(prev_i-2,prev_j) && exists(prev_i - 1, prev_j + 1) && exists(prev_i -1 , prev_j - 1)))
   f(visited, prev_i - 1, prev_j, pattern, steps_processed + 1);
}
 if(pattern[steps_processed] == '?' || pattern[steps_processed] == 'L') {

     if(exists(prev_i, prev_j - 1) && !(!exists(prev_i,prev_j-2) && exists(prev_i + 1, prev_j - 1) && exists(prev_i -1 , prev_j - 1)))
   f(visited, prev_i, prev_j - 1, pattern, steps_processed + 1);
}
 if(pattern[steps_processed] == '?' || pattern[steps_processed] == 'R') {

     if(exists(prev_i, prev_j + 1) && !(!exists(prev_i,prev_j+2) && exists(prev_i + 1, prev_j + 1) && exists(prev_i -1 , prev_j + 1)))
   f(visited, prev_i, prev_j + 1, pattern, steps_processed + 1);
}
 if(pattern[steps_processed] == '?' || pattern[steps_processed] == 'D'){

     if(exists(prev_i + 1, prev_j ) && !(!exists(prev_i+2,prev_j) && exists(prev_i + 1, prev_j - 1) && exists(prev_i +1 , prev_j + 1)))
   f(visited, prev_i + 1, prev_j, pattern, steps_processed + 1);
}
visited[prev_i][prev_j] = 0;

}
}





int main() {
visited = new int*[7];
for(int i = 0; i < 7; i++) {
    visited[i] = new int[7];
    for(int j = 0; j < 7;j++) {
        visited[i][j] = 0;
    }
}
string pattern;
cin >> pattern;
f(visited, 0, 0, pattern, 0);
cout << ans;
}
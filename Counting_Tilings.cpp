#include <bits/stdc++.h>
using namespace std;
int** mem;
int n, m;
const int mod = 1e9 + 7;

void gen_next_mask( int mask, vector<int>&masks, int s, int curr_mask) {
    // cout << "g";
    int e = n-1;
    
if(s > e) {
   masks.push_back(curr_mask);
   return;
}

    if((mask&(1<<s))) {gen_next_mask(mask, masks, s + 1, curr_mask); return;}
gen_next_mask( mask, masks, s+1, curr_mask^(1<<s));
if(s != e && !(mask&(1<<(s+1)))) {
    gen_next_mask(mask, masks, s + 2, curr_mask);
}


}


int f(int col, int mask) {
if(col == m) {
if(mask == 0) return 1;
return 0;
}
if(mem[mask][col] != -1) return mem[mask][col];
vector<int> next_masks;
gen_next_mask(mask, next_masks, 0, 0);
int answ = 0;
for(int next_mask : next_masks) {
   answ += f(col+1, next_mask);
   answ %= mod;
}
mem[mask][col] = answ;
return answ;
}



int main() {
cin >> n >> m;
mem = new int*[1<<n];
for(int i = 0; i < 1<<n; i++) {
    mem[i] = new int[m];
    for(int j = 0; j < m; j++) mem[i][j] = -1;
}
cout << f(0, 0);
}
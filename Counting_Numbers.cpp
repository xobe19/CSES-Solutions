#include <bits/stdc++.h>
using namespace std;

string r1;
long long int mem[19][10][2][2];
long long int f(long long int n,long long int last, bool e, bool has_started) {
    // if(n == 1) {
    //     cout << " last : " << last << " " <<  e << has_started << endl;
    // }
    if(mem[n][last][e][has_started] != -1) return mem[n][last][e][has_started];
    if(n == 0) return 1;
if(!e) {
long long int answ = 0;



for(long long int i =0; i < 10; i++){
    if((i == 0 && !has_started) ||  i != last) 
answ += f(n-1, i, false, has_started || i != 0);
}
mem[n][last][e][has_started] = answ;
return answ;
}
else {
    
long long int indx = r1.size() - n;
long long int new_last = r1[indx] - 48;
long long int answ = 0;
for(long long int i =  0; i < new_last; i++) {
    if((i == 0 && !has_started) || i!=last)
answ += f(n-1, i, false, has_started || i != 0);
}
if(new_last != last) {
    answ +=  f(n-1, new_last, true, true);
}

mem[n][last][e][has_started] = answ;
return answ;
}

}


  int main() {
long long int l, r; cin >> l >> r;
for(long long int a = 0; a < 19; a++) 
for(long long int b = 0; b < 10; b++)
for(long long int c = 0; c < 2; c++)
for(long long int d = 0; d < 2; d++)
mem[a][b][c][d] = -1;

r1 = to_string(r);
long long int mx_first = r1[0] - 48;
long long int answ = 0;
for(long long int i = 0; i < mx_first; i++) {
answ += f(r1.size()-1, i, false, i != 0);
}
answ += f(r1.size()-1, mx_first, true, true);
// cout << answ << endl;
if(l == 0) {
    cout << answ; return 0;
}
r1 = to_string(l-1);
 mx_first = r1[0] - 48;
for(long long int a = 0; a < 19; a++) 
for(long long int b = 0; b < 10; b++)
for(long long int c = 0; c < 2; c++)
for(long long int d = 0; d < 2; d++)
mem[a][b][c][d] = -1;

for(long long int i = 0; i < mx_first; i++) {
answ -= f(r1.size() -1, i, false, i != 0);
}
answ -= f(r1.size()-1, mx_first, true, true);
cout << answ;
}
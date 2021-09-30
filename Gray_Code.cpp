#include <bits/stdc++.h>
using namespace std;

vector<string> f(int n) {
if(n == 1) {
    return {"0", "1"};
}
auto prev = f(n-1);
vector<string> next;
for(int i = 0; i < prev.size();i++) {
    next.push_back("0"+prev[i]); 
}
for(int i = prev.size()-1; i>=0;i--) {
    next.push_back("1"+prev[i]);
}
return next;
}

int main(){
    int n; cin >> n;
    auto ans = f(n);
    for(string&x: ans) {
        cout << x << "\n";
    }
}
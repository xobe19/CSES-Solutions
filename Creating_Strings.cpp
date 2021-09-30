#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> answ;
    string orig; cin >> orig;
    sort(orig.begin(), orig.end());
    answ.push_back(orig);
    
    while(   
    next_permutation(orig.begin(), orig.end()) ) {
        answ.push_back(orig);
    }

    cout << answ.size() << "\n";
    for(string&x:answ) {
        cout << x << "\n";
    }
}
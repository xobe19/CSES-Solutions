#include <bits/stdc++.h>
using namespace std;
bool comp(array<int, 2>&a, array<int, 2>&b) {
if(a[0] == b[0]) {
    return a[1] >= b[1];
}
return a[0] < b[0];
}
int main () {
    map<array<int, 2>, bool> a;
    int n; cin >> n;
    vector<array<int, 2>> s(n);
    vector<array<int, 2>> orig(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        s[i] = {a, b};
        orig[i] = {a, b};
    }
    sort(s.begin(), s.end(), comp);

    int min_after = s[s.size() - 1][1];
    a[s[s.size()-1]] = false; 
    for(int i = s.size()-2; i >= 0; i--) {
        if(s[i][1] >= min_after) {
            a[s[i]] = true;
        }
        else {
            min_after = s[i][1];
            a[s[i]] = false;
        }
    
    }
    for(int i = 0 ; i < orig.size(); i++) {
        cout << a[orig[i]] << " "; 
    }
    cout << "\n";
 // sort(s.begin(), s.end(), comp);
    int max_right_before = s[0][1]; 
    a[s[0]] = false;
    for(int i = 1; i < s.size(); i++) {
        if(s[i][1] <= max_right_before) {
            a[s[i]] = true;
        }
        else  {
            max_right_before = s[i][1];
            a[s[i]] = false;
        }
    }
    for(int i = 0; i < orig.size(); i++) {
        cout << a[orig[i]] << " ";
    }
}
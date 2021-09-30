#include <bits/stdc++.h>
using namespace std;

int num_elems(set<int>&min_after, int k) {
 auto it = min_after.upper_bound(k);
 
 return it - min_after.begin();
}

bool comp(array<int, 2>&a, array<int, 2>&b) {
if(a[0] == b[0]) {
    return a[1] >= b[1];
}
return a[0] < b[0];
}
int main () {
    map<array<int, 2>, int> a;
    int n; cin >> n;
    vector<array<int, 2>> s(n);
    vector<array<int, 2>> orig(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        s[i] = {a, b};
        orig[i] = {a, b};
    }
    sort(s.begin(), s.end(), comp);
    set<int> min_after;
    min_after.insert(s[s.size()-1][1]);
    int min_after = s[s.size() - 1][1];
    a[s[s.size()-1]] = 0; 
    for(int i = s.size()-2; i >= 0; i--) {
        a[s[i]] = num_elems(min_after, s[i][1]);
        min_after.insert(s[i][1]);
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
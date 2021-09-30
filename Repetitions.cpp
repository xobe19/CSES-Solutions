#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    char prev = '*';
    int curr_count = 0;
    int max_count = INT_MIN;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == prev) {
            curr_count++;
           max_count = max(curr_count, max_count); 
        }
        else {
            prev = s[i];
            curr_count = 1;
            max_count = max_count > 1 ? max_count :1;
        }
    }
    cout << max_count;
}
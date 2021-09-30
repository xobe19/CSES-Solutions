#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants(n);
    for(int i = 0; i < n; i++) {
        cin >> applicants[i];
    }
    vector<int>apts(m);
    for(int i = 0; i < m; i++) {
        cin >> apts[i];
    }
sort(apts.begin(), apts.end());
sort(applicants.begin(), applicants.end());
int ans=  0;
int i = 0; int j = 0;
while(i < n && j < m) {
if(abs(applicants[i] - apts[j]) <= k) {
ans++;
i++;
j++;
continue;
}
else if(applicants[i] - apts[j] < 0){
i++;
continue;
}
else {
    j++;
    continue;
}
}
cout << ans;

}

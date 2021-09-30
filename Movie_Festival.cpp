#include <bits/stdc++.h>
using namespace std;


int main() {
long long int n; cin >> n;
vector<pair<long long int, long long int> > data(n);
for(long long int i =0 ; i<n; i++) {
    long long int a, b; cin >> a >> b;
    data[i] = {b, a};
}
sort(data.begin(), data.end());

long long int cm = 1;
long long int mm = 1;

auto prev = data[0].first;
for(long long int i = 1; i < data.size(); i++)  {
if(data[i].second >= prev) {
    cm++;
    mm = max(cm, mm);
    prev = data[i].first;
}
else {

}
}

cout << mm;
}
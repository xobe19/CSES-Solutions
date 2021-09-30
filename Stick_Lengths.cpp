#include <bits/stdc++.h>
using namespace std;


unsigned long long int calc(vector<unsigned long long int>&data, unsigned long long int avg) {
unsigned long long int ops = 0;
for(unsigned long long int&x:data) {
    ops += max(avg, x) - min(avg, x);
}
return ops;
}


int main() {
    unsigned long long int n; cin >> n;
   vector<unsigned long long int> data(n);
   for(unsigned long long int i = 0; i < n; i++) {
    cin >> data[i];
   }
sort(data.begin(), data.end());
if(data.size() % 2 == 0){
cout << min(calc(data, data[data.size()/2]), calc(data, data[data.size()/2-1]));
}
else {
    cout << calc(data, data[(data.size()-1)/2]);
}
   

}
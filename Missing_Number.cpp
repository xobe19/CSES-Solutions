#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
long long int n; cin >> n;
long long sum = 0;
long long sum_2 = n * (n + 1) / 2;
while(--n) {
int t; cin >> t;
sum+=t;
}
cout << sum_2 - sum << endl;



}
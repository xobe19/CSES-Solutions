#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> a, b;
    int n, k; cin >> n >> k;
    if(k == 1) {
        while(n--)
        {int t; cin >> t; cout << t << " ";}
        return 0;
    }
        int arr[k];
        int arry[n];
        for(int i = 0; i < k; i++) {
            cin >> arr[i];
            arry[i] = arr[i];
        }
        sort(arr, arr + k);
        for(int i = 0; i < k/2; i++) {
            a.insert(arr[i]);
        }
        for(int j = k/2; j < k; j++) {
            b.insert(arr[j]);
        }
        for(int i = k; i < n; i++) {
            cin >> arry[i];
        }

        for(int i = 0; i + k<= n; i++) {
            //cout << i << endl;
            if(a.size() >= b.size()) {
               auto it = a.end(); 
               cout << *(--it) << " ";
            }
            else  {
             cout << *(b.begin()) << " ";
            }
            auto it = a.find(arry[i]);
            if(it == a.end()) b.erase(b.find(arry[i]));

            else a.erase(it);
           if(((int)b.size() - (int)a.size()) >= 1) {
               int bgin = *(b.begin());
               a.insert(bgin);
               b.erase(b.begin());
           }

           int next = arry[i+k];
           auto iter = a.end();
           int a_max =  *(--iter);
           int b_min = *(b.begin());
           if(next > a_max ) {
              b.insert(next); 

           }
           else {
               a.erase(iter);
               b.insert(a_max);
               a.insert(next);
           }
 if(((int)b.size() - (int)a.size()) > 1) {
               int bgin = *(b.begin());
               a.insert(bgin);
               b.erase(b.begin());
           }


        }
}
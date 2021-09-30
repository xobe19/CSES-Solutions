#include <bits/stdc++.h>
using namespace std;

long long int leftSum = 0;
long long int rightSum = 0;
  void calc(long long int*arr, long long int median ,long long int s, long long int e, int l_size, int r_size){
    // cout << s << " " << e << endl;
    long long int ans = 0; 
  ans += l_size*median - leftSum;
  ans += rightSum - r_size*median;
cout << ans << " ";



    // long long int ans = 0;
    // for(long long int i = s; i<=e; ++i) {
    //     ans += abs(arr[i] - median);
    // }
    // return ans;
}

int prev_answ = -1;

int main() {
  multiset<long long int> a, b;
    long long int n, k; cin >> n >> k;
    if(k == 1) {
        while(n--)
        {long long int t; cin >> t; cout << 0 << " ";}
        return 0;
    }
        long long int arr[k];
        long long int arry[n];
        for(long long int i = 0; i < k; i++) {
            cin >> arr[i];
            arry[i] = arr[i];
        }
        sort(arr, arr + k);
        for(long long int i = 0; i < k/2; i++) {
            a.insert(arr[i]);
            leftSum += arr[i];
        }
        for(long long int j = k/2; j < k; j++) {
            b.insert(arr[j]);
            rightSum += arr[j];
        }
        for(long long int i = k; i < n; i++) {
            cin >> arry[i];
        }

if(((long long int)b.size() - (long long int)a.size()) >= 1) {
               long long int bgin = *(b.begin());
               leftSum += bgin;
               rightSum -= bgin;
               a.insert(bgin);
               b.erase(b.begin());
           }

        for(long long int i = 0; i + k<= n; i++) {
            //cout << i << endl;
            if(a.size() >= b.size()) {
               auto it = a.end(); 
               auto tmp  = *(--it);
                calc(arry, tmp, i, i + k - 1, a.size(), b.size());
            }
            else cout << "bsdk";
                      auto it = a.find(arry[i]);
            if(it == a.end()) {b.erase(b.find(arry[i])); 
            rightSum -= arry[i]; 
            
            }

            else {a.erase(it);
           leftSum -= *it; 
            } 
           if(((long long int)b.size() - (long long int)a.size()) >= 1) {
               long long int bgin = *(b.begin());
               a.insert(bgin);
               leftSum += bgin;
               rightSum -= bgin;
               b.erase(b.begin());
           }

           long long int next = arry[i+k];
           auto iter = a.end();
           long long int a_max =  *(--iter);
        //    long long int b_min = *(b.begin());
           if(next > a_max ) {
              b.insert(next); 
         rightSum += next;
           }
           else {
               leftSum -= *iter;
               rightSum += a_max;
               leftSum += next;
               a.erase(iter);
               b.insert(a_max);
               a.insert(next);
           }
 if(((long long int)b.size() - (long long int)a.size()) >= 1) {
               long long int bgin = *(b.begin());
               leftSum += bgin;
               rightSum -= bgin;
               a.insert(bgin);
               b.erase(b.begin());
           }


        }

}
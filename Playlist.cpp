#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int start = 0, end = 0;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<int> seen;
    seen.insert(arr[0]);
    int cl = 1;
    int ml = 1;
    end = 1;
    while(end < n) {
      //  cout << start << " " << end << endl;
     while(end < n) {
       if(seen.find(arr[end]) == seen.end()) {
           seen.insert(arr[end]);

           cl = end - start + 1;
           end++;
           ml = max(cl, ml); 
           }
       else {
          break; 
       }

     }  

     while(end < n && start < end) {
         cl--;
         ml = max(ml, cl);
         if(arr[start] == arr[end]) {
             
             start++;
             end++;
             break;
         }
         seen.erase(arr[start]);
         start++;
     }
     



    }
    cout << ml;
}
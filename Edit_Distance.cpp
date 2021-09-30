// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




int** memoize;

class Solution {
  public:
  
    int f(string &str1, string &str2, int size1, int size2) {
        if(size1 == 0 || size2 == 0) {
            return size1 == 0 ? size2 : size1;
        }
        if(memoize[size1][size2] != -1) return memoize[size1][size2];
        int first_1 = str1.size() - size1;
        int first_2 = str2.size() - size2;
        
        if(str1[first_1]== str2[first_2]) {
            auto ans_f= f( str1,  str2, size1-1, size2-1);
            memoize[size1][size2] = ans_f;
            return memoize[size1][size2];
        }
        
        else {
            int a = f(str1, str2, size1, size2-1);
            int b = f(str1, str2, size1-1, size2);
            int c = f(str1, str2, size1-1, size2-1);
            
            auto ans_f= 1 + std::min(a, std::min(b, c));
            memoize[size1][size2] = ans_f;
            return memoize[size1][size2];
        }
        
        
    }
  
    int editDistance(string s, string t) {
        // Code here
        memoize = new int*[s.size() + 1];
       for(int i = 0; i <= s.size(); i++) {
           memoize[i] = new int[t.size() + 1];
           for(int j = 0; j <= t.size(); j++) {
               memoize[i][j] = -1;
           }
       }
       
       return f(s, t, s.size(), t.size());
       
    }
};

// { Driver Code Starts.
int main() {
    int T;
    T = 1;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int dp[1010];
  int helper(int length,vector<int> &p)
  {
      if(length == 0 ) return 0;
      if(dp[length] != -1 ) return dp[length];
      int val =0;
      for(int len_to_be_cut = 1; len_to_be_cut <=p.size() ; len_to_be_cut++)
      {
          if(length - len_to_be_cut >= 0){
            val = max(val , helper(length-len_to_be_cut,p) + p[len_to_be_cut -1 ]);
          }
      }
      return dp[length] = val;
  }
  
  
  
  
    int cutRod(int price[], int n) {
    memset(dp,-1,sizeof(dp));
        vector<int> p(price,price+n);
        
        return helper(n,p);
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
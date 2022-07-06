#include<bits/stdc++.h>
using namespace std;
const int N= 25e2+10;
int dp[N];

int lis(int i,vector<int> &a)
{
    if(dp[i]!= -1) return dp[i];
    int maxx=1;
    for(int j=0;j<i;j++)
    {   
        if(a[i]>a[j]){
            maxx=max(maxx,lis(j,a)+1);
        }
    }
    return dp[i] = maxx;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int ans=0;

    for(int i=0;i<a.size();i++){
        ans=max(ans,lis(i,a));
    }
    cout<<ans;
    

return 0;
}
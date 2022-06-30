#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int k;
int h[N];
int dp[N];

int fun(int i)
{
    // base case
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int cost = INT_MAX;

    // way1
    //  cost=min(cost, fun(i-1)+abs(h[i]-h[i-1]));

    for (int jup = 1; jup <= k; jup++)
    {
        if (i - jup >= 0)
        {
            cost = min(cost, fun(i - jup) + abs(h[i] - h[i - jup]));
        }
    }
    // if(i>1){
    //     cost=min(cost,fun(i-2) + abs(h[i] - h[i-1]));
    // }

    return dp[i] = cost;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    // int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cout << fun(n - 1);

    return 0;
}
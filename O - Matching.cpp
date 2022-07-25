#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const int mod = 1e9 + 7;
const int OO = 1e18;
const int N  = 21, M = 1000;

int n;
int grid[N][N];
int dp[N][(1LL<<21)];
int solve(int i, int mask)
{
    if(i == n)return 1;
    int &ret = dp[i][mask];
    if(~ret) return ret;
    ret = 0;
    for(int j=0;j<n;j++)
    {
        if(!(mask & (1LL << j)) && (grid[i][j] == 1))
        {
            ret += solve(i+1, (mask)|(1<<j));
            if(ret>=mod)
                ret -= mod;
        }
    }
    return ret;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    clr(dp, -1);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << solve(0,0);
    return 0;
}

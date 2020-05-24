#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#define M 2509
#define N 55
#define clr(A) memset(A,0,sizeof(A))
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
int n,K;
int dp[N][N][M];
P x[N];
bool cmp(P a, P b){
    return a.second*b.first > a.first*b.second;
}
void solve(int no){
    cin>>n>>K;
    int tot=0;
    for(int i=1,ca,cb;i<=n;i++){
        cin>>ca>>cb;
        x[i]=P(ca,cb);
        tot+=cb;
    }
    sort(x+1,x+n+1,cmp);
    memset(dp,-1,sizeof(dp));
    int ans=0;
    dp[1][1][x[1].second] = x[1].first * x[1].second;
    for (int i = 1; i<n; i++)
    {
        dp[i][0][0] = 0;
        for (int j = 0; j <= i; j++)
            for (int h = 0; h <= tot; h++)
                if (dp[i][j][h] >= 0)
                {
                    dp[i + 1][j][h] = max(dp[i + 1][j][h], dp[i][j][h]);
                    dp[i + 1][j + 1][h + x[i + 1].second] = max(dp[i + 1][j + 1][h + x[i + 1].second], dp[i][j][h]+ x[i + 1].first * (x[i + 1].second + 2 * h));
                }
    }
    for (int i=1;i<=tot;i++)
			ans=max(dp[n][K][i], ans);
    printf("Case %d: %d\n",no,ans);
}
int main()
{
    #if defined JESI
        freopen("3.txt", "r", stdin);
    //        freopen("2.txt", "w", stdout);
    #endif
    int t;cin>>t;
    for(int i=1;i<=t;i++)
        solve(i);
    return 0;
}

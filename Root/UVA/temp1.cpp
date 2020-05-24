#include <bits/stdc++.h>
using namespace std;

int s, l;

int dp[30][360][30];

int solve (int cur, int sum, int grp)
{
    if (sum > s || grp > l) return 0;
    if (sum == s && grp == l) return 1;

    int &ret = dp[cur][sum][grp];
    if (ret != -1) return ret;

    ret = 0;
    for (int i=cur+1 ; i<27 ; i++)
        ret += solve(i, sum+i, grp+1);
    return ret;
}
int main()
{
    int t = 0, x;

//    freopen("1.txt", "r", stdin);
//    freopen("3.txt", "w", stdout);

    while (scanf("%d%d", &l, &s) == 2 && l)
    {
        memset(dp, -1, sizeof dp);
        if (s > 351 || l > 26) x = 0;
        else x = solve(0, 0, 0);

        printf("Case %d: %d\n", ++t, x);
    }
    return 0;
}

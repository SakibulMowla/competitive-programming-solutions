#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int inf = 1<<28;
#define SZ 35

char arr1[SZ], arr2[SZ];
int dp[SZ][SZ], len1, len2;
ll dp1[SZ][SZ];


int solve(int indx1,int indx2)
{
    int &ret = dp[indx1][indx2];

    if(ret != -1) return ret;
    if(indx1 == len1) return ret = len2-indx2;
    if(indx2 == len2) return ret = len1-indx1;

    ret = inf;

    if(arr1[indx1] == arr2[indx2])
        return ret = 1 + solve(indx1+1, indx2+1);

    ret = min(ret, 1 + solve(indx1+1, indx2));
    ret = min(ret, 1 + solve(indx1, indx2+1));

    return ret;
}


ll solve1(int indx1,int indx2)
{
    ll &ret = dp1[indx1][indx2];

    if(ret != -1) return ret;
    if(indx1 == len1 || indx2 == len2) return ret = 1;

    if(arr1[indx1] == arr2[indx2])
        return ret = solve1(indx1+1, indx2+1);

    int a = solve(indx1+1, indx2), b = solve(indx1, indx2+1);

    if(a == b)
        ret = solve1(indx1+1, indx2) + solve1(indx1, indx2+1);

    else if(a < b)
        ret = solve1(indx1+1, indx2);

    else
        ret = solve1(indx1, indx2+1);

    return ret;
}


int main()
{
    int test=0, t, i, j;

    scanf("%d",&t);

    while(t--)
    {
        scanf(" %s %s",arr1,arr2);

        len1 = strlen(arr1);
        len2 = strlen(arr2);

        for(i=0; i<=len1; i++)
            for(j=0; j<=len2; j++)
                dp[i][j] = -1, dp1[i][j] = -1;

        printf("Case %d: %d %lld\n",++test, solve(0, 0), solve1(0, 0));
    }

    return 0;
}

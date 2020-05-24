#include "bits/stdc++.h"
using namespace std;

#define SZ 102

int n;
int gold[SZ];
double dp[SZ];


double solve(int pos)
{
    double &ret = dp[pos];

    if(ret != -1) return ret;
    if(pos == n)  return gold[pos];

    int i, space = min(6, n-pos);

    ret = gold[pos];

    for(i=1; i<=space; i++)
        ret += (1.00/(double)space) * solve(pos+i);

    return ret;
}


int main()
{
    int test=0, t, i;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=1; i<=n; i++)
            dp[i] = -1, scanf("%d",&gold[i]);

        printf("Case %d: %.12lf\n",++test,solve(1));
    }

    return 0;
}

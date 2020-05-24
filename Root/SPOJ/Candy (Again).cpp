using namespace std;

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "iostream"

#define MAX 110

typedef long long ll;
const ll inf = 1LL<<28;

ll dp[MAX][410] , cnt[MAX] , calo[MAX] , n;

ll abso(ll i)
{
    if(i < 0) i = -i;
    return i;
}

ll solve(ll indx,ll dif)
{
    ll &ret = dp[indx][dif];

    if(indx == n) return ret = 0;
    if(ret != -1) return ret;

    ll i , cal;
    ret = inf;

    for(i=0; i<=cnt[indx]; i++)
    {
        cal = solve(indx + 1, (calo[indx] * abso(cnt[indx]-i-i))) - (calo[indx] * abso(cnt[indx]-i-i));
        if(abso(cal) < abso(ret)) ret = abso(cal);
    }

    return ret;
}

int main()
{
    ll i, j;
    while(scanf("%lld", &n) == 1)
    {
        for(i=0; i<n; i++)
            scanf("%lld %lld", &cnt[i], &calo[i]);

        for(i=0;i<=n;i++)
            for(j=0;j<=405;j++)
                dp[i][j] = -1;

        i = abso(solve(0 , 0));

        printf("%lld\n", i);
    }

    return 0;
}

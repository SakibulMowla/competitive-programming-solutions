#include "stdio.h"
#include "string.h"
#include "iostream"
using namespace std;

#define SZ 40010
#define SZ1 210
enum {red , blue};
typedef long long ll;
const ll inf = 1<<28;

ll height[SZ1] ,dp[2][SZ1][SZ] , presum[SZ1] , R , B , n;

ll solve(ll col,ll indx,ll rsum)
{
    if(indx == n) return 0;
    ll &ret = dp[col][indx][rsum] , dif = 0 , p;
    if(ret != -1) return ret;
    ret = inf;
    if(indx) dif = min(height[indx] , height[indx-1]);
    if(rsum + height[indx] <= R)
    {
        p = solve(red,indx+1,rsum+height[indx]);
        if(indx && col == blue) p += dif;
        ret = min(ret , p);
    }
    if(presum[indx] - rsum <= B)
    {
        p = solve(blue,indx+1,rsum);
        if(col == red) p += dif;
        ret = min(ret , p);
    }
    return ret;
}

//%I64d
int main()
{
    ll i,k;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%I64d",&n) == 1)
    {
        scanf("%I64d %I64d",&R,&B);
        for(i=0; i<n; i++)
        {
            scanf("%I64d",&height[i]);
            if(i) presum[i] = presum[i-1] + height[i];
            else presum[i] = height[i];
        }
        memset(dp,-1,sizeof(dp));
        k = solve(0,0,0);
        printf("%I64d\n",k >= inf ? -1 : k);
    }

    return 0;
}

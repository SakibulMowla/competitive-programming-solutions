#include "stdio.h"
#define SZ 1010

typedef long long ll;
const ll inf = 1<<28;
template <class T> T max(T a,T b)
{
   return a > b ? a : b;
}
ll n , arr[SZ] , dp[SZ][2];

ll solve(ll indx,ll par)
{

    if(indx > n) return 0ll;
    if(indx == n)
    {
        if(par != 1ll)
        {
//            printf("indx = %lld par = %lld arr[n] = %lld\n",indx,par,arr[n]);
            return arr[n];
        }
        else
        {
//            printf("indx = %lld par = %lld arr[n] = 0\n",indx,par);
            return 0ll;
        }
    }
    ll &ret = dp[indx][par];
    if(ret != -1) return ret;
    ret = 0ll;
    if(indx == 1ll) ret = max(ret , solve(indx+2,indx) + arr[indx]);
    else ret = max(ret , solve(indx+2,par) + arr[indx]);
    ret = max(ret , solve(indx+1,par));

//    printf("indx = %lld par = %lld ret = %lld\n",indx,par,ret);
    return  ret;

}

int main()
{
    ll t=0,test,i,j;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        for(i=1; i<=n; i++)
            scanf("%lld",&arr[i]);
        for(i=0; i<=n; i++) for(j=0; j<2; j++) dp[i][j] = -1;
        printf("Case %lld: %lld\n",++t,solve(1ll,0ll));
    }

    return 0;
}

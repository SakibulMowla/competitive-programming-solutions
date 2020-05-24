#include "stdio.h"
#include "string.h"
#define SZ 100010

typedef long long ll;

ll modvalue[SZ];

int main()
{
    ll t=0,test,i,j,n,mod,cur,ans;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&n,&mod);
        ans = cur = 0;
        memset(modvalue,0,sizeof(ll)*(mod+1));
        modvalue[0] = 1;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&j);
            cur = (cur + j) % mod;
            ans = ans  +  modvalue[cur];
            modvalue[cur]++;
        }
        printf("Case %lld: %lld\n",++t,ans);
    }

    return 0;
}

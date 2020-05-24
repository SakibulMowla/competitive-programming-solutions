#include "stdio.h"

typedef long long ll;
const ll inf = 1<<30;
template <class T> T max(T a,T b) { return a > b ? a : b; }

int main()
{
    ll i,n,k,t,f,ans;
    while(scanf("%I64d %I64d",&n,&k) == 2)
    {
        ans = -inf;
        for(i=0;i<n;i++)
        {
            scanf("%I64d %I64d",&f,&t);
            if(t > k)
                ans = max(ans,f-(t-k));
            else
                ans = max(ans,f);
        }
        printf("%I64d\n",ans);
    }

    return 0;
}

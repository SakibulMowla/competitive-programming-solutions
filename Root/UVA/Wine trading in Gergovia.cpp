#include "stdio.h"
typedef long long ll;
template <class T> T absolute(T a){return a < 0 ? -a : a;}
int main()
{
    ll n,cur,prev,ans;
    while(scanf("%lld",&n) == 1 && n)
    {
        ans = prev = 0;
        while(n--)
        {
            scanf("%lld",&cur);
            cur = cur + prev;
            ans += absolute(cur);
            prev = cur;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

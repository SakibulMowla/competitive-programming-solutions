#include <bits/stdc++.h>

using namespace  std;

typedef unsigned long long ll;

ll BigMod(ll B,ll P,ll M)
{
    ll R=1LLU%M;
    while(P>0)
    {
        if(P&1LLU)
        {
            R=(R*B)%M;
        }
        P >>= 1LLU;
        B=(B*B)%M;
    }
    return R;
}

#define SZ 100010
const ll inf = 1LL<<28;
const ll mod = 1000000007LLU;

int main()
{
    int i, t;

    ll n, tmp, ans;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%llu",&n);

        tmp = 0LLU;

        for(i=18; i>=0; i--)
        {
            tmp *= 10LLU;
            if(n&(1LLU<<i))
                tmp += 1LLU;
        }

        ans = BigMod(2LLU, tmp, mod);

        if(n & (1LLU<<19))
        {
            tmp = BigMod(2LLU, 5000000000000000000LLU, mod);
            tmp = (tmp * tmp) % mod;
            ans = (ans * tmp) % mod;
        }

        ans = (ans * ans) % mod;

        printf("%llu\n",ans);
    }


    return 0;
}

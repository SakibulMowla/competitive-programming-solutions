#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()

typedef long long ll;
typedef pair<ll,ll> pii;

#define SZ 110
const ll inf = 1LL<<28;
const ll mod = 1LL;

priority_queue <ll> PP_QQ[SZ];

int main()
{
    ll n, m, t, i, j, k, v;
    ll p[10010];

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0;i<m;i++)
            scanf("%lld",&p[i]);
        for(i=0;i<n;i++)
        {
            while(!PP_QQ[i].empty())PP_QQ[i].pop();
            scanf("%lld",&k);
            for(j=0;j<k;j++)
            {
                scanf("%lld",&v);
                PP_QQ[i].push(v);
            }
        }
        v = 0;
        for(i=0;i<m;i++)
        {
            if(!PP_QQ[ p[i] ].empty())
                v += PP_QQ[ p[i] ].top(), PP_QQ[ p[i] ].pop();
        }
        printf("%lld\n",v);
    }

    return 0;
}

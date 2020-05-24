#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()

typedef long long ll;
typedef pair<ll,ll> pii;


#define SZ 110
const ll inf = 1LL<<28;
const ll mod = 1LL;

struct DAATAA{ll a, b;};
DAATAA array[SZ];

double DEPE[110][10010];

ll N, sum;

double doit(ll indx, ll num)
{
    double &ret = DEPE[indx][num];
    if(indx == N)
    {
        if(2*num >= sum) return ret = 1.0;
        return ret = 0.0;
    }
    if(DEPE[indx][num] != -1)
        return ret;
    ret = (double)(array[indx].b/100.0) * doit(indx+1, num+array[indx].a) + (double)((100-array[indx].b)/100.0) * doit(indx+1, num);
    return ret;
}

int main()
{
    ll n, t, i, j;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);
        N = n;
        sum = 0;
        for(i=0; i<n; i++)
            scanf("%lld",&array[i].a), sum += array[i].a;
        for(i=0; i<n; i++)
            scanf("%lld",&array[i].b);
        for(i=0; i<=n; i++)
            for(j=0; j<=sum; j++)
                DEPE[i][j] = -1;
        printf("%.12lf\n",doit(0, 0));
    }

    return 0;
}

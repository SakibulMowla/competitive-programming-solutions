#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(a) (ll)(a.size())

vector <ll> good, baad;
ll sum, cnt, N;

void solve(ll indx,ll pres,ll num)
{
    ll i;
    if(num)
    {
        for(i=0;i<sz(baad);i++)
        {
            sum += pres + baad[i];
            cnt++;
        }
    }
    if(indx == N)
        return;
    solve(indx+1, pres, num);
    solve(indx+1, pres+good[indx], num+1);
}

int main()
{
    ll n, i, j;
    freopen("1.txt","r",stdin);

    while(scanf("%lld",&n) == 1)
    {
        good.clear();
        baad.clear();
        for(i=0;i<n;i++)
        {
            scanf("%lld",&j);
            if(j < 0) baad.push_back(j);
            else good.push_back(j);
        }
        if(sz(baad) == 0)
        {
            j = 0;
            for(i=0;i<sz(good);i++)
                j += good[i];
            printf("%.12lf\n",(double)j);
        }
        else
        {
            sum = cnt = 0;
            N = sz(good);
            solve(0, 0, 0);
            for(i=0;i<sz(baad);i++)
                sum += baad[i], cnt++;
            printf("%.12lf\n",(double)sum/(double)cnt);
        }
    }

    return 0;
}

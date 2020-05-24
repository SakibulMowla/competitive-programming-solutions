#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<ll,ll> pii;

#define SZ 110
const ll inf = 1LL<<28;
const ll mod = 1LL;

double pi[SZ];
int ai[SZ], bi[SZ];
double dp[1<<18];
int n;

double solve(int indx, int mask)
{
    if(indx == n)
        return 1.00;

    double &ret = dp[mask];

    if(ret != -1)
        return ret;

    ret = 0.00;

    int tmp;


        if( mask & (1<<ai[indx]) )
        {
            tmp = mask & ~(1<<ai[indx]);
            ret += (pi[indx]/100.0) * solve(indx+1, tmp);
        }

        if( mask & (1<<bi[indx]) )
        {
            tmp = mask & ~(1<<bi[indx]);
            ret += ((100-pi[indx])/100.0) * solve(indx+1, tmp);
        }


    return ret;
}

int main()
{
    int t, i, j, k, lim;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%lf %d %d",&pi[i], &ai[i], &bi[i]);
            ai[i]--;
            bi[i]--;
        }
        lim = 1 << 16;
        for(i=0; i<=lim; i++)
            dp[i] = -1;
        printf("%.12lf\n",solve(0, lim-1));
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace  std;


typedef long long ll;

#define sz(a) (int)( a.size() )
#define SZ 100010
const ll inf = 1LL<<28;
const ll mod = 1LL;

vector <ll> v[SZ];
ll final[SZ];
ll k;

bool comp(vector <ll> p, vector <ll> q)
{
    return p[k] > q[k];
}

int main()
{

    ll t, n, m, i, j, l;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&k);

        for(i=0; i<=n; i++)
            v[i].clear();

        for(i=0; i<n; i++)
        {
            m = 0;
            for(j=0; j<k; j++)
            {
                scanf("%lld",&l);
                m += l;
                v[i].push_back(l);
            }
            v[i].push_back(m);
            v[i].push_back(i+1);
        }

        sort(v, v+n);

        for(i=0; i<k; i++)
            scanf("%lld",&final[i]);

        vector <ll> ans;

        for(i=0; i<n; i++)
        {
            for(j=0;j<k;j++)
                if(final[j]-v[i][j] < 0)
                    break;
            if(j == k)
            {
                for(j=0;j<k;j++)
                    final[j] -= v[i][j];
                ans.push_back(v[i][k+1]);
            }
        }

        sort(ans.begin(), ans.end());

        printf("%d\n",sz(ans));

        for(i=0;i<ans.size();i++)
        {
            if(i)
                printf(" ");
            printf("%lld",ans[i]);
        }
        printf("\n");
    }


    return 0;
}






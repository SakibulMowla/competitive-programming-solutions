using namespace std;

#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

#define MAX 10010
#define MAX1 1000010

typedef long long ll;

struct data
{
    ll a, b, c;
};

data input[MAX1];
ll par[MAX];

void init(ll n)
{
    ll i;
    for(i=0; i<=n; i++)
        par[i] = i;
}

bool comp(data p,data q)
{
    return p.c < q.c;
}

ll find(ll r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

ll MST(ll n,ll m)
{
    ll i, j, k, cnt=0 , cost=0;

    for(i=0; i<m && cnt < n-1; i++)
    {
        j = find(input[i].a);
        k = find(input[i].b);

        if(j == k) continue;

        cnt++;
        par[j] = k;
        cost += input[i].c;
    }

    return cost;
}

int main()
{
    ll n, m, i, j;

    while(scanf("%lld %lld",&n, &m) == 2)
    {
        init(n);
        for(i=0; i<m; i++)
            scanf("%lld %lld %lld",&input[i].a ,&input[i].b ,&input[i].c );

        sort(input,input+m,comp);

        printf("%lld\n",MST(n,m));
    }

    return 0;
}

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define SZ 100010

ll arr[SZ], qi[SZ], qj[SZ], qv[SZ], oprt[SZ], tmp[SZ];

int main()
{
    ll n, m , q, i, j;

    scanf("%I64d %I64d %I64d",&n,&m,&q);

    for(i=1; i<=n; i++)   scanf("%I64d",&arr[i]);
    for(i=1; i<=m; i++)   scanf("%I64d %I64d %I64d",&qi[i],&qj[i],&qv[i]);

    while(q--)
    {
        scanf("%I64d %I64d",&i,&j);
        oprt[i]++;
        oprt[j+1]--;
    }

    for(i=1; i<=m; i++)
    {
        oprt[i] += oprt[i-1];
        qv[i] *= oprt[i];
    }

    for(i=1; i<=m; i++)
    {
        tmp[ qi[i] ] += qv[i];
        tmp[ qj[i]+1 ] -= qv[i];
    }

    for(i=1; i<=n; i++)
    {
        tmp[i] += tmp[i-1];
        printf("%I64d ",tmp[i]+arr[i]);
    }

    return 0;
}

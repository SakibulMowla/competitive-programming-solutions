#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define SZ 100010

ll arr[SZ];
vector <ll> tmp;

int main()
{
    ll i, n, best,v;

    scanf("%I64d",&n);

    for(i=0; i<n; i++)
        scanf("%I64d",&arr[i]);

    for(v=30; v>=0; v--)
    {
        best = (1LL<<32) - 1;
        tmp.clear();
        for(i=0; i<n; i++)    if((1LL<<v) & arr[i])
            {
                tmp.push_back(arr[i]);
                best = best & arr[i];
            }
        if(best % (1LL<<v) == 0 && tmp.size())
            break;
    }

    n = tmp.size();

    printf("%I64d\n",n);
    for(i=0; i<n; i++)
        printf("%I64d ",tmp[i]);

    return 0;
}


#include <iostream>
#include <cstdio>
#include <cstring>

#define ll long long
#define sz 251*251
#define oo 1<<28

using namespace std;

ll arr[sz] , tmp[sz] , pos[sz];

ll bin_search(ll item,ll start,ll end)
{
    ll mid=(start + end) /2;
    while(start <= end)
    {
        if(tmp[mid] == item)
            return mid;
        if(start == end)
            break;
        if(tmp[mid] > item)
            end=mid;
        else
            start=mid+1;
        mid=(start + end) / 2;
    }
    return end;
}

ll lis(ll n)
{
    ll start=0,end=n,len=0,loc;
    tmp[0]=-oo;
    for(ll i=1;i<=n;i++)
        tmp[i]=oo;
    for(ll i=0;i<n;i++)
    {
        loc=bin_search(arr[i],start,end);
        tmp[loc]=arr[i];
        len=max(loc,len);
        end=len+1;
    }
    return len;
}

int main()
{
    ll test=0,t,i,j,p,q,n;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld %lld",&n, &p, &q);
        p++, q++;

        memset(pos , -1, sizeof(ll)*(n*n+2));

        for(i=0;i<p;i++)
        {
            scanf("%lld",&j);
            pos[j] = i;
        }

        for(i=0;i<q;i++)
        {
            scanf("%lld",&j);
            arr[i] = pos[j];
        }

        printf("Case %lld: %lld\n",++test, lis(q));
    }

    return 0;
}

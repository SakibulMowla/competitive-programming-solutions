#include <iostream>
#include <cstdio>
#include <cstring>

#define ll long long
#define sz 10000000
#define oo 1000000000

using namespace std;

ll arr[sz],tmp[sz],L[sz],lis_seq[sz];

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
        L[i]=loc;
        end=len+1;
    }
    return len;
}

void print(ll n,ll len)
{
    ll tt=len;
    for(ll i=n-1;i>=0;i--)
    {
        if(L[i] == len)
        {
            lis_seq[--len]=arr[i];
            if(!len)break;
        }
    }

    for(ll i=0;i<tt;i++)
        printf("%lld\n",lis_seq[i]);
    return;
}

int main()
{
    ll len,n=0;
    while(scanf("%lld",&arr[n++]) == 1){;}
    len=lis(n);
    printf("%lld\n",len);
    printf("-\n");
    print(n,len);
    return 0;
}

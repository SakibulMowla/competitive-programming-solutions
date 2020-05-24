#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <deque>

#define clr(a,b) memset(a,b,sizeof(a))
#define ll long long
#define pb push_back
#define sz 10000000
#define oo 1000000000

using namespace std;

ll arr[sz],tmp[sz],L[sz],lis_seq[sz];

ll BIN_search(ll item,ll start,ll end)
{
    ll mid=(start + end) / 2;
    while(start <= end)
    {
        if(tmp[mid]==item)
            return mid;
        if(start==end)
            break;
        if(tmp[mid] > item)
            end=mid;
        else
            start=mid+1;
        mid=(start+end)/2;
    }
    return end;
}
ll LIS(ll n)
{
    ll start=0,end=n,lis_len=0,loc;
    tmp[0]=-oo;
    for(ll i=1;i<=n;i++)
        tmp[i]=oo;
    for(ll i=0;i<n;i++)
    {
        loc=BIN_search(arr[i],start,end);
        tmp[loc]=arr[i];
        lis_len=max(loc,lis_len);
        L[i]=loc;
        end=lis_len+1;
    }
    return lis_len;
}

int main()
{
    ll n,len,item,temp,i,j,k;
    n=0;k=0;
    while(scanf("%lld",&item) && item!=-1)
    {
        if(k!=0)
            printf("\n");
        arr[n++]=item;
        while(scanf("%lld",&item) && item!=-1)
        {
            arr[n++]=item;
        }
        for(i=0,j=n-1;i<n/2;i++,j--)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        len=LIS(n);
        printf("Test #%d:\n",++k);
        printf("  maximum possible interceptions: %d\n",len);
        n=0;
    }
    return 0;
}

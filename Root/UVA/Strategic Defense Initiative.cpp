#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define sz 10000000
#define oo 1000000000
#define ll long long

using namespace std;

ll arr[sz],L[sz],lis_seq[sz],tmp[sz];

ll bin_search(ll item,ll start,ll end)
{
    ll mid=(start + end) / 2;
    while(start<=end)
    {
        if(tmp[mid]==item)
            return mid;
        if(start==end)
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
    ll len=0,loc,start=0,end=n;
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

void print(ll len,ll n)
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
    {
        printf("%lld\n",lis_seq[i]);
    }
    return;
}

int main()
{
    ll num,test,n,item,len;
    char str[20],z;
    scanf("%lld",&test);
    getchar();
    getchar();
    for(ll i=0;i<test;i++)
    {
        n=0;
        while(gets(str))
        {
            if(str[0]=='\0')
                break;
            item=atol(str);
            arr[n++]=item;
        }
        len=lis(n);
        printf("Max hits: %lld\n",len);
        print(len,n);
        if(i<test-1)
            printf("\n");
    }
    return 0;
}

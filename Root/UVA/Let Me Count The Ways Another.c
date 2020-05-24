#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define coins 5
#define ll long long

ll table[30000+5][15];
ll paisa[]={1,5,10,25,50};

ll count(ll money,ll coin_type)
{
    if(money<0)
        return 0;
    if(coin_type >= coins)
        return 0;
    if(table[money][coin_type] != -1)
        return table[money][coin_type];
    if(money==0)
        return 1;
    return table[money][coin_type]=count(money,coin_type+1) + count(money-paisa[coin_type],coin_type);
}

int main()
{
    ll ans,n;
    memset(table,-1,sizeof(table));
    while(scanf("%lld",&n)==1)
    {
        ans=count(n,0);
        if(ans!=1)
            printf("There are %lld ways to produce %lld cents change.\n",ans,n);
        else
            printf("There is only 1 way to produce %lld cents change.\n",n);
    }
    return 0;
}

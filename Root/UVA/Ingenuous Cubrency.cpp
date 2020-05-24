#include <stdio.h>
#include <string.h>

#define ll long long
#define total_coins 21

ll coin[30];
ll table[22][10000+5];

void cubes(void)
{
    ll i,j,k;
    for(i=0;i<21;i++)
        coin[i]=(i+1)*(i+1)*(i+1);
    return;
}

ll change(ll type,ll money)
{
    if(type >= total_coins)
        return 0;
    if(money < 0)
        return 0;
    if(table[type][money] != -1)
        return table[type][money];
    if(money==0)
        return 1;

    return table[type][money] = change(type+1 , money) + change(type , money-coin[type]);
}

int main()
{
    cubes();
    ll money,ans;
    memset(table,-1,sizeof(table));
    while(scanf("%lld",&money) ==1 )
    {
        ans=change(0,money);
        printf("%lld\n",ans);
    }
    return 0;
}

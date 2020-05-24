#include <stdio.h>
#include <string.h>

#define total_coins 5
#define ll long long

ll table[5][8000];
int coins[]={1,5,10,25,50};

ll change(int types,int money)
{
    if(money < 0)
        return 0;
    if(types >= total_coins)
        return 0;
    if(table[types][money] != -1)
        return table[types][money];
    if(money==0)
        return 1;

    return table[types][money] = change(types+1 , money) + change(types , money-coins[types]);
}

int main()
{
    ll money,res;
    memset(table,-1,sizeof(table));
    while(scanf("%lld",&money)==1)
    {
        res=change(0,money);
        printf("%lld\n",res);
    }
    return 0;
}

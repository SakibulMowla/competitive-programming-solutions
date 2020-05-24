#include <stdio.h>
#include <string.h>

#define ll long long
#define total_types 11

int notes[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
ll table[12][30000+5];

ll changes(ll types,ll money)
{
    if(money < 0)
        return 0;
    if(types >= total_types)
        return 0;
    if(table[types][money] != -1)
        return table[types][money];
    if(money==0)
        return 1;

    return table[types][money]=changes(types+1 , money) + changes(types , money-notes[types]);
}

int main()
{
    ll cent,ans,d,c;
    memset(table,-1,sizeof(table));
    while(scanf("%lld.%lld",&d,&c)==2)
    {
        cent=(d*100) + c;
        if(cent==0)break;
        ans=changes(0,cent);
        printf("%3lld.%02lld%17lld\n",d,c,ans);
    }
    return 0;
}

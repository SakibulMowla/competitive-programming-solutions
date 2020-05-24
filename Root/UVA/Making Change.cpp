#include "stdio.h"
#define SZ 1000+5

int min(int a,int b) { return a < b ? a : b; }

const int inf = 1<<28;

int dp[SZ];
int coin[] = {5,10,20,50,100,200};
int avail[6];

int ways(int val,int indx)
{
    if(val > 500 || val < -500) return inf;
    if(indx >= 6 && val <= 0) return dp[-val];
    if(indx >= 6 && val > 0) return inf;
    if(avail[indx] == 0) return ways(val,indx+1);
    else
    {
        int a,b;
        avail[indx]--;
        a = 1 + ways(val-coin[indx] , indx);
        avail[indx]++;
        b = ways(val , indx+1);
        return min(a,b);
    }
}

int main()
{
    int i,j,target,a,b;

    for(i=1;i<SZ;i++) dp[i] = inf;

    dp[0] = 0;

    for(i=0;i<6;i++)
        for(j=coin[i];j<SZ;j++)
            dp[j] = min(dp[j] , 1 + dp[j- coin[i] ]);

    while(scanf("%d%d%d%d%d%d",&avail[0],&avail[1],&avail[2],&avail[3],&avail[4],&avail[5]) == 6)
    {
        if( avail[0] + avail[1] + avail[2] + avail[3] + avail[4] + avail[5] == 0) break;
        scanf("%d.%d",&a,&b);
        target = (a*100) + b;
        printf("%3d\n",ways(target,0));
    }

    return 0;
}

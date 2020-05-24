#include "stdio.h"
#include "string.h"

template <class T> T max(T a,T b) { return a > b ? a : b; }
int a[15] , b[15] , c[15] , d[15] , dp[15][1010];
int n,m;

int solve(int indx,int dough)
{
    /*printf("indx = %d dough = %d\n",indx,dough);*/
    if(indx > m || dough == 0) return 0;
    int i,&ret = dp[indx][dough];
    if(ret != -1) return ret;
    ret = solve(indx+1,dough);
    i = 0;
    while(++i)
    {
        if(i*c[indx] <= dough && i*b[indx] <= a[indx])
            ret = max(ret , solve(indx+1 ,dough - (i*c[indx]) ) + (d[indx] * i) ) /*, printf("ret = %d\n",ret)*/;
        else break;
    }
    return ret;
}

int main()
{
    int i;
    while(scanf("%d %d %d %d",&n,&m,&c[0],&d[0]) == 4)
    {
        for(i=1;i<=m;i++)
            scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(0,n));
    }
    return 0;
}

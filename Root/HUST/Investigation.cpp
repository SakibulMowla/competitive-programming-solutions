#include "stdio.h"
#include "string.h"
#define SZ 12

int n , k , dp[SZ][2][90][90];
char arr[12];

int solve(int indx,int flag,int mod1,int mod2)
{
    if(indx == n)
    {
        if(mod1 == 0 && mod2 == 0) return 1;
        return 0;
    }
    int &ret = dp[indx][flag][mod1][mod2];
    if(ret != -1) return ret;
    int i , start = 0, end = 9;
    if(flag) end = arr[indx] - '0';
    ret = 0;
    for(i=start;i<end;i++)
        ret += solve(indx+1,0,(10*mod1+i)%k,(mod2+i)%k);
    ret += solve(indx+1,flag,(10*mod1+i)%k,(mod2+i)%k);
    return ret;
}

int main()
{
    int t=0,test,i,j,p,q,a,b;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %s %d",&a,arr,&k);
        if(k >= 90)
        {
            printf("Case %d: 0\n",++t);
            continue;
        }
        n = strlen(arr);
        for(i=0;i<=n;i++) for(j=0;j<2;j++)
        for(p=0;p<=k;p++) for(q=0;q<=k;q++)
            dp[i][j][p][q] = -1;
        b = solve(0,1,0,0);
        a--;
        sprintf(arr,"%d",a);
        n = strlen(arr);
        for(i=0;i<=n;i++) for(j=0;j<2;j++)
        for(p=0;p<=k;p++) for(q=0;q<=k;q++)
            dp[i][j][p][q] = -1;
        b = b - solve(0,1,0,0);
        printf("Case %d: %d\n",++t,b);
    }

    return 0;
}

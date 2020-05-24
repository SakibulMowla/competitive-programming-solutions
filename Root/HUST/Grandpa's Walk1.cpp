#include "stdio.h"

#define SZ 55

int arr[SZ][SZ] , dp[SZ][SZ]  , r , c;

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

int solve(int p,int q)
{
    int i,j,k,&ret = dp[p][q];
    if(ret != -1) return ret;
    ret  = 0;
    for(k=0;k<4;k++)
    {
        i = x[k] + p;
        j = y[k] + q;
        if(i>=0 && j >=0 && i< r && j < c && arr[i][j] < arr[p][q])
        {
            ret++;
            solve(i,j);
        }
    }
    return ret;
}

int main()
{
    int i,j,k,t=0,test,u,v,flag,res;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&r,&c);
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                scanf("%d",&arr[i][j]);
                dp[i][j] = -1;
            }
        res = 0;
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                flag = 1;
                for(k=0;k<4;k++)
                {
                    u = x[k] + i;
                    v = y[k] + j;
                    if(u>=0 && v >= 0 && u< r && v < c)
                    {
                        if(arr[u][v] > arr[i][j])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag)
                        res += solve(i,j), printf("*");
                }
            }
        printf("Case #%d: %d\n",++t,res);
    }

    return 0;
}

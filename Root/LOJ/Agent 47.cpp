#include "stdio.h"
#define SZ 15

int Set(int n,int pos) { return n = n | (1<<pos); }
int reset(int n,int pos) { return n = n & ~(1<<pos); }
int check(int n,int pos) { return n & (1<<pos); }

template <class T> T min(T a,T b) { return a < b ? a : b; }
int n , dp[(1<<SZ)+2] , arr[SZ+2][SZ+2] , health[SZ+2];
const int inf = 1<<28;

int solve(int mask)
{
    if(!mask) return 0;
    if(dp[mask] != -1) return dp[mask];
    int &ret = dp[mask] , i , j , cost , tmp;
    ret = inf;
    for(i=0;i<n;i++)
    {
        if(check(mask,i))
        {
            cost = health[i];
            tmp = mask;
            tmp = reset(tmp,i);
            ret = min(ret , cost + solve(tmp));
        }
    }

    for(i=0;i<n;i++)
    {
        if(!check(mask,i))
        for(j=0;j<n;j++)
        {
            if(check(mask,j) && arr[i][j] != 0)
            {
                cost = health[j] / arr[i][j];
                cost += ((health[j] % arr[i][j]) != 0);
                tmp = mask;
                tmp = reset(tmp,j);
                ret = min(ret , cost + solve(tmp));
            }
        }
    }

    return ret;
}

int main()
{
    int t=0,test,i,j;
    char ch;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&health[i]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf(" %c",&ch) , arr[i][j] = ch - '0' /*, printf("arr[%d][%d] = %d\n",i,j,arr[i][j])*/;
        j = (1<<n) + 2;
        for(i=0;i<j;i++) dp[i] = -1;
        printf("Case %d: %d\n",++t,solve((1<<n)-1));
    }

    return 0;
}

#include "stdio.h"
#include "string.h"

int Set(int &n,int pos) { n = n | (1<<pos); }
int reset(int &n,int pos) { n = n & ~(1<<pos); }
int check(int n,int pos) { return n & (1<<pos); }

template <class T> T min(T a,T b) { return a < b ? a : b; }

const int inf = 1<<28;
const int N = 12;
int dp[(1<<12)+2];

int solve(int mask)
{
    if(dp[mask] != -1) return dp[mask];
    int i , tmp , &ret = dp[mask];
    ret = 0;
    for(i=0; i<12; i++)
        if(check(mask,i))
            ret++;
    for(i=0; i<N-1; i++)
    {
        if(check(mask,i) && check(mask,i+1) && i+2 < N && !check(mask,i+2))
        {
            tmp = mask;
            reset(tmp,i);
            reset(tmp,i+1);
            Set(tmp,i+2);
            ret = min(ret , solve(tmp));
        }
        if(check(mask,i) && check(mask,i+1) && i-1 >= 0 && !check(mask,i-1))
        {
            tmp = mask;
            reset(tmp,i);
            reset(tmp,i+1);
            Set(tmp,i-1);
            ret = min(ret , solve(tmp));
        }
    }

    return ret;
}

char arr[15];

int main()
{
    int t,i,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",arr);
        n = 0;
        for(i=0; arr[i]; i++)
        {
            n *= 2;
            n += arr[i] == 'o';
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(n));
    }

    return 0;
}

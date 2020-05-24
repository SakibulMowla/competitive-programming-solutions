#include "stdio.h"
#define SZ 85

int Set(int n,int pos)
{
    return n = n | (1<<pos);
}
int reset(int n, int pos)
{
    return n = n & ~(1<<pos);
}
int check(int n,int pos)
{
    return n & (1<<pos);
}
template <class T> T max(T a,T b)
{
    return a > b ? a : b;
}

struct data
{
    int a,b,c,d;
};
data arr[SZ];
int n , dp[SZ][(1<<9)+2];
const int inf = 1<<28;

int solve(int pos,int mask)
{
    if(mask == (1<<9)-1)
    {
        /*printf("ret mask  %d\n",mask);*/return 0;
    }
    if(pos >= n) return -1;
    if(dp[pos][mask] != -2) return dp[pos][mask];
    int &ret = dp[pos][mask] , i, tmp;
    ret = -1;
    for(i=pos; i<n; i++)
    {
        if(!check(mask,arr[i].a-1) && !check(mask,arr[i].b-1) && !check(mask,arr[i].c-1) )
        {
//            printf("i = %d\n",i);
            tmp = mask;
            tmp = Set(tmp,arr[i].a-1);
            tmp = Set(tmp,arr[i].b-1);
            tmp = Set(tmp,arr[i].c-1);
//            printf("abc = %d %d %d  mask = %d\n",arr[i].a,arr[i].b,arr[i].c,mask);
//            printf("tmp = %d\n",tmp);
            if(solve(i+1,tmp) != -1)
                ret = max(ret,solve(i+1,tmp)+arr[i].d);
//            printf("sdh = %d\n",ret);
        }
    }
//    printf("ret = %d\n",ret);
    return ret;
}

int main()
{
    int t=0,i,k,j=(1<<9)+2;
    while(scanf("%d",&n) == 1 && n)
    {
        for(i=0; i<n; i++)
            scanf("%d %d %d %d",&arr[i].a,&arr[i].b,&arr[i].c,&arr[i].d);
        for(i=0; i<n; i++)
            for(k=0; k<j; k++)
                dp[i][k] = -2;
        printf("Case %d: %d\n",++t,solve(0,0));
    }

    return 0;
}

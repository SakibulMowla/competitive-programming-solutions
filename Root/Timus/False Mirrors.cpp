#include "stdio.h"
#define SZ 20

template <class T> T min(T a,T b) { return a < b ? a : b; }

int Set(int n,int pos) { return n = n | (1<<pos); }
int reset(int n,int pos) { return n = n & ~(1<<pos); }
int check(int n,int pos) { return n & (1<<pos); }

const int inf = 1<<28;
int n , dp[(1<<SZ)+2] , arr[SZ+2];



int solve(int mask)
{

    if(!mask) return 0;
//    printf("Mask = %d\n",mask);
    if(dp[mask] != -1) return dp[mask];
    int i , j , tmp , sum  , &ret = dp[mask];
    sum = 0;
    for(i=0;i<n;i++) if(check(mask,i)) sum += arr[i];
    ret = inf;
    for(i=0;i<n;i++)
    {
        if(check(mask,i))
        {
//            printf("yes\n");
            tmp = mask;
            j = sum - arr[i];
            tmp = reset(tmp,i);
            if(check(mask,(i+1)%n))
            {
                j -= arr[(i+1)%n];
                tmp = reset(tmp,(i+1)%n);
            }
            if(check(mask,(i+2)%n))
            {
                j -= arr[(i+2)%n];
                tmp = reset(tmp,(i+2)%n);
            }
            ret = min(ret,j+solve(tmp));
//            if(mask == 64) printf("tmp = %d j = %d sdjh = %d\n",tmp,j,ret);
        }
    }
//    printf("ret = %d\n",ret);
    return ret;
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    j = (1<<n) + 2;
    for(i=0;i<j;i++)
        dp[i] = -1;
    j -= 3;
    printf("%d\n",solve(j));

    return 0;
}

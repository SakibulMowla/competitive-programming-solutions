#include "stdio.h"
#include "math.h"
#define SZ 20

template <class T> T min(T a,T b) { return a < b ? a : b; }
const int inf = 1<<28;

int Set(int n,int pos) { return n = n | (1<<pos); }
int reset(int n,int pos) { return n = n & ~(1<<pos); }
int check(int n,int pos) { return n & (1<<pos); }

int n;
double dp[(1<<16)+2] ;
struct data { int x,y; };
data arr[20];
double dist[20][20];

double solve(int mask)
{
    if(mask == (1<<n)-1) return 0;
//    printf("mask1 = %d\n",mask);
    if(dp[mask] != -1) return dp[mask];
//    printf("mask2 = %d\n",mask);
    int i,j,tmp;
    double &ret=dp[mask];
    ret = inf;
    for(i=0;i<n;i++) if(!check(mask,i))
        for(j=0;j<n;j++) if(i!=j && !check(mask,j))
        {
            tmp = Set(mask,i);
            tmp = Set(tmp,j);
            ret = min(ret , solve(tmp)+dist[i][j]);
        }
    return ret;
}

int main()
{
    char str[30];
    int i,j,t=0;
    while(scanf("%d",&n) == 1 && n)
    {
        n = n * 2;
        for(i=0;i<n;i++)
            scanf("%s %d %d",str,&arr[i].x,&arr[i].y);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                dist[i][j] = dist[j][i] = sqrt(pow(arr[i].x-arr[j].x , 2) + pow(arr[i].y-arr[j].y , 2));

        j = (1<<n) + 2;
        for(i=0;i<j;i++) dp[i] = -1;
        printf("Case %d: %.2lf\n",++t,solve(0));
    }

    return 0;
}

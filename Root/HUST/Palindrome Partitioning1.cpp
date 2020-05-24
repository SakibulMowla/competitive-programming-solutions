#include "stdio.h"
#include "string.h"
#define SZ 1010

template <class T> T min(T a,T b) { return a < b ? a : b; }
const int inf = 1<<28;
bool palin[SZ][SZ];
int len , dp[SZ];
char arr[SZ];

void ispalin(int n)
{
    int i,j;
//    for(i=0;i<=n;i++) for(j=0;j<=n;j++) palin[i][j] = 0;
    for(i=0;i<n;i++) palin[i][i] = 1;
    for(i=0;i<n-1;i++) palin[i][i+1] = arr[i] == arr[i+1];
    for(j=2;j<n;j++)
        for(i=0;i+2<=j;i++)
            palin[i][j] = arr[i] == arr[j] && palin[i+1][j-1];
}

int solve(int indx)
{
    if(indx == len) return 0;
    int &ret = dp[indx];
    if(ret != -1) return ret;
    ret = inf;
    int i;
    for(i=indx;i<len;i++)
        if(palin[indx][i])
            ret = min(ret , 1+solve(i+1));
    return ret;
}

int main()
{
    int t=0,test,n,i;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",arr);
        len = n = strlen(arr);
        ispalin(n);
        for(i=0;i<=n;i++) dp[i] = -1;
//        while(scanf("%d %d",&i,&j) == 2 && (i || j))
//            printf("%d\n",palin[--i][--j]);
        printf("Case %d: %d\n",++t,solve(0));
    }

    return 0;
}

#include "stdio.h"
#define SZ 30

int n,sum,arr[SZ],ans[SZ],k;

void subset(int indx,int ansindx)
{
    if(indx == n)
    {
        int i,j=0;
        for(i=0;i<ansindx;i++) j += ans[i];
        j = (sum - j) - j;
        j < 0 ? j *= -1 : j;
        k = k > j ? j : k;
        return;
    }
    ans[ansindx] = arr[indx];
    subset(indx+1,ansindx+1);
    subset(indx+1,ansindx);
}

int main()
{
    int i;
    while(scanf("%d",&n) == 1)
    {
        k = 1<<28;
        sum = 0;
        for(i=0;i<n;i++) scanf("%d",&arr[i]) , sum += arr[i];
        subset(0,0);
        printf("%d\n",k);
    }

    return 0;
}

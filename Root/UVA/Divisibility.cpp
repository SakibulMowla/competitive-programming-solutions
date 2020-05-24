#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"

#define SZ 10010

int arr[SZ] , n , k;
bool found , prun[SZ][110];

void backtrack(int now,int indx)
{
    if(found)return;
    if(indx == n)
    {
        if(now % k == 0)found = true;
        return;
    }

    if(prun[indx][now] == 1) return;
    prun[indx][now] = 1;

    int tmp;

    tmp = now;
    tmp = (tmp + arr[indx]) % k;
    if(tmp<0) tmp += k;
    tmp %= k;
    backtrack(tmp , indx+1);

    tmp = now;
    tmp = (tmp - arr[indx]) % k;
    if(tmp<0) tmp += k;
    tmp %= k;
    backtrack(tmp , indx+1);
}

int main()
{
    int test,i;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&k);
        for(i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
            arr[i] %= k;
            if(arr[i] < 0) arr[i] += k;
        }
        for(i=0;i<=n;i++) memset(prun[i],0,sizeof(prun[i]));
        found = false;
        backtrack(arr[0],1);
        if(found)printf("Divisible\n");
        else printf("Not divisible\n");
    }

    return 0;
}

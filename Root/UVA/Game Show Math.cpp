#include "stdio.h"
#include "string.h"
#include "stdbool.h"

#define SZ 200
#define SD(n) scanf("%d",&n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)

bool found , mark[110][64005];
int arr[SZ] , ans[SZ] , num , target;
char sign[] = {'+','-','*','/'};

void bctk(int now,int indx)
{
    if(found) return;
    if(now > 32000 || now < -32000) return;
    if(mark[indx][now] == 1) return;
    int i;
    if(indx == num)
    {
        if(now == target)
        {
            printf("%d",arr[0]);
            FORI(i,1,num-1) printf("%c%d",sign[ans[i]],arr[i]);
            printf("=%d\n",target);
            found = true;
        }
        return;
    }
    mark[indx][now] = 1;
    FOR(i,4)
    {
        if(i == 0) ans[indx] = 0 , bctk(now+arr[indx] , indx+1);
        else if(i == 1) ans[indx] = 1 , bctk(now-arr[indx] , indx+1);
        else if(i == 2) ans[indx] = 2 , bctk(now*arr[indx] , indx+1);
        else if(i == 3) if(now%arr[indx] == 0) ans[indx] = 3 , bctk(now/arr[indx],indx+1);
    }
}

int main()
{
    int t,i,j;
    SD(t);
    while(t--)
    {
        SD(num);
        FOR(i,num) SD(arr[i]);
        SD(target);
        found = false;
        FORI(i,0,num)memset(mark[i],0,sizeof(mark[i]));
        bctk(arr[0],1);
        if(!found) printf("NO EXPRESSION\n");
    }

    return 0;
}

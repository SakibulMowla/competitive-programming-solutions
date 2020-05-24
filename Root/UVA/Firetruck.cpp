#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 1007

int used[SZ] ,ans[SZ], matrix[SZ][SZ] , valid[SZ], ways , desti ,p , q;

void check(int n)
{
    used[n] = 1;
    q++;
    valid[q] = n;
    int i;
    for(i=1;i<=p;i++)
        if( matrix[n][i] && !used[i] )
            check(i);
}

void bctk(int n,int x)
{
    int i;
    if(n == desti)
    {
        ways++;
        printf("%d",ans[1]);
        for(i=2;i<=x;i++)
            printf(" %d",ans[i]);
        printf("\n");
        return;
    }

    for(i=0;i<q;i++)
    {
        if( !used[valid[i]] && matrix[n][valid[i]] )
        {
            used[valid[i]] = 1;
            ans[x+1] = valid[i];
            bctk(valid[i] , x+1);
            used[valid[i]] = 0;
        }
    }
}

int main()
{
    int i,n,m,t=0;
    freopen("1.txt","r",stdin);
    while(scanf("%d",&desti) == 1)
    {
        memset(used,0,sizeof(used));
        memset(matrix,0,sizeof(matrix));
        p = q = 0;
        while(scanf("%d %d",&n,&m) == 2 && (n || m))
        {
            if(n > p) p = n;
            if(m > p) p = m;
            matrix[n][m] = matrix[m][n] = 1;
        }

        memset(used,0,sizeof(used));
        check(1);
        sort(valid,valid+q);
        memset(used,0,sizeof(used));
        printf("CASE %d:\n",++t);
        ways = 0;
        ans[1] = 1;
        used[1] = 1;
        bctk(1,1);
        printf("There are %d routes from the firestation to streetcorner %d.\n",ways,desti);
    }
    return 0;
}

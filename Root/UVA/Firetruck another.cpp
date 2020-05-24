#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define SZ 25

long used[SZ] ,ans[SZ], matrix[SZ][SZ] , valid[SZ], ways , desti ,p , q;

void check(long n)
{
    used[n] = 1;
    valid[q++] = n;
    long i;
    for(i=1;i<=p;i++)
        if( matrix[n][i] && !used[i] )
            check(i);
}

void bctk(long n,long x)
{
    long i;
    if(n == desti)
    {
        ways++;
        printf("%ld",ans[1]);
        for(i=2;i<=x;i++)
            printf(" %ld",ans[i]);
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
    long i,n,m,t=0;
//    freopen("1.txt","r",stdin);
    while(scanf("%ld",&desti) == 1)
    {
        memset(used,0,sizeof(used));
        memset(matrix,0,sizeof(matrix));
        p = q = 0;
        while(scanf("%ld %ld",&n,&m) == 2 )
        {
            if(n == 0 && m == 0) break;
            if(n > p) p = n;
            if(m > p) p = m;
            matrix[n][m] = matrix[m][n] = 1;
        }

        memset(used,0,sizeof(used));
        check(desti);
        sort(valid,valid+q);
        memset(used,0,sizeof(used));
        printf("CASE %ld:\n",++t);
        ways = 0;
        ans[1] = 1;
        used[1] = 1;
        bctk(1,1);
        printf("There are %ld routes from the firestation to streetcorner %ld.\n",ways,desti);
    }
    return 0;
}

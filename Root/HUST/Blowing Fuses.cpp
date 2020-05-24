#include "stdio.h"
#include "string.h"
#include "math.h"
#include "iostream"

using namespace std;

#define SZ 25

int main()
{
    int i,j,k,n,m,c,flag,maxim,t=0;
    int cap[SZ];
    bool con[SZ];
    while(scanf("%d %d %d",&n,&m,&c) == 3 &&(n+m+c))
    {
        memset(con,0,sizeof(con));
        flag = k = maxim = 0;
        for(i=1;i<=n;i++) scanf("%d",cap+i);
        for(i=1;i<=m;i++)
        {
            scanf("%d",&j);
            if(con[j] == 0)
            {
                con[j] = 1;
//                printf("con = %d\n",con[j]);
                k += cap[j];
                if(k > maxim) maxim = k;
                if(k > c) flag = 1;
            }
            else if(con[j] == 1)
            {
                con[j] = 0;
                k -= cap[j];
//                if(k > maxim) maxim = k;
            }
//            printf("k = %d\n",k);
        }
//        printf("max = %d\n",maxim);
        printf("Sequence %d\n",++t);
        if(flag == 1) printf("Fuse was blown.\n\n");
        else
        {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n\n",maxim);
        }
    }

    return 0;
}

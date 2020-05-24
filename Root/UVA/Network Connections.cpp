#include <stdio.h>
#include <string.h>

#define SZ 100000

int par[SZ];

int find(int r)
{
    if(par[r] != r)
        par[r] = find(par[r]);
    return par[r];
}


int main()
{
    int test,n,i,k,p,q,con,dis,a,b,t;
    char ch;
    scanf("%d",&test);
    for(t=0;t<test;t++)
    {
        scanf("%d",&n);
        getchar();
        for (int i=1; i<=n ; i++ )
            par[i] = i;
        con = 0;
        dis = 0;
        while(scanf("%c",&ch) == 1)
        {
            if(ch == '\n')break;
            scanf("%d %d",&a,&b);
            getchar();
            if(ch == 'c')
            {
                par[find(a)] = find(b);
            }
            else if(ch == 'q')
            {
                p = find(a);
                q = find(b);
                if(p == q)con++;
                else dis++;
            }
        }
        if(t)printf("\n");
        printf("%d,%d\n",con,dis);
    }
    return 0;
}

#include "stdio.h"
#define SZ 30010

int par[SZ],cycle[SZ];

void init(int n)
{
    int i;
    for(i=0; i<=n; i++)
    {
        par[i] = i;
        cycle[i] = 1;
    }
}

int find(int n)
{
    if(n == par[n]) return n;
    return par[n] = find(par[n]);
}

//void Union(int a,int b)
//{
//    a = find(a);
//    b = find(b);
//    if(cycle[a] < cycle[b])
//    {
//        par[b] = a;
//        cycle[a] += cycle[b];
//    }
//    else
//    {
//        par[a] = b;
//        cycle[b] += cycle[a];
//    }
//}

void Union(int a,int b)
{
    par[find(a)] = find(b);
}

int main()
{
    int i,j,k,n,m,p,s,t;
    while(scanf("%d %d",&n,&m) == 2 && (n+m))
    {
        init(n);
        for(i=0; i<m; i++)
        {
            scanf("%d",&k);
            if(k == 0) continue;
            scanf("%d",&s);
            s = find(s);
            for(p=0; p<k-1; p++)
            {
                scanf("%d",&t);
                t = find(t);
                if(s != t) Union(s,t);
            }
        }
        i = find(0);
        k = 0;
        for(j=0;j<n;j++)
            if(i == find(j))
              k++;
        printf("%d\n",k);
    }

    return 0;
}

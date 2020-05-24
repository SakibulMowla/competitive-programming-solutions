#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "iostream"
#define SZ 5010
using namespace std;

map <string , int> M;
int cycle[SZ] , par[SZ] , maxim;

void init(int n)
{
    int i;
    M.clear();
    maxim = 0;
    for(i=0;i<=n;i++)
    {
        par[i] = i;
        cycle[i] = 1;
    }
}

int find(int r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void Union(int a,int b)
{
    if(cycle[a] < cycle[b])
    {
        par[b] = a;
        cycle[a] += cycle[b];
        if(cycle[a] > maxim) maxim = cycle[a];
    }
    else
    {
        par[a] = b;
        cycle[b] += cycle[a];
        if(cycle[b] > maxim) maxim = cycle[b];
    }
}

int main()
{
    int i,j,k,l,n,r;
    char arr[100],str[100];
    while(scanf("%d %d",&n,&r) == 2 &&(n+r))
    {
        init(n);
        for(i=1;i<=n;i++)
        {
            scanf(" %[^\n]",arr);
            M[arr] = i;
//            printf("i = %d n = %d\n",i,n);
        }
        for(i=1;i<=r;i++)
        {
//            printf("i = %d r = %d\n",i,r);
            scanf("%s",arr);
            scanf("%s",str);
            j = M[arr];
            k = M[str];
            j = find(j);
            k = find(k);
            if(j != k)
                Union(j,k);
        }
        if(maxim == 0 && n) maxim++;
        printf("%d\n",maxim);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 510
#define Union(a,b) par[find(a)] = find(b)

int par[SZ],matrix[SZ][SZ],cnt[510];

int find(int r)
{
    return par[r] == r ? r : par[r] = find(par[r]);
}

void makeset(int n)
{
    for(int i=0; i<=n; i++)
    {
        par[i] = i ;
        cnt[i] = 0;
    }
}

const int ninf = 1 << 31; // 1 << 31 = -2147483648

int main()
{
    int n,e,i,j,a,b,maxppa,ppa,cities;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&n,&e) == 2)
    {
        if(n==0 && e==0)break;
        makeset(n);
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                matrix[i][j] = ninf;
        maxppa = ninf;
        for(i=1; i<=e; i++)
        {
            scanf("%d %d %d",&a,&b,&ppa);
            if(ppa > matrix[a][b])
                matrix[a][b] = matrix[b][a] = ppa;
            maxppa = max(maxppa,ppa);
        }
        for(i=1; i<=n; i++)
            for(j=i+1; j<=n; j++)
                if(matrix[i][j] == maxppa)
                    Union(i,j);
        cities = 0;
        for(i=1; i<=n; i++)
            cities = max(cities,++cnt[find(i)]);
        printf("%d\n",cities);
    }

    return 0;
}

#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

int parent[50010];
#define makeset(n) parent[n] = n
#define Union(a,b) parent[find(a)] = find(b)

int find(int r)
{
    if(r == parent[r])
        return r;
    return parent[r] = find(parent[r]);
}

int main()
{
    int n,m,i,j,k,Case;
    map <int , int> M;

    Case = 0;
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n==0 && m==0)break;
        for(k=1;k<=n;k++)
            makeset(k);
        for(k=1;k<=m;k++)
        {
            scanf("%d %d",&i,&j);
            i = find(i);
            j = find(j);
            Union(i,j);
        }
        M.clear();
        for(k=1;k<=n;k++)
        {
            M[find(k)]++;
        }

        printf("Case %d: %d\n",++Case,M.size());
    }

    return 0;
}

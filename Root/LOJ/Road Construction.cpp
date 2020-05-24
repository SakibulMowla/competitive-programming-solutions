#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

#define Union(a,b) par[find(a)]  = find(b)
#define SZ 110

struct data
{
    int a,b,c;
};

bool comp(data p,data q)
{
    return p.c < q.c;
}

int par[SZ];
vector <data> input;
map <string , int> msi;

int find(int r)
{
    if(par[r] == r)
        return r;
    return par[r] = find(par[r]);
}

void init(int n)
{
    for(int i=0; i<=n; i++)
        par[i] = i;
}

int mst(int j)
{
    sort(input.begin(),input.end(),comp);
    int i,p,q,cost,nodes;
    cost = nodes = 0;
    for(i=0; i<input.size(); i++)
    {
        if(input[i].c != 0)
        {
            p = find(input[i].a);
            q = find(input[i].b);
            if(p != q)
            {
                nodes++;
                Union(p,q);
                cost += input[i].c;
            }
        }
    }
    if(nodes == j-1) return cost;
    return -1;
}

int main()
{
    data u;
    int i,j,m,k,t,test;
    char city1[100] , city2[100];
    scanf("%d",&test);
    t = 0;
    while(test--)
    {
        input.clear();
        msi.clear();
        scanf("%d",&m);
        j = k = 0;
        init(105);
        while(m--)
        {
            scanf("%s %s %d",city1,city2,&i);
            if(msi.find(city1) == msi.end()) msi[city1] = j++;
            if(msi.find(city2) == msi.end()) msi[city2] = j++;
            if(i == 0)
            {
                if(find(msi[city1]) != find(msi[city2]))
                    k++ , Union(msi[city1] , msi[city2]);
            }

            u.a = msi[city1];
            u.b = msi[city2];
            u.c = i;
            input.push_back(u);

        }

        i = mst(j-k);
        if(i == -1) printf("Case %d: Impossible\n",++t);
        else printf("Case %d: %d\n",++t,i);
    }

    return 0;
}

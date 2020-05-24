#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 110
#define Union(a,b) par[find(a)] = find(b)

int par[SZ];

struct data
{
    int a,b,c;
};

vector <data> input;

int find(int r)
{
    if(par[r] == r)
        return r;
    return par[r] = find(par[r]);
}

bool comp1(data p,data q)
{
    return p.c > q.c;
}

void init(int n)
{
    int i;
    for(i=0; i<=n; i++)
        par[i] = i;

}

int max_mst(int nodes)
{
    init(nodes);
    sort(input.begin(),input.end(),comp1);
    int i,n,m,cost;
    cost = 0;
    for(i=0; i<input.size(); i++)
    {
        n = find(input[i].a);
        m = find(input[i].b);
        if(n != m)
        {
            Union(n,m);
            cost += input[i].c;
        }
    }
    return cost;
}

int min_mst(int nodes)
{
    init(nodes);
    int i,n,m,cost;
    cost = 0;
    for(i=input.size()-1; i>=0; i--)
    {
        n = find(input[i].a);
        m = find(input[i].b);
        if(n != m)
        {
            Union(n,m);
            cost += input[i].c;
        }
    }
    return cost;
}

int main()
{
    data u;
    int n,p,q,r,test,t,r1,r2;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        input.clear();
        scanf("%d",&n);
        while(scanf("%d %d %d",&p,&q,&r) == 3)
        {
            if(p == 0 && q == 0 && r == 0) break;
            u.a = p , u.b = q , u.c = r;
            input.push_back(u);
        }
        r1 = max_mst(n);
        r2 = min_mst(n);
        if((r1+r2) % 2 == 0) printf("Case %d: %d\n",++t,(r1+r2)/2);
        else printf("Case %d: %d/2\n",++t,r1+r2);
    }

    return 0;
}

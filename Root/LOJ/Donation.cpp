#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define Union(a,b) par[find(a)] = find(b)
#define SZ 55

struct data { int a,b,c; };
bool comp(data p,data q) {return p.c < q.c ;};

vector <data> input;
int par[SZ];

int find(int r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void init(int n)
{
    for(int i=0;i<=n;i++) par[i] = i;
    input.clear();
}

int mst(int n)
{
    sort(input.begin(),input.end(),comp);
    int i,cost,p,q,edges;
    cost = edges = 0;
    for(i=0;i<input.size();i++)
    {
        p = find(input[i].a);
        q = find(input[i].b);
        if(p != q)
        {
            edges++;
            cost += input[i].c;
            Union(p,q);
        }
    }
    if(edges == n-1) return cost;
    return -1;
}

int main()
{
    data u;
    int n,t,test,i,j,cost,sum;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        init(n);
        sum = 0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&cost);
                if(i != j && cost > 0)
                {
                    u.a = i , u.b = j , u.c = cost;
                    input.push_back(u);
                }
                sum += cost;
            }
        cost = mst(n);
        if(cost == -1) printf("Case %d: -1\n",++t);
        else printf("Case %d: %d\n",++t,sum-cost);
    }

    return 0;
}

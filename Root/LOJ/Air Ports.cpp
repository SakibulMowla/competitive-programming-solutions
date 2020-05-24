#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N , M , A;

#define SZ 10010
#define Union(a,b) par[find(a)] = find(b)

struct data { int a,b,c; };
bool comp(data p,data q){return p.c < q.c;};

vector <data> input;
int par[SZ];

int find(int r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void mst()
{
    int airports,cost,i,p,q;
    airports = cost = 0;
    for(i=0;i<input.size();i++)
    {
        if(input[i].c < A)
        {
            p = find(input[i].a);
            q = find(input[i].b);
            if(p != q)
            {
                cost += input[i].c;
                Union(p,q);
            }
        }
    }
    for(i=1;i<=N;i++)
        if(par[i] == i)
            airports++ , cost += A;
    printf("%d %d\n",cost,airports);
}

void take_input()
{
    input.clear();
    data u;
    scanf("%d %d %d",&N,&M,&A);
    for(int i=1;i<=N;i++) par[i] = i;
    for(int i=0;i<M;i++) scanf("%d %d %d",&u.a,&u.b,&u.c) , input.push_back(u);
    sort(input.begin(),input.end(),comp);
}

int main()
{
    int t,test;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        take_input();
        printf("Case %d: ",++t);
        mst();
    }

    return 0;
}

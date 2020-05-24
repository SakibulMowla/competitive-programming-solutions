#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int par[5010];
int cycle[5010];

int find(int r)
{
    if(r!=par[r])
        par[r]=find(par[r]);
    return par[r];
}

void Union(int a,int b)
{
    if(cycle[a]<cycle[b])
        par[b]=a,cycle[a]+=cycle[b];
    else
        par[a]=b,cycle[b]+=cycle[a];
    return;
}

void makeset(int n)
{
    for(int i=1; i<=n; i++)
        par[i]=i,cycle[i]=1;
    return;
}

int main()
{
    int c,r,i,x,y;
    char node[35],node1[35];
    map<string,int>M;

    while(scanf("%d %d",&c,&r)==2)
    {
        if(c==0 && r==0)break;
        M.clear();
        memset(par,0,sizeof(par));
        memset(cycle,0,sizeof(cycle));
        makeset(c);
        for(i=1; i<=c; i++)
        {
            scanf("%s",node);
            M[node]=i;
        }
        for(i=1; i<=r; i++)
        {
            scanf("%s %s",&node,&node1);
            x=M[node];
            y=M[node1];
            x=find(x);
            y=find(y);
            if(x!=y)
                Union(x,y);
        }
        int res=0;
        for(i=1; i<=c; i++)
            res=cycle[i]>res?cycle[i]:res;
        printf("%d\n",res);
    }

    return 0;
}

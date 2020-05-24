#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 110

vector <int> V[SZ] , adj[SZ] , pos , best;

int dim , box , taken[SZ];

bool comp(int i,int j)
{
    int k;
    for(k=0; k<dim; k++)
    {
        if(V[i][k] <= V[j][k])
            return false;
    }
    return true;
}

void bctk(int n)
{
    if(pos.size() > best.size())
        best = pos;
    int i;
    for(i=0; i<adj[n].size(); i++)
    {
        if( !taken[adj[n][i]] )
        {
            taken[adj[n][i]] = 1;
            pos.push_back(adj[n][i]);
            bctk(adj[n][i]);
            pos.pop_back();
            taken[adj[n][i]] = 0;
        }
    }
}

int main()
{
    int i,j,k;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&box,&dim) == 2)
    {
        for(i=0; i<box; i++)
            for(j=0; j<dim; j++)
            {
                scanf("%d",&k);
                V[i].push_back(k);
            }
        for(i=0; i<box; i++)
            sort(V[i].begin(),V[i].end());

        for(i=0; i<box; i++)
        {
            for(j=i+1; j<box; j++)
            {
                if(comp(i,j))  adj[i].push_back(j);
                if(comp(j,i))  adj[j].push_back(i);
            }
        }

        for(i=0; i<box; i++)
        {
            taken[i] = 1;
            pos.clear();
            pos.push_back(i);
            bctk(i);
            taken[i] = 0;
        }
        printf("%d\n",best.size());
        printf("%d",best[ best.size()-1 ]+1);
        for(i=best.size()-2; i>=0; i--)
            printf(" %d",best[i]+1);
        printf("\n");
        pos.clear();
        best.clear();
        for(i=0; i<box; i++)
        {
            V[i].clear();
            adj[i].clear();
        }

    }

    return 0;
}

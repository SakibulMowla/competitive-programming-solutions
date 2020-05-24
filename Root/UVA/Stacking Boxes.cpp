#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 110

vector <int> V[SZ] , adj[SZ];

int dim;

bool comp(int i,int j)
{
    int k;
    for(k=0;k<dim;k++)
    {
        if(V[i][k] <= V[j][k])
            return false;
    }
    return true;
}

int main()
{
    int box,i,j,k;
    while(scanf("%d %d",&box,&dim) == 2)
    {
        for(i=0; i<box; i++)
            for(j=0; j<dim; j++)
            {
                scanf("%d",&j);
                V[i].push_back(j);
            }
        for(i=0; i<box; i++)
            sort(V[i].begin(),V[i].end());
        sort(V[0].begin(),V[0].end());
        for(i=0;i<box;i++)
        {
            for(j=i+1;j<box;j++)
            {
                if(comp(i,j)) adj[i].push_back(j);
                if(comp(j,i)) adj[j].push_back(i);
            }
        }
        for(i=0; i<box; i++)
        {
            printf("adj %d\n",i+1);
            for(j=0; j<adj[i].size(); j++)
            {
                printf("%d ",adj[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

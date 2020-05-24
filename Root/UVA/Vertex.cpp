#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define SZ 110

int n;

vector <int> adj[SZ];
bool color[SZ];
int cnt;

void dfs(int s)
{
    int i,j;
    for(i=0;i<adj[s].size();i++)
    {
        j = adj[s][i];
        if(color[j] == 0 && j<=n)
        {
            color[j] = 1;
            cnt++;
            dfs(j);
        }
    }
}

int main()
{
    int m,i,j,k,l;
//    freopen("1.txt","r",stdin);
    while(scanf("%d",&n) == 1 && n)
    {
        while(scanf("%d",&m) == 1 && m)
        {
            while(scanf("%d",&k) == 1 && k)
            {
                adj[m].push_back(k);
            }
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&k);
            for(i=1;i<=n;i++)   color[i] = 0;
            cnt = 0;
            dfs(k);
            cnt = n - cnt;
            printf("%d",cnt);
            for(i=1; i<=n; i++)
            {
                if(color[i] == 0)
                {
                    if(cnt) printf(" ");
                    printf("%d",i);
                    cnt--;
                }
            }
            printf("\n");
        }

        for(i=1; i<=n; i++)
            adj[i].clear();
    }

    return 0;
}

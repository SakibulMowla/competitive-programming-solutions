#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

#define SZ 110

int in[SZ] , col[SZ] , cnt;
vector <int> adj[SZ];
map <int , int> M;

void dfs(int root)
{
    int i;
    for(i=0;i<adj[root].size();i++)
    {
        if(!col[ adj[root][i] ])
        {
            col[ adj[root][i] ] = 1;
            cnt++;
            dfs( adj[root][i] );
        }
    }

}

int main()
{
    int flag,t=0,i,n,m,nodes,root,rootcnt,valid;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n == -1 && m == -1) break;
        for(i=0;i<SZ;i++)
        {
            in[i] = 0;
            col[i] = 0;
            adj[i].clear();
        }
        M.clear();

        if(n == 0 && m == 0)
        {
            printf("Case %d is a tree.\n",++t);
            continue;
        }

        nodes = 0;
        flag = 1;

        if(M.find(n) == M.end()) M[n] = nodes++;
        if(M.find(m) == M.end()) M[m] = nodes++;
        in[ M[m] ] ++;
        adj[ M[n] ].push_back( M[m] );

        if(n == m) flag = 0;

        while(scanf("%d %d",&n,&m) == 2)
        {
            if(n == 0 && m == 0) break;
            if(M.find(n) == M.end()) M[n] = nodes++;
            if(M.find(m) == M.end()) M[m] = nodes++;
            adj[ M[n] ].push_back( M[m] );
//            printf("m = %d Mm = %d\n",m,M[m]);
            in[ M[m] ] ++;
            if(n == m) flag = 0;
        }

        if( !flag )
        {
//            printf("here\n");
            printf("Case %d is not a tree.\n",++t);
            continue;
        }

        valid = 0 , rootcnt = 0;

        for(i=0;i<nodes;i++)
        {
            if(in[i] == 0)
            {
                root = i;
//                printf("root = %d\n",root);
                rootcnt++;
            }
            if(in[i] > 1)
                valid++ /*, printf("v = %d\n",i)*/;
        }

        if(rootcnt != 1 || valid)
        {
//            printf("here\n");
//            printf("rc = %d va = %d\n",rootcnt,valid);
            printf("Case %d is not a tree.\n",++t);
            continue;
        }

        cnt = 1;
        col[root] = 1;
        dfs(root);

        if(cnt == nodes) printf("Case %d is a tree.\n",++t);
        else printf("Case %d is not a tree.\n",++t);

        for(i=0;i<SZ;i++) adj[i].clear();
    }

    return 0;
}

#include "stdio.h"
#include "vector"
#include "iostream"
#include "stack"

using namespace std;

#define SZ 20010

vector <int> edge[SZ];
int indx[SZ] , low[SZ], under[SZ] , cnt , scccnt;
bool visited[SZ] , in[SZ] , out[SZ];
stack <int> stk;

void init(int n)
{
    int i;
    cnt = scccnt = 0;
    for(i=0; i<=n; i++)
    {
        in[i] = out[i] = low[i] = under[i] = 0;
        indx[i] = -1;
        edge[i].clear();
        visited[i] = false;
    }
}

void tarjan(int n)
{
    stk.push(n);
    low[n] = indx[n] = ++cnt;
    visited[n] = true;
    int i,j;
    for(i=0; i<edge[n].size(); i++)
    {
        j = edge[n][i];
        if(indx[j] == -1)
        {
            tarjan(j);
            low[n] = min(low[n] , low[j]);
        }
        else if(visited[j] == true)
            low[n] = min(low[n] , low[j]);
    }
    if(indx[n] == low[n])
    {
        scccnt++;
        j = -1;
        while(j != n)
        {
            j = stk.top();
            under[j] = scccnt;
            stk.pop();
            visited[j] = false;
        }
    }
}

void dfs(int n)
{
    int i,v;
    visited[n] = true;
    for(i=0;i<edge[n].size();i++)
    {
        v = edge[n][i];
        if(under[v] != under[n])
        {
            in[under[v]]++;
            out[under[n]]++;
        }
        if(visited[v] == false)
            dfs(v);
    }
}

int main()
{
    int t,test,n,m,i,j,k,in1,out1;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        init(n);
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&j,&k);
            edge[j].push_back(k);
        }
        for(i=1; i<=n; i++)
            if(indx[i] == -1)
               tarjan(i);
        for(i=0; i<=n; i++) visited[i] = false;
        for(i=1; i<=n; i++) if(!visited[i]) dfs(i);
        in1 = out1 = 0;
        if(scccnt == 1) scccnt = 0;
        else
        {
            for(i=1; i<=scccnt; i++)
            {
                if(in[i] == 0) in1++;
                if(out[i] == 0) out1++;
            }
            scccnt = max(in1,out1);
        }
        printf("Case %d: %d\n",++t,scccnt);
    }

    return 0;
}

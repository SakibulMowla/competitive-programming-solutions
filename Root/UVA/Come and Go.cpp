#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
#include "stack"

using namespace std;

#define SZ 2000

vector <int> edge[SZ];
int indx[SZ] , low[SZ] , cnt , scccnt;
stack <int> stk;
bool visited[SZ];

void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        edge[i].clear();
        indx[i] = -1;
        low[i] = 0;
        visited[i] = false;
    }
    while( !stk.empty() ) stk.pop();
    cnt = scccnt = 0;
}

void tarjan(int n)
{
    low[n] = indx[n] = cnt++;
    visited[n] = true;
    stk.push(n);
    int i,j;
    for(i=0;i<edge[n].size();i++)
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
    if(low[n] == indx[n])
    {
        scccnt++;
        j = -1;
        while(n != j)
        {
            j = stk.top();
            stk.pop();
            visited[j] = false;
        }
    }
}

int main()
{
    int i,j,k,n,m,u,v,p;
    while(scanf("%d %d",&n,&m) == 2 && (n+m))
    {
        init(n);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&p);
            edge[u].push_back(v);
            if(p == 2)
            edge[v].push_back(u);
        }
        tarjan(1);
        if(scccnt == 1 && cnt == n) printf("1\n");
        else printf("0\n");
    }

    return 0;
}

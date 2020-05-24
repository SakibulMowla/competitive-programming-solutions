#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "map"
#include "math.h"
#include "queue"
#include "stack"
#include "algorithm"
#include "iostream"

using namespace std;

#define inf 1<<28
#define SZ 10010

vector <int> edge[SZ];
bool col[SZ];
stack <int> stk;

void dfs(int n)
{
    col[n] = 1;
    int i,j;
    for(i=0;i<edge[n].size();i++)
    {
        j = edge[n][i];
        if(col[j] == 0)
            dfs(j);
    }
}

int main()
{
    int t=0,test,n,m,i,j,k;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++)
            edge[i].clear() , col[i] = 0;
        while( !stk.empty() ) stk.pop();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&j,&k);
            edge[j].push_back(k);
        }
        for(i=1;i<=n;i++)
            if(col[i] == 0)
                dfs(i) , stk.push(i);
        memset(col,0,sizeof(bool)*(n+1));
        j = 0;
        while( !stk.empty() )
        {
            k = stk.top();
            stk.pop();
            if(col[k] == 0)
                dfs(k) , j++;
        }
        printf("Case %d: %d\n",++t,j);
    }

    return 0;
}

#include "stdio.h"
#include "string.h"
#include "vector"
#include "stack"
#include "iostream"

using namespace std;

#define SZ 10010

vector <int> edge[SZ];
bool color[SZ];
stack <int> stk;

void dfs(int n)
{
    int i,j;
    color[n] = true;
    for(i=0;i<edge[n].size();i++)
    {
        j = edge[n][i];
        if(color[j] == false)
            dfs(j);
    }
}

int main()
{
//    freopen("1.txt","r",stdin);
    int test,t,i,j,k,n,m;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);

        for(i=0;i<=n;i++) edge[i].clear();
        memset(color,0,sizeof(bool)*(n+1));
        while( !stk.empty() ) stk.pop();

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&j,&k);
            edge[j].push_back(k);
        }

        for(i=1;i<=n;i++)
        {
            if(color[i] == false) dfs(i) , stk.push(i);
        }
        memset(color,0,sizeof(bool)*(n+1));
        j = 0;
        while( !stk.empty() )
        {
            k = stk.top();
            stk.pop();
            if(color[k] == 0) dfs(k) ,  j++;
        }

        printf("Case %d: %d\n",++t,j);
    }

    return 0;
}

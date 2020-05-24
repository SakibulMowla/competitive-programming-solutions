#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

using namespace std;

vector <int> v[110];
bool visited[110];
int count;

void dfs(int n)
{
    visited[n] = 1;
    int i;
    for(i=0; i<v[n].size(); i++)
    {
        if(!visited[v[n][i]])
        {
            count++;
            dfs(v[n][i]);
        }
    }
}

int main()
{
    int n,t,i,j,num,maxim,ans;
//    freopen("1.txt","r",stdin);
    while(scanf("%d",&n) && n)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d",&t);
            for(j=1; j<=t; j++)
            {
                scanf("%d",&num);
                v[i].push_back(num);
            }
        }
        maxim = 0;
        for(i=1; i<=n; i++)
        {
            memset(visited,0,sizeof(visited));
            count = 0;
            dfs(i);
            if(count > maxim)
                ans = i , maxim = count;
        }
        printf("%d\n",ans);
        for(i=1; i<=n; i++)
            v[i].clear();
    }

    return 0;
}

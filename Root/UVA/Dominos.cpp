#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

bool color[100010];
vector <int> v[100010];

void DFS(int n)
{
    int i;
    color[n] = 1;
    for(i=0;i<v[n].size();i++)
    {
        if(color[v[n][i]] == 0)
            DFS(v[n][i]);
    }

    return;
}

void DFS1(int n)
{
    int i;
    color[n]=0;
    for(i=0;i<v[n].size();i++)
    {
        if(color[v[n][i]] == 1)
            DFS1(v[n][i]);
    }

    return;
}

int main()
{
    int i,n,m,test,node1,node2,count;
    stack <int> s;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&node1,&node2);
            v[node1].push_back(node2);
        }
        for(i=1;i<=n;i++)
        {
            if(color[i] == 0)
            {
                s.push(i);
                DFS(i);
            }
        }
        count = 0;
        while( !s.empty() )
        {
            if(color[s.top()] == 1)
            {
                count++;
                color[s.top()]=0;
                DFS1(s.top());
            }
            s.pop();
        }
        printf("%d\n",count);
        for(i=1;i<=n;i++)
            v[i].clear();
        memset(color,0,sizeof(color));
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define SZ 20010
#define pb push_back

vector <int> v[SZ];
map <int ,int> m;
queue <int> q;
int color[SZ];
int nodes,max_race;

void BFS(int src)
{
    int race1,race2,u,i;
    race1 = race2 = 0;
    q.push(src);
    color[src] = 1;
    race1++;

    while( !q.empty() )
    {
        u = q.front();
        q.pop();
        for(i=0;i<v[u].size();i++)
        {
            if(color[v[u][i]] == 0)
            {
                if(color[u] == 1)
                {
                    color[v[u][i]] = 2;
                    race2++;
                    q.push(v[u][i]);
                }
                else if(color[u] == 2)
                {
                    color[v[u][i]] = 1;
                    race1++;
                    q.push(v[u][i]);
                }
            }
        }
    }
    max_race += max(race1 , race2);

    return;
}

int main()
{
    int t,test,node1,node2,i,j,k,l,fights;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        max_race = 0;
        nodes = 0;
        m.clear();
        while( !q.empty() ) q.pop();
        memset(color,0,sizeof(color));
        scanf("%d",&fights);
        for(i=1;i<=fights;i++)
        {
            scanf("%d %d",&node1,&node2);
            if(m.find(node1) == m.end()) m[node1] = ++nodes;
            if(m.find(node2) == m.end()) m[node2] = ++nodes;
            v[m[node1]].pb(m[node2]);
            v[m[node2]].pb(m[node1]);
        }
        for(i=1;i<=nodes;i++)
        {
            if(color[i] == 0)
                BFS(i);
        }
        printf("Case %d: %d\n",t,max_race);
        for(i=0;i<=nodes;i++)
            v[i].clear();
    }

    return 0;
}

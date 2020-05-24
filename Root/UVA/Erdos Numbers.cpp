            //10044 - Erdos Numbers
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
map <string , int> m;
vector <int> v[5010];
queue <int> q;
int nodes , edros_num[5010] , map_num[510] , visited[5010];

void take_input()
{
    int i,j,k;
    char line[1000],arr[110];
    scanf(" %[^\n]",line);
    k = i = j = 0;
    while(1)
    {
        if(line[k] == ':')
        {
            if(line[k-1] == '.')
            {
                arr[i] = '\0';
                if(m.find(arr) == m.end())
                    m[arr] = ++nodes;
                map_num[++j] = m[arr];
            }
            break;
        }
        if(line[k] == ',' && line[k-1] == '.')
        {
            arr[i] = '\0';
            i = 0;
            if(m.find(arr) == m.end())
                m[arr] = ++nodes;
            map_num[++j] = m[arr];
            k++;
            continue;
        }
        if(i==0 && line[k] == ' ')
        {
            k++;
            continue;
        }
        arr[i++] = line[k];
        k++;
    }
    for(i=1;i<=j;i++)
        for(k=i+1;k<=j;k++)
        {
            v[map_num[i]].push_back(map_num[k]);
            v[map_num[k]].push_back(map_num[i]);
        }
}

void BFS(int start)
{
    int i,u;
    edros_num[start] = 0;
    visited[start] = 1;
    q.push(start);
    while( !q.empty() )
    {
        u = q.front();
        q.pop();
        for(i=0;i<v[u].size();i++)
        {
            if( !visited[v[u][i]] )
            {
                q.push(v[u][i]);
                visited[v[u][i]] = 1;
                edros_num[v[u][i]] = edros_num[u] + 1;
            }
        }
    }
}
int main()
{
    int t,test,p,n,i;
    char name[200];
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        nodes = 0;
        m["Erdos, P."] = ++nodes;
        scanf("%d %d",&p,&n);
        for(i=1; i<=p; i++)
            take_input();
        for(i=0;i<=nodes;i++)
            edros_num[i] = -1 , visited[i] = 0;
        BFS(1);
        printf("Scenario %d\n",t);
        for(i=1; i<=n; i++)
        {
            scanf(" %[^\n]",name);
            if(m.find(name) == m.end()   ||   edros_num[m[name]] == -1)
                printf("%s infinity\n",name);
            else
                printf("%s %d\n",name,edros_num[m[name]]);
        }
        for(i=0; i<=nodes; i++)
            v[i].clear();
        m.clear();
    }
    return 0;
}

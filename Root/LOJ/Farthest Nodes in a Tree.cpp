#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int>edge[30010];
vector<int>cost[30010];
int dist[30010];
bool color[30010];

int maxi,node;

void DFS(int m) {
    color[m] = 1;
    int i,j;
    for(i=0; i<edge[m].size(); i++) {
        if(color[edge[m][i]] == 0) {
            dist[edge[m][i]] = dist[m] + cost[m][i];
            DFS(edge[m][i]);
        }
    }
    if(dist[m] > maxi) {
        maxi= dist[m];
        node = m;
    }

    return;
}

int main() {
    int t,test,n,i,j,u,v,w;
    scanf("%d",&test);
    for(t=1; t<=test; t++) {
        scanf("%d",&n);
        for(i=0; i<n-1; i++) {
            scanf("%d %d %d",&u,&v,&w);
            edge[u].push_back(v);
            edge[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        maxi = 0;
        DFS(u);
        for(i=0; i<n; i++)
            dist[i] = 0,color[i] = 0;

        maxi = 0;
        DFS(node);
        printf("Case %d: %d\n",t,maxi);

        for(i=0; i<n; i++)
            dist[i] = 0,color[i] = 0;
        for(i=0; i<n; i++) {
            edge[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}

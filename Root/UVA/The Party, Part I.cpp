#include "stdio.h"
#include "vector"
#include "iostream"
#include "map"
#include "queue"
using namespace std;

#define SZ 1010
#define MP(a,b) make_pair(a,b)

typedef pair<int,int> pii;
vector <int> edge[SZ];
bool taken[SZ];
queue <int> Q;
int giova[SZ] , n;
map <pii,int> M;

void BFS()
{
    int i,u,v;
    taken[0] = 1;
    giova[0] = 0;
    Q.push(0);

    while( !Q.empty() )
    {
        u = Q.front() ;
        Q.pop();
        for(i=0; i<edge[u].size(); i++)
        {
            v = edge[u][i];
            if(v>=0 && v<n && taken[v] == 0)
            {
                taken[v] = 1;
                Q.push(v);
                giova[v] = giova[u] + 1;
            }
        }
    }
}

int main()
{
    int t,i,j,k,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&p);
        for(i=0; i<p; i++)
        {
            scanf("%d %d",&j,&k);
            if(M.find(MP(j,k)) != M.end()) continue;
            M[ MP(j,k) ] = 1;
            M[ MP(k,j) ] = 1;
            edge[j].push_back(k);
            edge[k].push_back(j);
        }
        BFS();
        for(i=1; i<n; i++) printf("%d\n",giova[i]);
        for(i=0; i<n; i++) edge[i].clear() , taken[i] = 0;
        while( !Q.empty() ) Q.pop();
        M.clear();

        if(t) printf("\n");
    }

    return 0;
}

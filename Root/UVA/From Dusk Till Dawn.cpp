#include "stdio.h"
#include "string.h"
#include "vector"
#include "queue"
#include "map"
#include "iostream"

using namespace std;

#define SZ 110

typedef pair<int,int>pii;

struct data
{
    int to, s, d;
    data(int a,int b,int c)
    {
        to = a;
        s = b;
        d = c;
    }
};

vector <data> adj[SZ];
queue <int> Q;
int dist[SZ][32], n;
map <string,int> M;
const int inf = 1e9;
bool rep[SZ][32];

int BFS(int start,int end)
{
    while(!Q.empty()) Q.pop();

    int i, j, k, u, v, w, p, q;
    int ret = inf;

    Q.push(start);
    Q.push(18);
    dist[start][18] = 0;

    while(!Q.empty())
    {
        p = Q.front();
        Q.pop();
        q = Q.front();
        Q.pop();

        if(dist[p][q] >= ret) continue;
        if(p == end)
            ret = min(ret, dist[p][q]);

        k = (int)adj[p].size();
        rep[p][q] = 0;

        for(i=0; i<k; i++)
        {
            u = adj[p][i].to;
            v = adj[p][i].s;
            w = adj[p][i].d;
            j = 0;
            if(q > v) j = 1;

            if(dist[u][w] > dist[p][q] + j)
            {
                dist[u][w] = dist[p][q] + j;
                if(rep[u][w] == 0)
                {
                    rep[u][w] = 1;
                    Q.push(u);
                    Q.push(w);
                }
            }
        }
    }

    return ret;
}

int main()
{
    int test = 0, t, i, j, k, l, arrival, departure;
    char arr1[100], arr2[100];

    scanf("%d",&t);
    while(t--)
    {
        n=0;
        M.clear();

        scanf("%d",&j);
        for(i=0; i<j; i++)
        {
            scanf("%s %s %d %d",arr1,arr2,&k,&l);
            if(M.find(arr1) == M.end()) M[arr1] = ++n;
            if(M.find(arr2) == M.end()) M[arr2] = ++n;

            if((k > 6 && k < 18) || l > 12) continue;
            if(((k+l)%24) > 6 && ((k+l)%24 < 18)) continue;
            if(k == 6 && l >= 1) continue;

            if(k <= 6) k += 24;
            adj[M[arr1]].push_back( data(M[arr2], k, k+l) );
        }

        scanf("%s %s",arr1,arr2);
        printf("Test Case %d.\n",++test);

        if(M.find(arr1) == M.end() || M.find(arr2) == M.end())
        {
            printf("There is no route Vladimir can take.\n");
            continue;
        }

        for(i=0; i<=n; i++)
        {
            for(k=0; k<=30; k++)
                dist[i][k] = inf, rep[i][k] = 0;
        }

        k = BFS(M[arr1], M[arr2]);
        if(k >= inf)    printf("There is no route Vladimir can take.\n");
        else    printf("Vladimir needs %d litre(s) of blood.\n",k);

        if(t)for(i=0; i<=n; i++)adj[i].clear();
    }

    return 0;
}

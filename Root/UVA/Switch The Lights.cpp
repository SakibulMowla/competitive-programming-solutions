#include "stdio.h"
#include "string.h"
#include "queue"
#include "vector"
#include "iostream"
using namespace std;
#define SZ 110
#define SZ1 20
#define SZ2 33000

int n,m,dist[SZ2],matr[SZ];
queue <int> Q;

int BFS(int mask)
{
    while(!Q.empty()) Q.pop();
    int i,tmp;
    for(i=0; i<=mask; i++) dist[i] = -1;
    Q.push(mask);
    dist[mask] = 0;
    while(!Q.empty())
    {
        mask = Q.front();
        Q.pop();
        for(i=0; i<m; i++)
        {
            tmp = mask ^ matr[i];
            if(dist[tmp] == -1)
            {
                dist[tmp] = dist[mask] + 1;
                if(tmp == 0) return dist[tmp];
                Q.push(tmp);
            }
        }
    }
    return -1;
}

int main()
{
    int t=0,test,i,j,k;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        for(i=0; i<m; i++)
        {
            matr[i] = 0;
            for(j=0; j<n; j++)
            {
                scanf("%d",&k);
                matr[i] <<= 1;
                matr[i] |= k;
            }
        }
        printf("Case %d: ",++t) ;
        k = (1<<n)-1;
        k = BFS(k);
        if(k == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n",k);
    }

    return 0;
}

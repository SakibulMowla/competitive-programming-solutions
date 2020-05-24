#include "stdio.h"
#include "string.h"
#include "queue"
#include "iostream"

using namespace std;

const int inf = 1<<28;
#define SZ 110
#define SZ1 15

int matrix[SZ][SZ];
bool visited[SZ][SZ1];
int state[SZ][SZ1];
queue <int> Q;

void init(int n,int k)
{
    int i,j;
    while( !Q.empty() ) Q.pop();
    for(i=0;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
            matrix[i][j] = matrix[j][i] = inf;
        matrix[i][i] = 0;
    }
    for(i=0;i<=n;i++)
        for(j=0;j<=k;j++)
            state[i][j] = inf , visited[i][j] = false;
}

int bfs(int start,int target,int a,int b,int k,int l)
{
    int i,j,u,v;
    state[start][0] = 0;
    visited[start][0] = 1;
    Q.push(start);
    Q.push(0);

    while( !Q.empty() )
    {
        u = Q.front() ; Q.pop();
        v = Q.front() ; Q.pop();
        visited[u][v] = false;
        for(i=1;i<=start;i++)
        {
            if(v < k && matrix[u][i] <= l && state[i][v+1] > state[u][v])
            {
                state[i][v+1] = state[u][v];
                if(visited[i][v+1] == false)
                {
                    visited[i][v+1] = true;
                    Q.push(i);
                    Q.push(v+1);
                }
            }
            if(state[i][v] > state[u][v] + matrix[u][i])
            {
                state[i][v] = state[u][v] + matrix[u][i];
                if(visited[i][v] == false)
                {
                    visited[i][v] = true;
                    Q.push(i);
                    Q.push(v);
                }
            }
        }
    }
    int ans = inf;
    for(i=1;i<=k;i++)
        if(state[target][i] < ans)
            ans = state[target][i];
    return ans;
}

void floyd(int a,int b)
{
    int i,j,k;
    for(k=1;k<=a;k++) for(i=1;i<=a+b;i++) for(j=1;j<=a+b;j++)
        matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
}

int main()
{
//    freopen("1.txt","r",stdin);
    int t,n,m,a,b,l,k,i,j,p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d",&a,&b,&m,&l,&k);
        init(a+b,k);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&p,&q,&j);
            matrix[p][q] = matrix[q][p] = j;
        }
        floyd(a,b);
        printf("%d\n",bfs(a+b,1,a,b,k,l));
    }

    return 0;
}

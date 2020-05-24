#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "map"
#include "math.h"
#include "queue"
#include "stack"
#include "algorithm"
#include "iostream"

using namespace std;

#define inf 1<<28
#define SZ 25

int r,c;
int dist[SZ][SZ];
bool col[SZ][SZ];
char arr[SZ][SZ];
queue <int> Q;

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

int BFS(int s1,int s2)
{
    int u,v,i,j,k;
    memset(dist,0,sizeof(dist));
    memset(col,0,sizeof(col));
    while( !Q.empty() ) Q.pop();
    Q.push(s1);
    Q.push(s2);
    col[s1][s2] = 1;

    while( !Q.empty() )
    {
        u = Q.front(); Q.pop();
        v = Q.front(); Q.pop();
//        printf("u = %d v = %d\n",u,v);
        for(i=0;i<4;i++)
        {
//            printf("j = %d k = %d\n",j,k);
            j = u + x[i];
            k = v + y[i];
            if(j>=0 && k>=0 && j<r && k<c && col[j][k] == 0 && (arr[j][k]=='.'||arr[j][k] == 'a'||arr[j][k] == 'b'||arr[j][k] == 'c'||arr[j][k] == 'h') )
            {
                Q.push(j);
                Q.push(k);
                col[j][k] = 1;
                dist[j][k] = dist[u][v] + 1;
                if(arr[j][k] == 'h') {/*printf("fd = %d\n",dist[j][k]);*/return dist[j][k];}
            }
        }
    }
}

int main()
{
    int i,j,k,n,t,test,ans;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++) scanf("%s",arr[i]);
        ans = -inf;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(arr[i][j] == 'a' || arr[i][j] == 'b' || arr[i][j] == 'c')
                {
//                    printf("ans = %d i = %d j = %d\n",ans,i,j);
                    ans = max(ans , BFS(i,j));

                }
            }
        }
        printf("Case %d: %d\n",++t,ans);
    }

    return 0;
}

#include "stdio.h"
#include "string.h"
#include "queue"
#include "iostream"
using namespace std;
#define SZ 15

char arr[SZ][SZ];
bool col[SZ][SZ];
int dist[SZ][SZ];
queue <int> Q;
int r , c;
const int inf = 1e9;

struct data
{
    int x, y;
} arr1[30];

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

int BFS(int s1,int s2,int e1,int e2)
{
    while(!Q.empty()) Q.pop();

    int i, j, k, u, v;

    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            col[i][j] = 0, dist[i][j] = inf;

    Q.push(s1);
    Q.push(s2);
    col[s1][s2] = 1;
    dist[s1][s2] = 0;
    arr[e1][e2] = '.';

    while(!Q.empty())
    {
        j = Q.front();Q.pop();
        k = Q.front();Q.pop();

        for(i=0; i<4; i++)
        {
            u = j + x[i];
            v = k + y[i];
            if(u >= 0 && v >= 0 && u < r && v < c && arr[u][v] == '.' && !col[u][v])
            {
                col[u][v] = 1;
                dist[u][v] = dist[j][k] + 1;
                if(u == e1 && v == e2) return dist[u][v];
                Q.push(u);
                Q.push(v);
            }
        }
    }

    return dist[e1][e2];
}

int main()
{
    int t=0, test, n, i, j, high, tmp, sum;

    scanf("%d",&test);

    while(test--)
    {
        high = 0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {
                scanf(" %c",&arr[i][j]);
                if(arr[i][j] >= 'A' && arr[i][j] <= 'Z')
                {
                    arr1[ arr[i][j]-'A' ].x = i;
                    arr1[ arr[i][j]-'A' ].y = j;
                    high = max(high, arr[i][j]-'A');
                }
            }
        r = c = n;
        sum = 0;
        arr[ arr1[0].x ][ arr1[0].y ] = '.';
        for(i=0; i<high; i++)
        {
            tmp = BFS(arr1[i].x, arr1[i].y, arr1[i+1].x, arr1[i+1].y);
            if(tmp == inf)
            {
                sum = inf;
                break;
            }
            sum += tmp;
        }
        printf("Case %d: ",++t);
        if(sum == inf) printf("Impossible\n");
        else printf("%d\n",sum);
    }
}

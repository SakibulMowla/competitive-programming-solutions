#include "stdio.h"
#include "string.h"
#include "queue"
#include "iostream"

using namespace std;

#define SZ 510

bool col[SZ][SZ], col1[SZ][SZ];
int dp[SZ][SZ];
char arr[SZ][SZ];
int r, c;
queue <int> Q;

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

void BFS(int s1,int s2)
{
    while(!Q.empty()) Q.pop();

    int i, j, k, u, v, sum;

    col[s1][s2] = 1;
    Q.push(s1);
    Q.push(s2);
    sum = 0;
    if(arr[s1][s2] == 'C') sum++;

    while(!Q.empty())
    {
        j = Q.front();Q.pop();
        k = Q.front();Q.pop();
        for(i=0;i<4;i++)
        {
            u = j + x[i];
            v = k + y[i];
            if(u >= 0 && v >= 0 && u < r && v < c && arr[u][v] != '#' && !col[u][v])
            {
                col[u][v] = 1;
                Q.push(u);
                Q.push(v);
                if(arr[u][v] == 'C') sum++;
            }
        }
    }

    while(!Q.empty()) Q.pop();

    col1[s1][s2] = 1;
    Q.push(s1);
    Q.push(s2);
    dp[s1][s2] = sum;

    while(!Q.empty())
    {
        j = Q.front();Q.pop();
        k = Q.front();Q.pop();
        for(i=0;i<4;i++)
        {
            u = j + x[i];
            v = k + y[i];
            if(u >= 0 && v >= 0 && u < r && v < c && arr[u][v] != '#' && !col1[u][v])
            {
                col1[u][v] = 1;
                Q.push(u);
                Q.push(v);
                dp[u][v] = sum;
            }
        }
    }
}

int main()
{
    int t=0, test, i, j, q;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d %d",&r,&c,&q);
        for(i=0; i<r; i++)    scanf(" %s",arr[i]);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                col[i][j] = col1[i][j] = 0;
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                if(arr[i][j] == '#')
                {
                    dp[i][j] = 0;
                    continue;
                }
                if(!col[i][j])
                    BFS(i, j);
            }
        printf("Case %d:\n",++t);
        while(q--)
        {
            scanf("%d %d",&i,&j);
            --i;--j;
            printf("%d\n",dp[i][j]);
        }
    }

    return 0;
}

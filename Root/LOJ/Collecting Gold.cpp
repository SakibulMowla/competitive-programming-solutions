#include "bits/stdc++.h"
using namespace std;

#define SZ 22
const int inf = 1<<28;

struct point
{
    int x, y;
    point() {}
    point(int a,int b)
    {
        x = a;
        y = b;
    }
};

vector <point> gold;

int dist[SZ][SZ][SZ][SZ];
int dp[18][(1<<15)+2];
char arr[SZ][SZ];


int x[] = {-1,-1,-1,0,0,1,1,1};
int y[] = {-1,0,1,-1,1,-1,0,1};

queue <int> Q;
bool col[SZ][SZ];
int r, c;

void BFS(int s1, int s2)
{
    int u, v, i, j, k, a, b;

    while(!Q.empty()) Q.pop();

    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            col[i][j]= 0;

    col[s1][s2] = 1;
    dist[s1][s2][s1][s2] = 0;
    Q.push(s1);
    Q.push(s2);

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        v = Q.front();
        Q.pop();

        for(i=0; i<8; i++)
        {
            a = u + x[i];
            b = v + y[i];

            if(a >= 0 && b >= 0 && a < r && b < c && col[a][b] == 0)
            {
                col[a][b] = 1;
                dist[s1][s2][a][b] = dist[s1][s2][u][v] + 1;
                Q.push(a);
                Q.push(b);
            }
        }
    }

    return ;
}


int n, st1, st2;

int solve(int pos, int mask, int u, int v)
{
    int &ret = dp[pos][mask];

    if(ret != -1) return ret;
    if(!mask)
        return dist[u][v][st1][st2];

    int i;

    ret = inf;

    for(i=0; i<n; i++)
        if(mask&(1<<i))
            ret = min(ret, dist[u][v][gold[i].x][gold[i].y] + solve(i, mask&~(1<<i), gold[i].x, gold[i].y));

    return ret;
}


int main()
{
    int test=0, t, s1, s2, k, i, j;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&r,&c);

        for(i=0; i<r; i++)
            scanf(" %s",arr[i]);

        gold.clear();

        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                if(arr[i][j] == 'x')
                    st1 = i, st2 = j, BFS(i, j);
                else if(arr[i][j] == 'g')
                    gold.push_back(point(i, j)) , BFS(i, j);
            }

        n = gold.size();
        k = 1<<n;

        for(i=0; i<=n+1; i++)
            for(j=0; j<k; j++)
                dp[i][j] = -1;

        printf("Case %d: %d\n",++test, solve(n, k-1, st1, st2));
    }

    return 0;
}

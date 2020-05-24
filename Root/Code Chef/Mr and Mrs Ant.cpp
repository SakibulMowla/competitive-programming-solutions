#include "bits/stdc++.h"

using namespace std;

#define mem(a, b) memset(a, b, sizeof(a))
#define MP(a, b) make_pair(a, b)
#define SZ 15

#define X first
#define Y second

const int inf = 1e5;

typedef pair<int , int> pii;

int r, c;
char grid[SZ][SZ];
vector <pii> food;
int dist[SZ][SZ][SZ][SZ];
queue <int> Q;

int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};

void bfs(int stx, int sty)
{
    while(!Q.empty()) Q.pop();

    Q.push(stx);
    Q.push(sty);
    dist[stx][sty][stx][sty] = 0;

    int i, j, k, u, v, a, b;

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        v = Q.front();
        Q.pop();

        for(i=0; i<4; i++)
        {
            a = u + x[i];
            b = v + y[i];
            if(a >= 0 && b >= 0 && a < r && b < c && grid[a][b] != '#' && dist[stx][sty][a][b] >dist[stx][sty][u][v] + 1)
            {
                dist[stx][sty][a][b] = dist[stx][sty][u][v] + 1;
                Q.push(a);
                Q.push(b);
            }
        }
    }

    return;
}


int dp[SZ][ (1<<9) + 10 ];
int glox, gloy;
int bits;
int path[ (1<<9) + 10 ];

int solve(int now, int mask)
{
//    printf("mask = %d\n",mask);
    int &ret = dp[now][mask];
    if(ret != -1)
        return ret;

    if(!mask)
        return ret = 0;


    int i, ret1;
    ret = inf;

    for(i=0; i<bits; i++)
        if(mask&(1<<i))
        {
            ret1 = solve(i, mask&~(1<<i)) + dist[ food[now].X ][ food[now].Y ][ food[i].X ][ food[i].Y ];
            if(ret1 < ret)
            {
                ret = ret1;
                path[mask] = i;
            }
        }

    return ret;
}

vector <int> v, v1;
bool mark;

void path_dp(int now, int mask)
{
    if(mask == 0)
    {
//        if(now == 0)
//            return;
        if(mark)
            v.push_back(now);
        else
            v1.push_back(now);
        return;
    }

    int i;

    for(i=0; i<bits; i++)
        if(mask&(1<<i))
        {
//            if(i == 0)
//                printf("very bad\n");

            if(dp[now][mask] == dp[i][mask&~(1<<i)] + dist[ food[now].X ][ food[now].Y ][ food[i].X ][ food[i].Y ])
                path_dp(i, mask&~(1<<i));
        }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("waout.txt","w",stdout);
    int test=0, t, i, j, k, n, m, ans, mask, res1, res2, res;

    scanf("%d",&t);

//    printf("t = %d\n",t);

    while(t--)
    {
        scanf("%d %d",&r,&c);

        for(i=0; i<r; i++)
            scanf("%s",grid[i]);

//        printf("---------\n");
//        for(i=0;i<r;i++)
//            printf("%s\n",grid[i]);
//        printf("---------\n");

        food.clear();

        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                if(grid[i][j] == 'H')
                    food.push_back(MP(i, j));

        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                if(grid[i][j] == 'F')
                    food.push_back(MP(i, j));

        for(i=0; i<15; i++)
            for(j=0; j<15; j++)
                for(k=0; k<15; k++)
                    for(n=0; n<15; n++)
                        dist[i][j][k][n] = inf;

        bits = (int)food.size();

        for(i=0; i<(int)food.size(); i++)
        {
            bfs(food[i].X, food[i].Y);
        }

        k = (1 << ((int)( food.size() ))) - 1;
        ans = inf;

        int p, q;

        for(mask=0; mask<=k; mask++)
        {
            mem(dp, -1);

            v.clear();
            v1.clear();

            mark = 1;

            res1 = solve(0, mask&~(1));
            if(res1 < inf)
                path_dp(0, mask&~(1));

            mark = 0;

            res2 = solve(0, (mask^k)&~(1));
            if(res2 < inf)
                path_dp(0, (mask^k)&~(1));

//                        printf("%d %d %d %d\n",mask&~(1), (mask^k)&~(1), res1, res2);

            if(v.size() == 0)
                v.push_back(0);
            if(v1.size() == 0)
                v1.push_back(0);

            if(res1 < inf && res2 < inf)
            for(p=0; p<v.size(); p++)
                for(q=0; q<v1.size(); q++)
                {
                    m = dist[ food[v[p]].X ][ food[v[p]].Y ][ food[v1[q]].X ][ food[v1[q]].Y ];



                    n = abs(res1-res2);

                    m -= n;

                    m = max(0, m);

//                    if(max(res1, res2) + (m/2) + (m%2) == 5)
//                        printf("%d %d %d %d %d %d %d %d\n",mask&~(1), (mask^k)&~(1), res1, res2, m, max(res1, res2) + (m/2) + (m%2), v[p], v1[q]);
//
//                    if((mask&~(1)) == 59)
//                        printf("59 -> %d %d %d %d %d %d %d %d\n",mask&~(1), (mask^k)&~(1), res1, res2, m, max(res1, res2) + (m/2) + (m%2), v[p], v1[q]);

                    ans = min(ans, max(res1, res2) + (m/2) + (m%2));
                }
        }

        if(ans >= inf)
            ans = -1;

        printf("Case %d: %d\n",++test, ans);
    }

    return 0;
}


/*

2 6
#FFF##
FFFH.F

*/

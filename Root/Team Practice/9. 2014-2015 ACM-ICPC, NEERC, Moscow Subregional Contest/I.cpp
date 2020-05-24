#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

namespace matching
{
    typedef int val_t;
    const int SIZE = 1000;
    int v1, v2;
    vector<int> graph[SIZE];
    int mx[SIZE], my[SIZE];
    int total_matching;
    int dist[SIZE];
    int inf_dist;
    bool bfs()
    {
        int x, y;
        queue<int> q;
        for (x = 0 ; x < v1 ; x++)
        {
            if (mx[x] == -1)
            {
                dist[x] = 0;
                q.push(x);
            }
            else
                dist[x] = -1;
        }
        bool flg = false;
        while (!q.empty())
        {
            x = q.front();
            q.pop();
            for (int i = 0 ; i < graph[x].size() ; i++)
            {
                y = graph[x][i];
                if (my[y] == -1)
                {
                    inf_dist = dist[x] + 1;
                    flg = true;
                }
                else if (dist[my[y]] == -1)
                {
                    dist[my[y]] = dist[x] + 1;
                    q.push(my[y]);
                }
            }
        }
        return flg;
    }
    bool dfs(int x)
    {
        if (x == -1) return true;
        for (int i = 0 ; i < graph[x].size() ; i++)
        {
            int y = graph[x][i];
            int tmp = (my[y] == -1) ? inf_dist : dist[my[y]];
            if (tmp == dist[x] + 1 && dfs(my[y]))
            {
                mx[x] = y;
                my[y] = x;
                return true;
            }
        }
        dist[x] = -1;
        return false;
    }
    int hopcroft()
    {
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        total_matching = 0;
        while (bfs())
        {
            for (int x = 0 ; x < v1 ; x++)
                if (mx[x] == -1 && dfs(x))
                    total_matching++;
        }
        return total_matching;
    }
}

int parse()
{
    int h, m;
    scanf(" %d : %d", &h, &m);
    return h*60+m;
}

pii person[210], job[210];

int main()
{
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int cs = 0; cs < t; cs++) {
        int n, m;
        scanf(" %d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            person[i].X = parse();
            person[i].Y = parse();
        }

        for (int i = 0; i < m; i++) {
            job[i].X = parse();
            job[i].Y = parse();
        }

        matching::v1 = n;
        matching::v2 = m;
        for (int i = 0; i < n; i++) {
            matching::graph[i].clear();
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if( person[i].X <= job[j].X && person[i].Y >= job[j].Y ) {
                matching::graph[i].pb(j);
            }
        }

        printf("%d\n", matching::hopcroft());
    }

    return 0;
}













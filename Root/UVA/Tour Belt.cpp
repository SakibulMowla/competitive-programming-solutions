#include "bits/stdc++.h"
using namespace std;

typedef pair<int , int> pii;
const int inf = 1e9;
#define sz(a) ( (int)a.size() )
#define MP(a, b) make_pair(a, b)
#define SZ 10010
#define SZ1 13000000

struct data
{
    int u, v, w;
    bool operator < (const data&now)const
    {
        return w > now.w;
    }
}road[SZ1];

vector <pii> adj[SZ];
vector <int> tmp[SZ];
int par[SZ], belt[SZ];

int find(int r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

bool chk(int now)
{
    int i, j, k, u, v, mx = 0, mn = inf;
    for(i=0;i<belt[now];i++)
    {
        u = tmp[now][i];
        k = sz(adj[u]);
        for(j=0;j<k;j++)
        {
            v = find(adj[u][j].first);
            if(v == now)
                mn = min(mn, adj[u][j].second);
            else
                mx = max(mx, adj[u][j].second);
            if(mn <= mx) return false;
        }
    }
    return true;
}

inline void read (int &n)
{
    n = 0;
    int i = getchar_unlocked();

    while (i < '0' || i > '9')
        i = getchar_unlocked();

    while (i >= '0' && i <= '9')
    {
        n = (n << 3) + (n << 1) + i - '0';
        i = getchar_unlocked();
    }
}

int main()
{
    cin.sync_with_stdio(0);
    int t, n, m, i, j, k, l, ans, now;

    read(t);
    while(t--)
    {
        read(n);
        read(m);
        for(i=0;i<=n;i++)
        {
            adj[i].clear();
            par[i] = i;
            belt[i] = 1;
            tmp[i].clear();
            tmp[i].push_back(i);
        }
        for(i=0;i<m;i++)
        {
            read(road[i].u);
            read(road[i].v);
            read(road[i].w);
            adj[road[i].u].push_back(MP(road[i].v, road[i].w));
            adj[road[i].v].push_back(MP(road[i].u, road[i].w));
        }
        sort(road, road+m);
        ans = 0;
        now = n;
        for(i=0;i<m;i++)
        {
            j = find(road[i].u);
            k = find(road[i].v);
            if(j == k) continue;

            par[j] = ++now;
            par[k] = now;
            par[now] = now;
            belt[now] = belt[j] + belt[k];
            tmp[now].clear();
            for(l=0;l<belt[j];l++) tmp[now].push_back(tmp[j][l]);
            for(l=0;l<belt[k];l++) tmp[now].push_back(tmp[k][l]);
            if(chk(now))
                ans += belt[now];
        }
        cout << ans << '\n';
    }
}

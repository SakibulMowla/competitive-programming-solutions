#include "bits/stdc++.h"
using namespace std;

#define SZ 1010
#define sz(a) (int)a.size()
#define MP(a, b) make_pair(a, b)

#define X first
#define Y second

typedef pair <int , int> pii;

vector <int> adj[SZ];
int tym[SZ], low[SZ], timer;
stack <pii> S;
set <pii> ans;

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

void bcc(int u, int par)
{
    tym[u] = low[u] = timer++;
    int i, k, v, us, vs, cnt;
    k = sz(adj[u]);
    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(v == par) continue;

        if(!tym[v])
        {
            S.push(MP(u, v));
            bcc(v, u);
            low[u] = min(low[u], low[v]);
            if(tym[u] <= low[v])
            {
                cnt = 0;
                while(!S.empty())
                {
                    us = S.top().X;
                    vs = S.top().Y;
                    S.pop();
                    cnt++;

                    if(cnt == 1 && u == us && v == vs) // bridge
                    {
                        ans.insert(MP(us, vs));
                        ans.insert(MP(vs, us));
                        break;
                    }
                    ans.insert(MP(us, vs));
                    if(u == us && v == vs)
                    {
                        break;
                    }

                }
            }
        }

        else if(tym[u] > tym[v])
        {
            S.push(MP(u, v));
            low[u] = min(tym[v], low[u]);
        }

    }
}

int main()
{
    int n, m, i, j, k, t=0;

    while(1)
    {
        read(n);
        read(m);
        if(n == 0 && m == 0) break;
        while(!S.empty()) S.pop();
        ans.clear();
        for(i=0; i<=n; i++)
        {
            adj[i].clear();
            tym[i] = low[i] = 0;
        }
        for(i=0; i<m; i++)
        {
            read(j);
            read(k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        timer = 0;
        for(i=1; i<=n; i++)
            if(!tym[i])
                bcc(i, -1);
        printf("%d\n\n",++t);
        for(set<pii>::iterator it = ans.begin();it!=ans.end();it++)
            printf("%d %d\n",it->first,it->second);
        printf("#\n");
    }

    return 0;
}

using namespace  std;

#include "stdio.h"
#include "map"
#include "vector"
#include "stack"
#include "iostream"

#define sz(x) ((int)x.size())
#define SZ 1010

vector <int> adj[SZ], dag[SZ];
map <int , int> M;
stack <int> S;
int group[SZ], col[SZ], low[SZ], dis[SZ], tym, compo, zero,  that;
int in[SZ], out[SZ];

void init()
{
    int i;
    for(i=0; i<SZ; i++)
    {
        adj[i].clear();
        dag[i].clear();
        col[i] = in[i] = out[i] = 0;
    }
    zero = that = -1;
    tym = compo = 0;
    M.clear();
    while(!S.empty()) S.pop();
}

void tarjan(int u)
{
    int i, j, k;

    col[u] = 1;
    low[u] = dis[u] = tym++;
    S.push(u);
    k = sz(adj[u]);

    for(i=0; i<k; i++)
    {
        j = adj[u][i];
        if(col[j] == 1)
            low[u] = min(low[u], dis[j]);
        else if(col[j] == 0)
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
    }

    if(low[u] == dis[u])
    {
        int f = 0;
        do
        {
            j = S.top();
            S.pop();
            if(j == 0) f = 1;
            group[j] = compo;
            col[j] = 2;
        }
        while(j != u);
        if(f) zero = compo;
        compo++;
    }
}

void make_DAG(int node)
{
    int i, j, p, k, l;

    k = node;
    for(i=0; i<k; i++)
    {
        l = sz(adj[i]);
        for(j=0; j<l; j++)
        {
            p = adj[i][j];

            if(group[i] != group[p])
            {
                in[group[p]]++;
                out[group[i]]++;
                dag[group[i]].push_back(group[p]);
            }
        }
    }
}

bool found;

int main()
{
    int t=0, test, n, k, i, j, l, node, ya, f;

    scanf("%d",&test);

    while(test--)
    {
        init();
        M[0] = 0;
        f = 0;
        node = 1;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&k);
            if(!k) f++;
            while(k--)
            {
                scanf("%d %d",&j,&l);

                if(!j || !l) ya = 1;

                if(M.find(j) == M.end()) M[j] = node++;
                if(M.find(l) == M.end()) M[l] = node++;
                adj[ M[j] ].push_back(M[l]);
            }
        }

        if(ya) tarjan(0);

        for(i=1; i<node; i++)
            if(!col[i])
                tarjan(i);
        make_DAG(node);

        found = true;

        int inout, ind, outd;
        inout = ind = outd = 0;


        for(i=0; i<compo; i++)
        {
            if(in[i]==1 && out[i]==1)
                inout++;
            else if(in[i] == 1 && out[i] == 0)
                ind++;
            else if(out[i] == 1 && in[i] == 0)
                outd++;
        }

        if(compo > 2)
        {
            if(inout != compo-2)
                found = false;
        }
        if(compo > 1)
            if(ind != 1 || outd != 1 || !(out[zero]==1 && in[zero]==0)) found = false;

        printf("Case %d: ",++t);
        if(found || f==n) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

/*

1
10
0 1
1 2
2 3
0 3
3 4
4 5
5 6
6 7
7 4
7 0

ans = YES

2
2
0 9
9 10
1
10 15

ans = YES

1
2
0 9
0 11

ans = NO

1
6
0 4
4 3
3 2
2 1
1 4
2 4

ans = YES

1
6
0 4
4 3
3 2
2 1
1 4
4 2

ans = YES

1
4
0 1
1 2
2 3
2 5

ans = NO

1
4
0 1
1 2
2 3
3 1000

ans = YES

1
7
0 2
2 3
3 0
0 4
4 5
5 6
6 7

ans = YES

1
8
0 1
1 2
2 3
3 0
0 2
2 0
1 3
3 1

ans = YES

1
5
0 1
1 2
2 3
2 4
4 3

ans = NO

1
5
0 1
1 2
2 3
2 5
3 5

ans = NO

1
8
0 1
1 2
2 3
3 0
1 4
4 5
5 6
6 1

ans = YES

1
4
1 0
0 2
2 3
3 4

ans = NO
*/

#include "bits/stdc++.h"
using namespace std;

#define SZ  2*8010
#define SZ1  20010


struct data
{
    int x, y;
};
data val[SZ1];

vector <int> adj[SZ];
int col[SZ], low[SZ], tim[SZ], timer;
int group_id[SZ], compo;
bool logic[SZ];
stack <int> S;

inline void inp( int &n )
{
    n=0;
    int ch=getchar_unlocked();
    int sign=1;
    while( ch < '0' || ch > '9' )
    {
        if(ch=='-')sign=-1;
        ch=getchar_unlocked();
    }

    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

void SCC(int u)
{
    int i, v, tem, k;

    col[u] = 1;
    low[u] = tim[u] = timer++;
    S.push(u);

    k = (int)adj[u].size();

    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(col[v] == 1)
            low[u]= min(low[u], tim[v]);
        else if(col[v] == 0)
        {
            SCC(v);
            low[u] = min(low[u], low[v]);
        }
    }


    if(low[u] == tim[u])
    {
        do
        {
            tem = S.top();
            S.pop();
            group_id[tem] = compo;
            col[tem] = 2;
        }
        while(tem != u);
        compo++;
    }
}

void tarjan_SCC(int m)
{
    int i;

    for(i=0; i<=2*m+2; i++)
    {
        col[i] = 0;
    }

    timer = compo = 0;
    while(!S.empty()) S.pop();

    for(i=2; i<=2*m+1; i++)
        if(col[i] == 0)
            SCC(i);
}

void implication_graph(int n)
{
    int i, j, k, a, b, aprime, bprime;

    for(i=0; i<n; i++)
    {
        j = val[i].x;
        k = val[i].y;
        if(j > 0)
        {
            a = 2 * j;
            aprime = 2 * j + 1;
        }
        else
        {
            a = 2 * (-j) + 1;
            aprime = 2 * (-j);
        }

        if(k > 0)
        {
            b = 2 * k;
            bprime = 2 * k + 1;
        }
        else
        {
            b = 2 * (-k) + 1;
            bprime = 2 * (-k);
        }
        adj[aprime].push_back(b);
        adj[bprime].push_back(a);
    }

}


bool two_SAT(int m)
{
    int i;

    for(i=2; i<=2*m; i+=2)
    {
        if(group_id[i] == group_id[i+1])
            return false;
        else if(group_id[i] > group_id[i+1])
            logic[i/2] = false;
        else
            logic[i/2] = true;
    }

    return true;
}


int main()
{
    int test=0, t, n, m, i, j, k;
    vector <int> v;

    inp(t);

    while(t--)
    {
        inp(n);
        inp(m);

        for(i=0; i<=2*m+2; i++)
            adj[i].clear();

        for(i=0; i<n; i++)
        {
            inp(val[i].x);
            inp(val[i].y);
        }

        implication_graph(n);

        tarjan_SCC(m);
        printf("Case %d: ",++test);

        if(two_SAT(m))
        {
            printf("Yes\n");
            v.clear();

            for(i=1; i<=m; i++)
                if(logic[i])
                    v.push_back(i);

            k = (int)v.size();
            printf("%d",k);

            for(i=0; i<k; i++)
                printf(" %d",v[i]);

            printf("\n");
        }
        else
            printf("No\n");
    }

    return 0;
}

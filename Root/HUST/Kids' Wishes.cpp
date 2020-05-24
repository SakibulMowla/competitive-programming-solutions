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

//#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

typedef long long ll;
typedef pair<ll,ll> pii;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 200010
const ll inf = 1LL<<28;
const ll mod = 1LL;

int in[SZ];
int n;
map <int , int> M;
vector <int> adj[SZ];
int col[SZ], low[SZ], tim[SZ], timer;
int group_id[SZ], no_ele[SZ], compo;
stack <int> S;

bool found ;

void scc(int u)
{
    int i, v, tem, k;

    col[u]=1;
    low[u]=tim[u]=timer++;
    S.push(u);
    k = sz(adj[u]);

    for(i=0;i<k;i++)
    {
        v=adj[u][i];
        if(col[v]==1)
            low[u]=min(low[u],tim[v]);
        else if(col[v]==0)
        {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
    }

    if(low[u]==tim[u])
    {
        int cnt=0;
        do
        {
            cnt++;
            tem=S.top();S.pop();
            group_id[tem]=compo;
            col[tem]=2;
        }while(tem!=u);

        no_ele[compo] = cnt;
        compo++;
    }
}


bool TarjanSCC()
{
    int i;
    timer = compo = 0;

    for(i=0; i<=n; i++)
    {
        col[i] = 0;
        low[i] = 0;
        tim[i] = 0;
        group_id[i] = 0;
        no_ele[i] = 0;
    }

    while(!S.empty()) S.pop();

    for(i=0;i<n;i++)
        if(col[i] == 0)
        {
            found = false;
            SCC(i);
            if(found)
                return false;
        }

    for(i=0;i<compo;i++)
        if(no_ele[i] > 1 && no_ele[i] < n)
            return false;

    return true;
}

set <int> myset[SZ];

//%I64d
int main()
{
    int i, j, k, w, f;

    while(scanf("%d %d",&k,&w) == 2)
    {
        if(k == 0 && w == 0)
            break;

        M.clear();
        n = 0;
        f = 0;


        for(i=0;i<=2*w;i++)
            in[i] = 0,myset[i].clear(), adj[i].clear();

        for(i=0; i<w; i++)
        {
            scanf("%d %d",&j,&k);

            if(M.find(j) == M.end()) M[j] = n++;
            if(M.find(k) == M.end()) M[k] = n++;

            j = M[j];
            k = M[k];

            in[k]++;
            if(in[k] > 2)
                f = 1;

            myset[j].insert(k);
            myset[k].insert(j);

            adj[j].push_back(k);
//            adj[k].push_back(j);
        }

        if(f)
        {
            printf("N\n");
            continue;
        }

        for(i=0;i<n;i++)
            if(sz(myset[i]) > 2)
            {
                f = 1;
                break;
            }

        if(f)
        {
            printf("N\n");
            continue;
        }
    }

    return 0;
}


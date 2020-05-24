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

#define SZ 3*100010
#define SZ1 4*3*100010
const ll inf = 1LL<<28;
const ll mod = 1LL;

int tree[SZ1];
int lazy[SZ1];

struct data
{
    int x, y, z;
};

data query[SZ];

void build(int node,int b,int e)
{
    tree[node] = lazy[node] = 0;
    if(b == e)
    {
        return;
    }
    int mid = (b + e) / 2;
    build(2*node, b, mid);
    build((2*node)+1, mid+1, e);
}


void update(int node, int b, int e, int f, int t, int cl)
{
//    printf("ft %d %d %d %d %d\n",f,t,b,e,node);
    if(b >= f && e <= t)
    {
        tree[node] = cl;
        lazy[node] = cl;
        return;
    }

    int mid = (b + e) / 2;

    if(lazy[node] && (b!=e))
    {
        tree[2*node] = tree[(2*node)+1] = lazy[node];
        lazy[2*node] = lazy[(2*node)+1] = lazy[node];
        lazy[node] = 0;
    }

    if(f <= mid) update(2*node, b, mid, f, t, cl);
    if(t > mid) update((2*node)+1, mid+1, e, f, t, cl);

    return;
}

int query1(int node, int b, int e, int pos, int last)
{
    if(lazy[node] && (b!=e))
    {
        tree[2*node] = tree[(2*node)+1] = lazy[node];
        lazy[2*node] = lazy[(2*node)+1] = lazy[node];
        lazy[node] = 0;
    }

    if(b == e)
    {
        return tree[node];
    }

    int mid = (b + e) / 2;

    if(pos <= mid) return query1(2*node, b, mid, pos, tree[node]);
    else return query1((2*node)+1, mid+1, e, pos, tree[node]);

    return 0;
}

//%I64d
int main()
{
    int i, j, k, n, m, l, r, v;

    while(scanf("%d %d",&n,&m) == 2)
    {
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&query[i].x,&query[i].y,&query[i].z);
        }

        build(1, 1, n);

        for(i=m-1; i>=0; i--)
        {
            l = query[i].x;
            r = query[i].y;
            v = query[i].z;

            if(v-1 >= l) update(1, 1, n, l, v-1, v);
            if(v+1 <= r) update(1, 1, n, v+1, r, v);
        }

        for(i=1; i<=n; i++)
        {
            printf("%d ",query1(1, 1, n, i, 0));
        }

        printf("\n");

//        printf("t = %d %d %d\n",tree[10],tree[20],tree[21]);

    }



    return 0;
}



/*

11 8
3 5 5
8 9 9
4 6 6
8 10 10
5 7 7
2 7 2
10 11 11
1 11 1

0 1 5 5 6 7 2 9 10 11 1

*/

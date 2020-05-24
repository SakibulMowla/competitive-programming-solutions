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

#define X first
#define Y second

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;

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

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 100010
#define SZ1 2*SZ
#define SZ2 6*SZ

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

int tree[SZ2];
int pos[SZ1];
int n;


void push_up(int node)
{
    tree[node] = tree[node<<1] + tree[(node<<1)|1];
}


void build(int node, int b, int e)
{
    if(b == e)
    {
        if(b <= n)
            tree[node] = 1;
        else
            tree[node] = 0;
        return;
    }

    int mid = (b + e) >> 1;

    build(left);
    build(riht);

    push_up(node);
}


int query(int node, int b, int e, int f, int t)
{
    if(b >= f && e <= t)
        return tree[node];

    int mid = (b + e) >> 1, sum = 0;

    if(f <= mid)
        sum = query(left, f, t);
    if(t > mid)
        sum += query(riht, f, t);

    return sum;
}


void update(int node, int b, int e, int x)
{
    if(b == e)
    {
        tree[node] = !tree[node];
        return;
    }

    int mid = (b + e) >> 1;

    if(x <= mid)
        update(left, x);
    else
        update(riht, x);

    push_up(node);
}


//%I64d
int main()
{
//    freopen("1.txt","r",stdin);

    int t, q, i, j;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&q);

        build(1, 1, n+q);

        for(i=1;i<=n;i++)
            pos[i] = n-i+1;

        for(i=0;i<q;i++)
        {
            scanf("%d",&j);

            if(i) printf(" ");

            printf("%d",query(1, 1, n+q, pos[j]+1, n+q));

            update(1, 1, n+q, pos[j]);
            pos[j] = n + i + 1;
            update(1, 1, n+q, pos[j]);
        }

        printf("\n");

    }


    return 0;
}


















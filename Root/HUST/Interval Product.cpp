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

#define SZ 100010
#define SZ1 4*SZ
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

int tree[SZ1], arr[SZ];

void build(int node,int b, int e)
{
    if(b == e)
    {
        if(arr[b] > 0)
            tree[node] = 1;
        else if(arr[b] < 0)
            tree[node] = -1;
        else tree[node] = 0;
//        printf("b = %d t = %d\n",b,tree[node]);
        return;
    }
    int mid = (b + e) >> 1;
    build(left);
    build(riht);
    tree[node] = tree[node<<1] * tree[(node<<1)|1];
}

void update(int node,int b,int e,int pos)
{
    if(b == e)
    {
        if(arr[b] > 0)
            tree[node] = 1;
        else if(arr[b] < 0)
            tree[node] = -1;
        else tree[node] = 0;
        return;
    }
    int mid = (b + e) >> 1;
    if(pos <= mid) update(left, pos);
    else update(riht, pos);
    tree[node] = tree[node<<1] * tree[(node<<1)|1];
}

int query(int node,int b,int e,int f,int t)
{
    if(b >= f && e <= t)
        return tree[node];
    int mid = (b + e) >> 1;
    int ans1 = 1, ans2 = 1;
    if(f <= mid) ans1 = query(left, f, t);
    if(t > mid) ans2 = query(riht, f, t);
    return ans1 * ans2;
}

//%I64d
int main()
{
//    freopen("1.txt","r",stdin);
    int n, k, i, j, l;
    char ch;

    while(scanf("%d %d",&n,&k) == 2)
    {
        for(i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        build(1, 1, n);
        while(k--)
        {
            scanf(" %c",&ch);
            if(ch == 'C')
            {
                scanf("%d %d",&i,&j);
                arr[i] = j;
                update(1, 1, n, i);
            }
            else
            {
                scanf("%d %d",&i,&j);
                l = query(1, 1, n, i, j);
//                printf("lllll");
                if(l == 0) printf("0");
                else if(l > 0) printf("+");
                else printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}

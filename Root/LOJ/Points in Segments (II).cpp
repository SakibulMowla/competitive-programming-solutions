#include <bits/stdc++.h>

using namespace  std;

#define sz(x) (int)x.size()
#define SZ 150010
#define SZ1 50010
#define SZ2 100000010
#define SZ3 524290

#define left (node<<1), b, mid
#define riht ((node<<1)|1), mid+1, e

int beg[SZ1], end[SZ1], point[SZ1];
int lazy[SZ3];
map <int, int> val;
vector <int> v;
int N, Q, KK;

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

void build(int node,int b,int e)
{
    lazy[node] = 0;
    if(b == e) return;
    int mid = (b + e) >> 1;
    build(left);
    build(riht);
}

void update(int node,int b,int e,int f,int t)
{
    if(b >= f && e <= t)
    {
        lazy[node]++;
        return;
    }
    if(lazy[node])
    {
        lazy[node<<1] += lazy[node];
        lazy[(node<<1)|1] += lazy[node];
        lazy[node] = 0;
    }
    int mid = (b + e) >> 1;
    if(f <= mid) update(left, f, t);
    if(t >= mid+1) update(riht, f, t);
}

int query(int node,int b,int e,int x)
{
    if(b == e) return lazy[node];
    if(lazy[node])
    {
        lazy[node<<1] += lazy[node];
        lazy[(node<<1)|1] += lazy[node];
        lazy[node] = 0;
    }
    int mid = (b + e) >> 1;
    if(x <= mid) return query(left, x);
    else return query(riht, x);
}

void compress()
{
    int i, k;
    scanf("%d %d",&N,&Q);
    v.clear();
    for(i=0; i<N; i++)
    {
        read(beg[i]);
        read(end[i]);
        v.push_back(beg[i]);
        v.push_back(end[i]);
    }
    for(i=0; i<Q; i++)
    {
        read(point[i]);
        v.push_back(point[i]);
    }
    sort(v.begin(),v.end());
    KK = unique(v.begin(),v.end()) - v.begin();
    val.clear();
    k = 0;
    for(i=0; i<KK; i++)
        val[v[i]] = ++k;
}

void dhoom()
{
    int i;
    build(1, 1, KK);
    for(i=0; i<N; i++)
        update(1, 1, KK, val[ beg[i] ], val[ end[i] ]);
    for(i=0; i<Q; i++)
        printf("%d\n",query(1, 1, KK, val[ point[i] ]));
}

int main()
{
    int test=0, t;

    scanf("%d",&t);
    while(t--)
    {
        compress();
        printf("Case %d:\n",++test);
        dhoom();
    }

    return 0;
}



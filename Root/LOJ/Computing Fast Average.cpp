#include "bits/stdc++.h"
using namespace std;

#define SZ 100010
#define SZ1 262150

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

int tree[SZ1], lazy[SZ1];
bool upd[SZ1];
int val;

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

void prop(int node,int b,int mid,int e)
{
    int a = node<<1, bb = (node<<1)|1;
    lazy[a] = lazy[node];
    lazy[bb] = lazy[node];
    upd[node] = 0;
    upd[a] = 1;
    upd[bb] = 1;
    tree[a] = (mid-b+1) * lazy[a];
    tree[bb] = (e-mid) * lazy[bb];
}

void build(int node,int b,int e)
{
    lazy[node] = 0;
    upd[node] = 0;
    tree[node] = 0;
    if(b == e) return;
    int mid = (b + e) >> 1;
    build(left);
    build(riht);
}

void update(int node,int b,int e,int f,int t)
{
    if(b >= f && e <= t)
    {
        lazy[node] = val;
        upd[node] = 1;
        tree[node] = val * (e-b+1);
        return;
    }
    int mid = (b + e) >> 1;
    if(upd[node]) prop(node, b, mid, e);
    if(f <= mid) update(left, f, t);
    if(t  > mid) update(riht, f, t);
    tree[node] = tree[node<<1] + tree[(node<<1)|1];
}

int query(int node,int b,int e,int f,int t)
{
    if(b >= f && e <= t)
    {
        return tree[node];
    }
    int mid = (b + e) >> 1, sum = 0;
    if(upd[node]) prop(node, b, mid, e);
    if(f <= mid) sum = query(left, f ,t);
    if(t > mid)  sum += query(riht, f, t);
    tree[node] = tree[node<<1] + tree[(node<<1)|1];
    return sum;
}

int main()
{
    int test=0, t, i, j, k, n, q, a, b, g;

    read(t);

    while(t--)
    {
        read(n);
        read(q);
        build(1, 1, n);
        printf("Case %d:\n",++test);
        while(q--)
        {
            read(k);
            read(i);
            read(j);
            i++,j++;
            if(k == 1)
            {
                read(val);
                update(1, 1, n, i, j);
            }
            else
            {
                a = query(1, 1, n, i, j);
                b = j-i+1;
                g = __gcd(a, b);
                a /= g;
                b /= g;
                if(b == 1) printf("%d\n",a);
                else printf("%d/%d\n",a, b);
            }
        }
    }

    return 0;
}

#include "bits/stdc++.h"
using namespace std;

#define SZ 30000
#define SZ1 65540

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

struct data
{
    int minim, indx;
};

data tree[SZ1];
data small;
int arr[SZ];
int n;

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
    if(b == e)
    {
        tree[node].minim = arr[b];
        tree[node].indx = b;
        return;
    }

    int mid = (b + e) >> 1;
    build(left);
    build(riht);

    int pref;
    if( tree[node<<1].minim < tree[(node<<1)|1].minim ) pref = node<<1;
    else pref = (node<<1)|1;

    tree[node].minim = tree[pref].minim;
    tree[node].indx = tree[pref].indx;
}

void query(int node,int b,int e,int f,int t)
{
    if(b>=f && e<=t)
    {
        if(tree[node].minim < small.minim)
        {
            small.minim = tree[node].minim;
            small.indx = tree[node].indx;
        }
        return;
    }
    int mid = (b + e) >> 1;
    if(f <= mid) query(left, f, t);
    if(t > mid) query(riht, f, t);
}

int ans;

int cal_area(int b,int e)
{
    small.minim = 1<<28;
    query(1, 1, n, b, e);
    ans = max(ans, small.minim*(e-b+1));
    if(small.indx > b) cal_area(b, small.indx-1);
    if(small.indx < e) cal_area(small.indx+1, e);
}

int main()
{
    int test=0, t, i, j;

    read(t);

    while(t--)
    {
        read(n);
        for(i=1;i<=n;i++)
            read(arr[i]);
        build(1, 1, n);
        ans = 0;
        cal_area(1, n);
        printf("Case %d: %d\n",++test,ans);
    }

    return 0;
}

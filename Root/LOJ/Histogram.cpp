#include "bits/stdc++.h"
using namespace std;

#define SZ 30010
#define SZ1 65540

struct data
{
    int bestpre, prel, bestsuf, sufl, totmin, totans, bestans;
};

data tree[SZ1];
int arr[SZ];

void build(int n,int b,int e)
{
    if(b == e)
    {
        tree[n].bestpre = arr[b];
        tree[n].prel = 1;
        tree[n].bestsuf = arr[b];
        tree[n].sufl = 1;
        tree[n].totmin = arr[b];
        tree[n].totans = arr[b];
        tree[n].bestans = arr[b];
        return;
    }

    int mid = (b + e) >> 1, aa = n << 1, bb = (n << 1) | 1, alen = mid-b+1, blen = e-mid;
    int tmp, tmp1;

    build(aa, b, mid);
    build(bb, mid+1, e);

    tmp = alen + tree[bb].prel;
    tmp1 = min(tree[aa].totmin, tree[bb].bestpre);

    if(tmp * tmp1 > tree[aa].bestpre * tree[aa].prel)
    {
        tree[n].bestpre = tmp1;
        tree[n].prel = tmp;
    }
    else
    {
        tree[n].bestpre = tree[aa].bestpre;
        tree[n].prel = tree[aa].prel;
    }

    tmp = blen + tree[aa].sufl;
    tmp1 = min(tree[bb].totmin, tree[aa].bestsuf);

    if(tmp * tmp1 > tree[bb].bestsuf * tree[bb].sufl)
    {
        tree[n].bestsuf = tmp1;
        tree[n].sufl = tmp;
    }
    else
    {
        tree[n].bestsuf = tree[bb].bestsuf;
        tree[n].sufl = tree[bb].sufl;
    }

    tree[n].totmin = min(tree[aa].totmin, tree[bb].totmin);
    tree[n].totans = tree[n].totmin * (e-b+1);

    tree[n].bestans = max(tree[aa].bestans, tree[bb].bestans);
    tree[n].bestans = max(tree[n].bestans, tree[n].totans);

    tmp = tree[aa].sufl + tree[bb].prel;
    tmp1 = min(tree[aa].bestsuf, tree[bb].bestpre);

    if(tmp * tmp1 > tree[n].bestans)
        tree[n].bestans = tmp * tmp1;

    tree[n].bestans = max(tree[n].bestpre*tree[n].prel, tree[n].bestans);
    tree[n].bestans = max(tree[n].bestsuf*tree[n].sufl, tree[n].bestans);
}

int main()
{
    int test=0, t, n, i;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        build(1, 1, n);
        printf("Case %d: %d\n",++test,tree[2].bestans);
    }

    return 0;
}

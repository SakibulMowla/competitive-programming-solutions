#include "stdio.h"

#define SZ 1000

typedef long long ll;

const int inf = 1e9;

struct data
{
    int x, y;
};

data point[SZ];
int par[SZ];
int rank[SZ];

void init(int n)
{
    int i;
    for(i=0; i<n; i++)
        par[i] = i, rank[i] = 0;
}

int find_par(int r)
{
    if(r == par[r])
        return r;
    return par[r] = find_par(par[r]);
}

void Union(int a, int b)
{
    a = find_par(a);
    b = find_par(b);
    if(a == b) return;
    if(rank[a] > rank[b])
        par[b] = a;
    else
    {
        par[a] = b;
        if(rank[a] == rank[b])
            rank[b]++;
    }
}

inline bool chk(int i, int j, ll mid)
{
    ll d, x, y;

    x = point[i].x-point[j].x;
    y = point[i].y-point[j].y;

    d = x*x + y*y;
    mid = mid*mid;

    return d <= mid;
}

inline void getint(int &num)
{
    bool neg=0;
    num=0;
    char c;
    while ((c=getchar_unlocked()) && ((c < '0' || c > '9') && c!='-'));
    if (c=='-')
    {
        neg=1;
        c=getchar_unlocked();
    }
    do num=num*10+c-'0';
    while ((c=getchar_unlocked()) && (c >= '0' && c <= '9'));
    num*=(neg)?-1:1;
}

int  main()
{
    int t, m, n, ans, i, j, tmp;
    ll hi, lo, mid;

    getint(t);
    while(t--)
    {
        n = 0;
        getint(m);

        getint(i);

        while(i != -1)
        {
            point[n].x = i;
            getint(j);
            point[n++].y = j;

            getint(i);
        }

        lo = 0;
        hi = 12000;

        while(lo <= hi)
        {
            init(n);
            mid = (lo + hi) / 2;

            for(i=0; i<n; i++)
                for(j=i+1; j<n; j++)
                    if(chk(i, j, mid))
                        Union(i, j);
            tmp = 0;
            for(i=0; i<n; i++)
                if(i == find_par(i))
                    tmp++;
            if(tmp <= m)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        printf("%d\n",ans);
    }

    return 0;
}

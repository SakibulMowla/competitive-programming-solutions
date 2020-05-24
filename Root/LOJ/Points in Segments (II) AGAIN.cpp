#include "bits/stdc++.h"

using namespace std;

#define SZ 50010
#define SZ1 3*SZ

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

int cum[SZ1];
int x[SZ], y[SZ];
int z[SZ1];
int q[SZ];

int main()
{
    int test = 0, t;

//    scanf("%d", &t);
    inp(t);

    while(t--)
    {
        int n, Q;
//        scanf("%d %d", &n, &Q);
        inp(n);
        inp(Q);

        int zcnt = 0;

        for(int i = 0; i < n; i++)
        {
//            scanf("%d %d", &x[i], &y[i]);
            inp(x[i]);
            inp(y[i]);
            z[zcnt++] = x[i];
            z[zcnt++] = y[i];
        }

        for(int i = 0; i < Q; i++)
        {
//            scanf("%d", &q[i]);
            inp(q[i]);
            z[zcnt++] = q[i];
        }

        sort(z, z+zcnt);
        zcnt = unique(z, z+zcnt) - z;

        memset(cum, 0, sizeof(int)*(zcnt));

        for(int i = 0; i < n; i++)
        {
            cum[ lower_bound(z, z+zcnt, x[i]) - z ]++;
            cum[ (lower_bound(z, z+zcnt, y[i]) - z) + 1 ]--;
        }

        for(int i = 1; i < zcnt; i++)
            cum[i] += cum[i-1];

        printf("Case %d:\n", ++test);

        for(int i = 0; i < Q; i++)
        {
            printf("%d\n", cum[ lower_bound(z, z+zcnt, q[i]) - z ]);
        }
    }

    return 0;
}


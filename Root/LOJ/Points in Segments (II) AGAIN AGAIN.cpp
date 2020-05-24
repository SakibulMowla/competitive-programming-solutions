#include "bits/stdc++.h"

using namespace std;

#define SZ 50000

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

int main()
{
    int x[SZ], y[SZ];
    int test = 0, t;

//    scanf("%d", &t);
    inp(t);

    while(t--)
    {
        int n, q;
//        scanf("%d %d", &n, &q);
        inp(n);
        inp(q);

        for(int i = 0; i < n; i++)
        {
//            scanf("%d %d", &x[i], &y[i]);
            inp(x[i]);
            inp(y[i]);
        }

        sort(x, x+n);
        sort(y, y+n);

        printf("Case %d:\n", ++test);

        for(int i = 0; i < q; i++)
        {
            int val;
//            scanf("%d", &val);
            inp(val);
            printf("%d\n", upper_bound(x, x+n, val) - x - ( upper_bound(y, y+n, val-1) - y ));
        }
    }

    return 0;
}

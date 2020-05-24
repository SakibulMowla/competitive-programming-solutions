#include "bits/stdc++.h"
using namespace std;

set <int> myset;
set <int>:: iterator it;

inline void inp( int &n )
{
    n=0;
    int ch=getchar_unlocked();
    int sign=1;
    while( ch < '0' || ch > '9' )
    {
        if(ch=='-')sign=-1;
        ch=getchar_unlocked();
    }

    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

int main()
{
    int t, test= 0, n, w, pre, k, j;

    inp(t);

    while(t--)
    {
        inp(n);
        inp(w);
        myset.clear();

        while(n--)
        {
            scanf("%*d");
            inp(j);
            myset.insert(j);
        }

        pre = (-1e9) - 1;
        k = 0;

        for(it=myset.begin(); it != myset.end(); it++)
        {
            if((*it) > pre)
            {
                k++;
                pre = (*it) + w;
            }
        }

        printf("Case %d: %d\n",++test,k);
    }

    return 0;
}

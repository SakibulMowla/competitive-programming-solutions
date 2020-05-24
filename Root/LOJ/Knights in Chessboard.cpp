#include <stdio.h>
#include <iostream>
using namespace std;

inline void inp( int &n )
{
        n=0;
        int ch=getchar_unlocked();int sign=1;
        while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}

        while(  ch >= '0' && ch <= '9' )
                n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
        n=n*sign;
}

int main()
{
    int t, test, ans, n, m;
    inp(test);
    t = 0;
    while(test--)
    {
        inp(n);
        inp(m);
        if(n == 1 || m==1) ans = max(m, n);
        else if(n == 2) ans = (m/4)*4 + min(2, m%4)*2;
        else if(m == 2) ans = (n/4)*4 + min(2, n%4)*2;
        else if(m%2 == 0) ans = n*(m/2);
        else if(n%2 == 0) ans = m*(n/2);
        else ans = (n/2 + 1)*(m/2 + 1) + (n/2)*(m/2);
        printf("Case %d: %d\n",++t,ans);
    }

    return 0;
}

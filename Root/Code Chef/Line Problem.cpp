#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t, n, m, x1, x2, y1, y2;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        n = x1 - x2;
        if(n < 0) n = -n;
        m = y1 - y2;
        if(m < 0) m = -m;
        n = n + m - __gcd(n, m);
        printf("%d\n",n);
    }

    return 0;
}

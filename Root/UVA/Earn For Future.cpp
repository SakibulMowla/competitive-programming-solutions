#include "bits/stdc++.h"

int main()
{
    int t, n, i, j, b, test=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        b = 0;
        while(n--)
        {
            scanf("%d",&j);
            b = j > b ? j : b;
        }
        printf("Case %d: %d\n",++test,b);
    }

    return 0;
}

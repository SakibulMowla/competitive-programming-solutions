#include "bits/stdc++.h"
using namespace std;


int arr[4][4];




int main()
{
    int a, b, c, i, j, k, x, y, z;

    while(~scanf("%d %d %d",&a,&b,&c))
    {
        k = max(a, max(b, c));

        for(i=0;i<=k;i++)
        {
            x = i;
            z = b - x;
            y = c - z;
            if(z>-1 && y>-1 && (a == x+y) && (b == x+z) && (c == y+z))
            {
                printf("%d %d %d\n",x,z,y);
                return 0;
            }
        }


        printf("Impossible\n");

    }

    return 0;
}

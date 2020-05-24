#include <bits/stdc++.h>

using namespace  std;

int main()
{

    int n, m, i, j, zero, five;

    while(scanf("%d",&n) == 1)
    {
        five = zero = 0;

        for(i=0; i<n; i++)
        {
            scanf("%d",&j);
            if(j == 0) zero++;
            else five++;
        }

        if(!zero)
        {
            printf("-1\n");
            continue;
        }
        if(five < 9)
        {
            printf("0\n");
            continue;
        }

        j = 0;

        for(i=0; i<five; i++)
        {
            j = (j*10 + 5) % 9;
            if(j == 0)
                m = i+1;
        }

        for(j=0; j<m; j++)
            printf("5");
        for(j=0; j<zero; j++)
            printf("0");

        printf("\n");
    }


    return 0;
}


















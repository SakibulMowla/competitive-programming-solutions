#include "stdio.h"
#include "iostream"

using namespace std;

int arr[2010];

int main()
{
    int test=0, t, n, i, j, from, to, maxim;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);

        printf("Case %d:",++test);

        if(n < 11)
        {
            printf(" go home!\n");
            continue;
        }

        from = 0;
        to = n-11;

        for(i=0; i<11; i++)
        {
            maxim = -1e9;
            for(j=from; j<=to; j++)
            {
                if(arr[j] > maxim)
                {
                    maxim = arr[j];
                    from = j + 1;
                }
            }
            to++;
            printf(" %d",maxim);
        }

        printf("\n");
    }

    return 0;
}







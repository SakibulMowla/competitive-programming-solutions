#include "bits/stdc++.h"
using namespace std;

#define SZ 55

int arr1[SZ], arr2[SZ];
bool used1[SZ], used2[SZ];

int main()
{
    int test=0, t, i, j, k, now, f, l, n;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        k = 0;

        for(i=1; i<=n; i++)
            scanf("%d",&arr1[i]);

        for(i=1; i<=n; i++)
            scanf("%d",&arr2[i]);

        k = 0;
        memset(used1, 0, sizeof(used1));
        memset(used2, 0, sizeof(used2));
        sort(arr1+1, arr1+n+1);

        for(i=1; i<=n; i++)
        {
            now = -1;
            f = 0;
            for(j=1; j<=n; j++)
            {
                if(used2[j] || arr2[j] >= arr1[i]) continue;
                if(arr2[j] > now)
                {
                    now = arr2[j];
                    f = 1;
                    l = j;
                }
            }
            if(f)
            {
//                printf("i l = %d %d\n",i,l);
                k += 2;
                used1[i] = 1;
                used2[l] = 1;
            }
        }

        for(i=1;i<=n;i++)
        {
            if(used1[i]) continue;
            for(j=1;j<=n;j++)
            {
                if(used2[j]) continue;
                if(arr1[i] == arr2[j])
                {
//                    printf("i j %d %d\n",i,j);
                    k++;
                    used2[j] = 1;
                    break;
                }
            }
        }

        printf("Case %d: %d\n",++test,k);
    }

    return 0;
}

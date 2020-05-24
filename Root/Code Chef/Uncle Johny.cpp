#include <bits/stdc++.h>

using namespace  std;

#define SZ 110

int arr[SZ];


int main()
{
    int t, i, j, k, n;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        scanf("%d",&k);
        j = 1;
        k--;

        for(i=0;i<n;i++)
            if(arr[i] < arr[k])
                j++;

        printf("%d\n",j);
    }

    return 0;
}



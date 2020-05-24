#include "stdio.h"
#define SZ 100010

const int inf = 2e9;
int arr[SZ], I[SZ], seq_F[SZ], seq_R[SZ], n;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int LIS(int arr[], int seq[])
{
    int i, hi, lo, mid, lislen;

    I[0] = -inf;

    for(i=1; i<=n; i++)   I[i] = inf;

    lislen = 0;

    for(i=0; i<n; i++)
    {
        lo = 0;
        hi = lislen;

        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(I[mid] < arr[i])
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        I[lo] = arr[i];
        if(lislen < lo)
            lislen = lo;
        seq[i] = lislen;
    }

    return lislen;
}

int main()
{
    int i, t=0, test, ans;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&n);

        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);

        LIS(arr, seq_F);

        for(i=0; i<n/2; i++)
        {
            arr[i] = arr[i] ^ arr[n-i-1];
            arr[n-i-1] = arr[i] ^ arr[n-i-1];
            arr[i] = arr[i] ^ arr[n-i-1];
        }

        LIS(arr, seq_R);

        ans = 0;

        for(i=0; i<n; i++)
            ans = max(ans, min( seq_F[i], seq_R[n-i-1] )*2 - 1 );

        printf("Case %d: %d\n",++t, ans);
    }

    return 0;
}

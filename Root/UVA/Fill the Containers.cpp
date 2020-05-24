#include "stdio.h"
#include "stdbool.h"

#define SZ 1002


int arr[SZ];
int n, m;

bool chk(int cap)
{
    int i, j, k, sum;

    k = sum = 0;

    for(i=0;i<n;i++)
    {
        if(arr[i] > cap) return false;
        sum += arr[i];
        if(sum > cap)
        {
            sum = arr[i];
            k++;
            if(k > m)
                return false;
        }
    }

    k++;

    return (k<=m);
}

int main()
{
    int i, maxim, hi, lo, mid, ans;

    while(scanf("%d %d",&n,&m) == 2)
    {
        maxim = 0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i] > maxim)
                maxim = arr[i];
        }

        lo = maxim;
        hi = maxim * n;

        while(lo <= hi)
        {
            mid = (lo + hi) / 2;

            if(chk(mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        printf("%d\n",ans);
    }

    return 0;
}

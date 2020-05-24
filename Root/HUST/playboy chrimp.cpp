#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

long long arr[50500], p, n;

long long func(long long x)
{
    long long beg = 0, endd = n - 1, mid;
    while(beg < endd)
    {
        mid  = (beg + endd) / 2;
        if(arr[mid] == x)
            return mid;
        if(beg == endd)
        {
            p = 1;
            return beg;
        }
        if(arr[mid] < x)
            beg = mid + 1;
        else if(arr[mid] > x)
            endd = mid - 1;
    }
}

int main()
{
    long long i, q, a, b, x, cnt;
    scanf("%lld", &n);
    for(i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);
    scanf("%lld", &q);
    for(cnt = 0; cnt < q; ++cnt)
    {
        scanf("%lld", &x);
        a = func(x);
        p = 0;
        for(i = a; i >= 0; --i)
            if(arr[i] < x)
            {
                p = 1;
                printf("%lld ", arr[i]);
                break;
            }
        if(p == 0)
            printf("X ");
        p = 0;
        for(i = a; i < n; ++i)
            if(arr[i] > x)
            {
                p = 1;
                printf("%lld\n", arr[i]);
                break;
            }
        if(p == 0)
            printf("X\n");
    }
    return 0;
}

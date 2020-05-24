#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

#define SZ 100010

ll arr[SZ];

inline void read (ll &n)
{
    n = 0;
    int i = getchar_unlocked();

    while (i < '0' || i > '9')
        i = getchar_unlocked();

    while (i >= '0' && i <= '9')
    {
        n = (n << 3) + (n << 1) + i - '0';
        i = getchar_unlocked();
    }
}

int main()
{
    ll test=0, t, i, j, n, q, sum;

    read(t);

    while(t--)
    {
        sum = 0;
        read(n);
        read(q);
        for(i=0;i<n;i++)
        {
            read(arr[i]);
            sum += arr[i] * (n-i-1);
            sum -= arr[i] * i;
        }
        printf("Case %lld:\n",++test);
        while(q--)
        {
            read(i);
            if(i)
                printf("%lld\n",sum);
            else
            {
                read(i);
                read(j);
                sum -= arr[i] * (n-i-1);
                sum += arr[i] * i;
                arr[i] = j;
                sum += arr[i] * (n-i-1);
                sum -= arr[i] * i;
            }
        }
    }

    return 0;
}

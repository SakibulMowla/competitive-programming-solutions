using namespace std;

#include "stdio.h"
#include "iostream"
#define SZ 10010

typedef long long ll;
ll const inf = 1e15;
ll arr[SZ], maxim_f[SZ], minim_f[SZ], maxim_r[SZ], minim_r[SZ], n;

void max_min_front()
{
    ll i, sum_mx, sum_mn, maxim, minim;

    sum_mn = sum_mx = 0;
    maxim = -inf;
    minim = inf;

    for(i=1; i<=n; i++)
    {
        sum_mx += arr[i];
        sum_mx = max(sum_mx, arr[i]);
        sum_mn += arr[i];
        sum_mn = min(sum_mn, arr[i]);

        maxim_f[i] = maxim = max(sum_mx, maxim);
        minim_f[i] = minim = min(sum_mn, minim);
    }
}

void max_min_rev()
{
    ll i, sum_mx, sum_mn, maxim, minim;

    sum_mn = sum_mx = 0;
    maxim = -inf;
    minim = inf;

    for(i=n; i>=1; i--)
    {
        sum_mx += arr[i];
        sum_mx = max(sum_mx, arr[i]);
        sum_mn += arr[i];
        sum_mn = min(sum_mn, arr[i]);

        maxim_r[i] = maxim = max(sum_mx, maxim);
        minim_r[i] = minim = min(sum_mn, minim);
    }
}

int main()
{
    ll t, i, k, dif;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)   scanf("%lld",&arr[i]);
        max_min_front();
        max_min_rev();
        dif = -inf;
        for(i=1;i<n;i++)
        {
            k = maxim_f[i] - minim_r[i+1];
            if(k < 0) k = -k;
            if(dif < k) dif = k;
            k = minim_f[i] - maxim_r[i+1];
            if(k < 0) k = -k;
            if(dif < k) dif = k;
        }
        printf("%lld\n",dif);
    }

    return 0;
}

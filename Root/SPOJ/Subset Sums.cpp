#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define SZ 18

ll sum1[1<<SZ], sum2[1<<SZ];
ll arr1[SZ], arr2[SZ];

int main()
{
    ll n, a, b, num1, num2, k, l, r, j, i, tmp;

    while(scanf("%lld %lld %lld",&n,&a,&b) == 3)
    {
        num1 = n / 2;
        num2 = n - num1;

        for(i=0; i<num1; i++)
            scanf("%lld",&arr1[i]);

        for(i=0; i<num2; i++)
            scanf("%lld",&arr2[i]);

        k = 1<<num1;
        l = 0;

        for(i=0; i<k; i++)
        {
            tmp = 0;
            for(j=0; j<num1; j++)
                if(i&(1<<j))
                    tmp += arr1[j];

            sum1[l++] = tmp;
        }

        k = 1<<num2;
        r = 0;

        for(i=0; i<k; i++)
        {
            tmp = 0;
            for(j=0; j<num2; j++)
                if(i&(1<<j))
                    tmp += arr2[j];

            sum2[r++] = tmp;
        }

        sort(sum1, sum1+l);
        sort(sum2, sum2+r);

        tmp = 0;

//        printf("l r %lld %lld\n",l,r);

        for(i=0; i<l; i++)
            tmp += upper_bound(sum2, sum2+r, b-sum1[i]) - lower_bound(sum2, sum2+r, a-sum1[i]);

        printf("%lld\n",tmp);
    }

    return 0;
}

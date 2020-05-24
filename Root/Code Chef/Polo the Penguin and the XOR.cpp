#include "bits/stdc++.h"
using namespace std;
#define SZ1 40

typedef long long ll;

ll cnt[SZ1][2];

int main()
{
    ll t, n, i, j, k, sum;

    scanf("%lld",&t);

    while(t--)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%lld",&n);

        sum = 0LL;

        for(i=0; i<n; i++)
        {
            scanf("%lld",&k);

            for(j=0; j<32; j++)
            {
                if(k & (1LL<<j))
                {
                    swap(cnt[j][0], cnt[j][1]);
                    cnt[j][1]++;
                }
                else
                {
                    cnt[j][0]++;
                }

                sum += (1LL<<j) * cnt[j][1];
            }
        }

        printf("%lld\n",sum);
    }

    return 0;
}

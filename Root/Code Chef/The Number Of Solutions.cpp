#include <bits/stdc++.h>

using namespace  std;

#define mem(a,b) memset(a, b, sizeof(a))

typedef long long ll;

ll bigmod(ll a,ll b,ll m)
{
    if(b == 0) return 1%m;
    ll x = bigmod(a,b/2,m);
    x = (x * x) % m;
    if(b % 2 == 1) x = (x * a) % m;
    return x;
}

#define SZ 50
const ll inf = 1LL<<28;
const ll moduluss = 1000000007LL;

ll arr[SZ];

int main()
{
    ll n, t, upper, d, N, m, mval, mval1, i, j, k, answer;

    scanf("%lld",&t);

    while(t--)
    {
        mem(arr, 0);
        scanf("%lld %lld %lld %lld",&upper,&d,&m,&N);
        mval1 = upper / N;
        for(i=0; i<min(N, upper+1); i++)
        {
            mval = bigmod(i, d, N);
            arr[mval] += upper / N;
            if(mval1 * N + i <= upper)
                arr[mval]++;
        }

        answer = 0LL;

        for(i=0; i<N; i++) if(arr[i])
        for(j=0; j<N; j++) if(arr[j])
        for(k=0; k<N; k++) if(arr[k])
        {
            if( (i + j + k) % N == m)
                answer = (answer + ( ( (arr[i] * arr[j]) % moduluss ) * arr[k] ) % moduluss ) % moduluss;
        }

        printf("%lld\n",answer);
    }

    return 0;
}

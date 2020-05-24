using namespace std;
#include "bits/stdc++.h"
#define SZ 1000010

typedef long long ll;
const ll mod = 1000000007LL;

ll bigmod(ll b,ll p)
{
    if(p == 0) return 1;
    ll x = bigmod(b, p/2);
    x = (x * x)% mod;
    if(p%2) x = (b * x) % mod;
    return x;
}

bool arr[SZ];
vector <ll> prime;
ll val[SZ], ans;

void sieve()
{
    ll i, j, k;
    k = sqrt(SZ);
    for(i=3; i<k; i+=2)
        if(arr[i] == 0)
            for(j=i*i; j<SZ; j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(i=3; i<SZ; i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

ll mul(ll n)
{
    ll i, j, k;
    k = prime.size();
    for(i=0; i<k && n!= 1 && prime[i]*prime[i] <= n; i++)
    {
        if(n % prime[i] == 0)
        {
            j = 0;
            while(n % prime[i] == 0)
            {
                n /= prime[i];
                j++;
            }
            ans = (ans * bigmod(val[prime[i]], mod-2)) % mod;
            val[prime[i]] += j;
            ans = (ans * val[prime[i]]) % mod;
        }
    }
    if(n != 1)
    {
        ans = (ans * bigmod(val[n], mod-2)) % mod;
        val[n]++;
        ans = (ans * val[n]) % mod;
    }
    return ans;
}

ll div(ll n)
{
    ll i, j, k;
    k = prime.size();
    for(i=0; i<k && n!= 1 && prime[i]*prime[i] <= n; i++)
    {
        if(n % prime[i] == 0)
        {
            j = 0;
            while(n % prime[i] == 0)
            {
                n /= prime[i];
                j++;
            }
            ans = (ans * bigmod(val[prime[i]], mod-2)) % mod;
            val[prime[i]] -= j;
            ans = (ans * val[prime[i]]) % mod;
        }
    }
    if(n != 1)
    {
        ans = (ans * bigmod(val[n], mod-2)) % mod;
        val[n]--;
        ans = (ans * val[n]) % mod;
    }
    return ans;
}

int main()
{
    sieve();
    ll test=0, t, i, n, sum;

    scanf("%lld",&t);

    while(t--)
    {
        sum = 0LL;
        ans = 1LL;
        fill(val,val+1000005,1);
        scanf("%lld",&n);
        while(n--)
        {
            scanf("%lld",&i);
            if(i > 0)   sum = (sum + mul(i)) % mod;
            else    sum = (sum + div(-i)) % mod;
        }
        printf("Case %lld: %lld\n",++test,sum);
    }

    return 0;
}

#include "stdio.h"
typedef long long ll;

ll zeroes(ll n)
{
    ll ans = 0;
    while(n >= 5)
    {
        ans += n / 5;
        n /= 5;
    }
    return ans;
}

ll b_search(ll n)
{
    ll mid , begin = 5 , end = 500000010;
    ll p;
    while(begin <= end)
    {
        mid = (begin + end) / 2;
        p = zeroes(mid);
        if(p == n) return mid;
        else if(p > n) end = mid - 1;
        else begin = mid + 1;
    }

    return -1;
}

int main()
{
    ll i,k,n,t,test;
    t = 0;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        k = b_search(n);
        printf("Case %lld: ",++t);
        if(k == -1) printf("impossible\n");
        else
        {
            while(zeroes(k-1) == n) k--;
            printf("%lld\n",k);
        }
    }

    return 0;
}

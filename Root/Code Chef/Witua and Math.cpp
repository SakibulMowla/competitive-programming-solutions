using namespace std;

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "iostream"

typedef long long ll;

ll sample[] = {3 , 5 , 7 , 11 , 17 , 23 , 41 , 43 , 97 , 19 , 67 , 79}; // 12 nums

ll bigmod(ll B,ll P,ll M)
{
    ll R=1;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

bool check(ll n)
{
    ll i,a;

    for(i=0; i<10; i++)
    {
        a = rand() % (n-1);
        a++;
        if( bigmod(a , n-1 , n) != 1)
            return false;
    }

    return true;
}

ll find(ll n)
{
    if(n == 2LL) return 2LL;
    ll i;
    if(n % 2 == 0) n--;
    for(i=n ;; i-=2)
        if(check(i))
            return i;
}

int main()
{
    ll t,n;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",find(n));
    }

    return 0;
}

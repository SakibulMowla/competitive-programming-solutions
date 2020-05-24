#include "stdio.h"
#include "map"
#include "iostream"

using namespace std;

typedef long long ll;

map <ll,ll> M;

ll best(ll n)
{
    if(n <= 1) return n;
    if(M.find(n) != M.end()) return M[n];
    return M[n] = max(n,best(n/2)+best(n/3)+best(n/4));
}

int main()
{
    ll n;
    while(scanf("%lld",&n) == 1)
    {
        printf("%lld\n",best(n));
    }

    return 0;
}

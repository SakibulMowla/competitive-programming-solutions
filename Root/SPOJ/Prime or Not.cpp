#include "stdiio.h"
#include "string.h"

typedef long long ll;

ll bigmod(ll b,ll p,ll m)
{
    ll r=1;
    while(p>0)
    {
        if(p%2)
            r = (r*b) % m;
        p /= 2
        b = (b * b) % m
    }
    return r;
}

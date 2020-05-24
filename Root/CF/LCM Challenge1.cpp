#include "bits/stdc++.h"
using namespace std;

template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

int main()
{
    long long n;

    while(scanf("%I64d",&n) == 1)
    {
        if(n == 1)
            n = 1;
        else if(n == 2)
            n = 2;
        else if(n == 3)
            n = 6;
        else if(n == 4)
            n = 12;
        else
        {
            if(n&1)
                n = n * (n-1) * (n-2);
            else
                n = max((n-1) * (n-2) * (n-3), lcm((n-3), n) * (n-1)) ;
        }

        printf("%I64d\n",n);
    }

    return 0;
}
